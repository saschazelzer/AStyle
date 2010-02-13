#! /usr/bin/python
# Run the AStyle regression test.
# Tests the output of a new program against an older one.
# Change the global variables to the desired values.
# Variables astyleexe1 & 2 should be an old and new version of the program.
# Changes will cause files in the second run to be formatted.
# The differences can be checked with a diff program.

import libastyle		#local directory
import libextract		#local directory
import libtest			#local directory
import os
import subprocess
import sys
import time

# global variables ------------------------------------------------------------

# select one of the following from libastyle
#   CODEBLOCKS
#   CODELITE
#   JEDIT
#   KDEVELOP
#  SHARPDEVELOP
# TEST
project = libastyle.CODEBLOCKS

# select one of the following
#options = ""
# indent-brackets (B), add-brackets (j), break-blocks=all (F), align-pointer=type (k1)
#options = "-CSKBNLwM50m10yejoOcFpPHUxEk1"
# indent-blocks (G), add-one-line-brackets (J), break-blocks (f), align-pointer=middle (k2)
options = "-CSKGNLwM50m10yeJoOcfpPHUxEk2"

# executables for test
astyleexe1 = "astyle25a"
astyleexe2 = "astyled"

# select one of the following to unarchive files
extractfiles = True
#extractfiles = False

# -----------------------------------------------------------------------------

def process_files():
	"""Main processing function.
	"""
	# initialization
	starttime = time.time()
	libastyle.set_text_color()
	print "Testing " +  project
	print
	os.chdir(libastyle.get_file_py_directory())
	libastyle.build_astyle_executable(get_astyle_config())
	verify_astyle_executables(astyleexe1, astyleexe2)
	filepaths = libastyle.get_project_filepaths(project)
	testfile = "test.txt"
	if extractfiles:
		print "Extracting files"
		libextract.extract_project(project)

	# run test 1
	print_test_header(1, astyleexe1)
	astyle = set_astyle_args(filepaths, astyleexe1)
	print_formatting_message(astyle, project)
	call_artistic_style(astyle, testfile)
	print_astyle_totals(testfile)
	# os.remove(testfile)

	# run test 2
	print_test_header(2, astyleexe2)
	astyle = set_astyle_args(filepaths, astyleexe2)
	print_formatting_message(astyle, project)
	call_artistic_style(astyle, testfile)
	totformat, totfiles = print_astyle_totals(testfile)
	files = libtest.get_formatted_files(testfile)
	verify_formatted_files(len(files), totformat)

	# process formatted files
	print_run_total(totformat, totfiles, starttime)
	libtest.diff_formatted_files(files, totformat)

# -----------------------------------------------------------------------------

def call_artistic_style(astyle, testfile):
	"""Call artistic style.
	"""
	outfile = open(testfile, 'w')
	try:
		subprocess.check_call(astyle, stdout=outfile)
	except subprocess.CalledProcessError as e:
		libastyle.system_exit("Bad astyle return: " + str(e.returncode))
	except OSError:
		libastyle.system_exit("Cannot find executable: " + astyle[0])
	outfile.close()

# -----------------------------------------------------------------------------

def get_astyle_config():
	"""Get the build configuration from the executalbe name.
	"""
	config = libastyle.DEBUG
	if (astyleexe1.lower() == "astyle"
	or astyleexe2.lower() == "astyle"):
		config = libastyle.RELEASE
	return config

# -----------------------------------------------------------------------------

def get_astyle_path(astyleexe):
	"""Get the astyle executable path.
	"""
	config = get_astyle_config()
	astylepath = libastyle.get_astyleexe_directory(config, True) + astyleexe
	return astylepath

# -----------------------------------------------------------------------------

def print_astyle_totals(filename):
	"""Print total information from the astyle total line.
	   Returns files formatted and total files from the report total line.
	"""
	formatted, unchanged, min, sec = libtest.get_astyle_totals(filename)
	totfiles = formatted + unchanged
	if min == 0:
		printline = "{0} formatted, {1} files, {2} seconds"
		print printline.format(formatted, totfiles, sec)
	else:
		printline = "{0} formatted, {1} files, {2} min {3} seconds"
		print printline.format(formatted, totfiles, min, sec)
	return (formatted, totfiles)

# -----------------------------------------------------------------------------

def print_formatting_message(args, project):
	"""Print the formatting message at the start of a test.
	   Input is the command list used to call astyle.
	"""
	print "Formatting " +  project,
	# print args starting with a '-'
	for arg in args:
		if arg[0] == '-':
			print arg,
	print

# -----------------------------------------------------------------------------

def print_run_total(formatted, totfiles, starttime):
	"""Print total information for the entire run.
	"""
	print
	stoptime = time.time()
	runtime = int(stoptime - starttime + 0.5)
	min = runtime / 60
	sec = runtime % 60
	if min == 0:
		print "{0} seconds total".format(sec)
	else:
		print "{0} min {1} seconds total".format(min, sec)
	# if formatted == 0: libastyle.set_ok_color()
	# else: libastyle.set_error_color()
	print
	print "{0} diffs in {1} files".format(formatted, totfiles)
	print

# -----------------------------------------------------------------------------

def print_test_header(testnum, astyleexe):
	"""Print header information for a test.
	"""
	print
	print "TEST {0} with {1}".format(testnum, astyleexe)

# -----------------------------------------------------------------------------

def set_astyle_args(filepath, astyleexe):
	"""Set args for calling artistic style.
	"""
	astylepath = get_astyle_path(astyleexe)
	args = [astylepath]
	# set filepaths
	for file in filepath:
		args.append(file)
	# set options
	if len(options.strip()) > 0:
		args.append(options)
	args.append("-vRQ")
	return args

# -----------------------------------------------------------------------------

def verify_astyle_executables(exe1, exe2):
	"""Verify that the astyle test executables are available.
	"""
	exe1path = get_astyle_path(exe1)
	if (os.name == "nt"
	and not exe1path.endswith(".exe")):
			exe1path += ".exe"
	if not os.path.exists(exe1path):
		libastyle.system_exit("Cannot find executable: " + exe1path)
	exe2path = get_astyle_path(exe2)
	if (os.name == "nt"
	and not exe2path.endswith(".exe")):
		exe2path += ".exe"
	if not os.path.exists(exe2path):
		libastyle.system_exit("Cannot find executable: " + exe2path)

# -----------------------------------------------------------------------------

def verify_formatted_files(numformat, totformat):
	"""Check that the formatted files list equals the astyle report total.
	"""
	if totformat != numformat:
		message = "files != report ({0},{1})".format(numformat, totformat)
		libastyle.system_exit(message)

# -----------------------------------------------------------------------------

# make the module executable
if __name__ == "__main__":
	process_files()
	libastyle.system_exit()

# -----------------------------------------------------------------------------
