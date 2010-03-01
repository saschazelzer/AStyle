#! /usr/bin/python
# Run the AStyle regression test.
# Tests the output of a new program against an older one.
# Change the global variables to the desired values.
# Variables astyleexe1 & 2 should be an old and new version of the program.
# Compares diffs in old and new files.
# The differences can be checked with a diff program.

import libastyle		#local directory
import libextract		#local directory
import libtest			#local directory
import glob
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
#  SCITE 
#  SHARPDEVELOP
#  TESTPROJECT
project = libastyle.SCITE 

# select OPT1 thru OPT4, or use customized options
#options = libastyle.OPT1

# scite formatting options
options = "-tapOHUk3"

# executables for test
astyleexe1 = "astyle25a"
astyleexe2 = "astyled"

# select one of the following to format files in the OLD directory
formatOLD = True
#formatOLD = False

# -----------------------------------------------------------------------------

def process_files():
	"""Main processing function.
	"""
	# initialization
	starttime = time.time()
	libastyle.set_text_color()
	print "Testing " +  project
	print "Using {0} {1}".format(astyleexe1, astyleexe2) 
	os.chdir(libastyle.get_file_py_directory())
	libastyle.build_astyle_executable(get_astyle_config())
	verify_astyle_executables(astyleexe1, astyleexe2)
	filepaths = libastyle.get_project_filepaths(project)
	excludes = libastyle.get_project_excludes(project)
	testfile = "test.txt"
	# run test 1
	if formatOLD:
		print "\nExtracting Test 1"
		libextract.extract_project(project)
		print_test_header(1, astyleexe1)
		astyle = set_astyle_args(filepaths, excludes, astyleexe1)
		print_formatting_message(astyle, project)
		call_artistic_style(astyle, testfile)
		print_astyle_totals(testfile)
		libextract.remove_test_directory(project + "OLD")
		libextract.rename_test_directory(project, project + "OLD")
	else:
		verify_test_directory(project + "OLD")
		print "No Test 1"

	# run test 2
	print "\nExtracting Test 2"
	libextract.extract_project(project)
	print_test_header(2, astyleexe2)
	astyle = set_astyle_args(filepaths, excludes, astyleexe2)
	print_formatting_message(astyle, project)
	call_artistic_style(astyle, testfile)
	print_astyle_totals(testfile)

	# process formatted files
	diffs = compare_formatted_files(filepaths)
	print_run_total(starttime)
	libtest.diff_formatted_files(diffs, True)

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

def call_file_compare_program(filepath, testout, fcout):
	"""Call the file compare program for a given filepath.
	   Write files with a diff to to testout.
	"""
	oldpath = libtest.get_old_filepath(filepath)
	# call file compare
	fclist = get_file_compare_list(filepath, oldpath)
	retval = subprocess.call(fclist, stdout=fcout)
	if retval > 1:
		libastyle.system_exit("Bad file compare return: " + str(retval))
	if retval == 1:
		testout.write(filepath + '\n')
		return True
	return False

# -----------------------------------------------------------------------------

def compare_formatted_files(filepaths):
	"""Walk thru the top-level directory tree
	   and diff the files in the current and OLD directories.
	   Returns a list of the files with a diff.
	"""
	# process the filepaths
	totfiles = 0
	totdiffs = 0
	diffs = []
	print
	fcfile = libastyle.get_temp_directory() + "/filecompare.txt"
	fcout = open(fcfile, 'w')
	testfile = "test-diff.txt"
	testout = open(testfile, 'w')
	for filepath in filepaths:
		testdir = libastyle.get_test_directory(True)
		print "Compare " + filepath[len(testdir):]
		dirname, tail = os.path.split(filepath)
		pathroot, pathext = os.path.splitext(filepath)
		# walk thru the directory tree
		for dirpath, dirnames, filenames in os.walk(dirname):
			# process each file in the directory
			for filename in filenames:
				root, ext = os.path.splitext(filename)
				# compare only for the file extension requested
				if ext == pathext:
					totfiles += 1
					filepath = os.path.join(dirpath, filename)
					filepath = filepath.replace('\\', '/')
					retval = call_file_compare_program(filepath, testout, fcout)
					if retval:
						diffs.append(filepath)
						totdiffs += 1
					if totfiles % 100 == 0:
						print "{0} files  {1} diffs".format(totfiles, totdiffs)
	print "{0} files  {1} diffs".format(totfiles, totdiffs)
	fcout.close()
	os.remove(fcfile)
	testout.close()
	return diffs

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

def get_file_compare_list(filepath, oldpath):
	"""Get the file compare call list for the os environment
	"""
	if os.name == "nt":
		filepath = filepath.replace('/', '\\')
		oldpath = oldpath.replace('/', '\\')
		fclist = ["fc", "/lb1", "/t", filepath, oldpath]
	else:
		fclist = ["diff", "-q", "-a", filepath, oldpath]
	return fclist

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
	# print args starting with a '-' except for excludes
	for arg in args:
		if not arg[0] == '-': continue
		if arg[:9] == "--exclude": continue
		print arg,
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
	if len(options.strip()) > 0:
		args.append(options)
	args.append("-vRQ")
	# set excludes
	for exclude in excludes:
		args.append(exclude)
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

def verify_test_directory(name):
	"""Verify that a directory exists in the TestData directory.
	"""
	testdir = libastyle.get_test_directory(True) + name
	dirs = glob.glob(testdir)
	if len(dirs) == 0:
		msg = ("No test directory " + name +
			   ", must use formatOLD = True")
		libastyle.system_exit(msg)

# -----------------------------------------------------------------------------

# make the module executable
if __name__ == "__main__":
	process_files()
	libastyle.system_exit()

# -----------------------------------------------------------------------------
