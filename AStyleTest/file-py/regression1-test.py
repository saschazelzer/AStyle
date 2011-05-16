#! /usr/bin/python
# Run the AStyle regression test.
# Tests the output of a new program against an older one.
# Change the global variables to the desired values.
# Variables astyleexe1 & 2 should be an old and new version of the program.
# Changes will cause files in the second run to be formatted.
# The differences can be checked with a diff program.

import libastyle		# local directory
import libextract		# local directory
import libtest			# local directory
import locale
import os
import shutil
import subprocess
import sys
import time

# global variables ------------------------------------------------------------

# select one of the following from libastyle
#   CODEBLOCKS
#   DRJAVA
#   JEDIT
#   KDEVELOP
#   MONODEVELOP
#  SCITE
#  SHARPDEVELOP
# TESTPROJECT
project = libastyle.CODEBLOCKS

# select OPT0 thru OPT3, or use customized options
# optionsX can be a bracket style or any other option
options = libastyle.OPT0
optionsX = ""

# executables for test
astyleexe1 = "astyle2n"
astyleexe2 = "astyled"

# extract all files options, use False for speed
#all_files_option = True
all_files_option = False

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
	locale.setlocale(locale.LC_ALL, "")
	print_run_header()
	os.chdir(libastyle.get_file_py_directory())
	libastyle.build_astyle_executable(get_astyle_config())
	verify_astyle_executables(astyleexe1, astyleexe2)
	filepaths = libastyle.get_project_filepaths(project)
	excludes = libastyle.get_project_excludes(project)
	testfile = "test.txt"
	if extractfiles:
		print "\nExtracting files"
		libextract.extract_project(project, all_files_option)

	# run test 1
	print_test_header(1, astyleexe1)
	astyle = set_astyle_args(filepaths, excludes, astyleexe1)
	print_formatting_message(astyle, project)
	call_artistic_style(astyle, testfile)
	print_astyle_totals(testfile)

	# run test 2
	print_test_header(2, astyleexe2)
	astyle = set_astyle_args(filepaths, excludes, astyleexe2)
	print_formatting_message(astyle, project)
	call_artistic_style(astyle, testfile)
	totformat, totfiles = print_astyle_totals(testfile)
	files = libtest.get_formatted_files(testfile)
	verify_formatted_files(len(files), totformat)

	# process formatted files
	print_run_total(starttime)
	libtest.diff_formatted_files(files)

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
	# the native locale should be set to get the numeric formatting
	formatted, totfiles, min, sec = libtest.get_astyle_totals(filename)
	if min == 0:
		printline = "{0:n} formatted; {1:n} files; {2} seconds"
		print printline.format(formatted, totfiles, sec)
	else:
		printline = "{0:n} formatted; {1:n} files; {2} min {3} seconds"
		print printline.format(formatted, totfiles, min, sec)
	return (formatted, totfiles)

# -----------------------------------------------------------------------------

def print_formatting_message(args, project):
	"""Print the formatting message at the start of a test.
	   Input is the command list used to call astyle.
	"""
	print "Formatting " +  project,
	# print args starting with a '-' except for excludes
	for arg in args:
		if not arg[0] == '-': continue
		if arg[:9] == "--exclude": continue
		print arg,
	print

# -----------------------------------------------------------------------------

def print_run_header():
	"""Print run header information.
	"""
	print "Testing {0}".format(project)
	if os.name == "nt":
		print "Using ({0}) {1} {2}".format(libastyle.VS_RELEASE,
				astyleexe1, astyleexe2),
	else:
		print "Using {0} {1}".format(astyleexe1, astyleexe2),
	if options == libastyle.OPT0:
		print "OPT0",
	elif options == libastyle.OPT1:
		print "OPT1",
	elif options == libastyle.OPT2:
		print "OPT2",
	elif options == libastyle.OPT3:
		print "OPT3",
	else:
		print options,
	if len(optionsX.strip()) > 0:
		print optionsX,
	print

# -----------------------------------------------------------------------------

def print_run_total(starttime):
	"""Print total information for the entire run.
	"""
	print
	stoptime = time.time()
	runtime = int(stoptime - starttime + 0.5)
	min = runtime / 60
	sec = runtime % 60
	if min == 0:
		print "{0} seconds total run time".format(sec)
	else:
		print "{0} min {1} seconds total run time".format(min, sec)
	print

# -----------------------------------------------------------------------------

def print_test_header(testnum, astyleexe):
	"""Print header information for a test.
	"""
	print
	print "TEST {0} with {1}".format(testnum, astyleexe)

# -----------------------------------------------------------------------------

def set_astyle_args(filepath, excludes, astyleexe):
	"""Set args for calling artistic style.
	"""
	astylepath = get_astyle_path(astyleexe)
	args = [astylepath]
	# set filepaths
	for file in filepath:
		args.append(file)
	# set options
	args.append("-vRQ")
	if len(options.strip()) > 0:
		args.append(options)
	if len(optionsX.strip()) > 0:
		if optionsX[0] != '-':
			libastyle.system_exit("optionsX must begin with a '-'")
		args.append(optionsX)
	# set excludes
	for exclude in excludes:
		args.append(exclude)
	return args

# -----------------------------------------------------------------------------

def verify_astyle_executables(exe1, exe2):
	"""Verify that the astyle test executables are available.
	"""
	# get paths
	exe1path = get_astyle_path(exe1)
	exe2path = get_astyle_path(exe2)
	regress1path = libastyle.get_astyle_directory() + "/regress/" + exe1
	# add "exe" extension
	if os.name == "nt":
		if not exe1path.endswith(".exe"):
			exe1path += ".exe"
		if not exe2path.endswith(".exe"):
			exe2path += ".exe"
		if not regress1path.endswith(".exe"):
			regress1path += ".exe"
	# verify exe1
	if not os.path.exists(exe1path):
		# try to copy exe1 from the "regress" directory
		if os.path.exists(regress1path):
			print "Copying " + exe1
			shutil.copy(regress1path, exe1path)
		else:
			libastyle.system_exit("Cannot find executable 1: " + exe1path)
	# check exe1 for most current by bumping the ending letter by 1
	if not verify_current_exe1(regress1path):
		libastyle.system_exit("Executable 1 is not current: " + regress1path)
	# verify exe2
	if not os.path.exists(exe2path):
		libastyle.system_exit("Cannot find executable 2: " + exe2path)

# -----------------------------------------------------------------------------

def verify_current_exe1(regress1path):
	"""Check that the requested exe1 is the most current version.
	"""
	# check exe1 for most current by bumping the ending letter by 1
	alphas = "abcdefghijklmnopqrstuvwxyz"
	if os.name == "nt":
		if regress1path[-5].isdigit():	# for first file from last release (AStyle1.exe)
			return True
		index = alphas.find(regress1path[-5])
		if index == -1:
			libastyle.system_exit("Bad index for alpha: " + index)
		test1path = regress1path[:-5] + alphas[index+1] + regress1path[-5+1:]
	else:
		if regress1path[-1].isdigit():	# for first file from last release (astyle1)
			return True
		index = alphas.find(regress1path[-1])
		if index == -1:
			libastyle.system_exit("Bad index for alpha: " + index)
		test1path = regress1path[:-1] + alphas[index+1]
	# is NOT most current if the next version exista
	if os.path.exists(test1path):
		return False
	return True

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
