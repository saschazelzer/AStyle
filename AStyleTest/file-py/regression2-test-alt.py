#! /usr/bin/python
# Run the AStyle regression test.
# Tests the output of a new program against an older one.
# Change the global variables to the desired values.
# Variables astyleexe1 & 2 should be an old and new version of the program.
# Compares diffs in old and new files.
# The differences can be checked with a diff program.

import libastyle		# local directory
import libextract		# local directory
import libtest			# local directory
import locale
import glob
import os
import shutil
import subprocess
import sys
import time

# global variables ------------------------------------------------------------

# enter the following
# JBoss.org ***********************************
archive = "Greenfoot-source-1.5.6.zip"
project = "Greenfoot-source-1.5.6"		# primary directory in archive
source = [ "*.java" ]					# extensions to format

# select OPT0 thru OPT3, or use customized options
options = libastyle.OPT1

# scite formatting options
#options = "-tapOHUk3"

# executables for test
astyleexe1 = "astyle25b"
astyleexe2 = "astyle"

# select one of the following to format files in the OLD directory
formatOLD = True
#formatOLD = False

# -----------------------------------------------------------------------------

# ProjectsTested
#
# FileZilla			C++
# Greenfoot			**Java
# Notepad++			C++
# SportsTracker		Java
# TestDisk			C

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
	filepaths = get_file_paths()
	excludes = []
	testfile = "test.txt"
	# run test 1
	if formatOLD:
		print "\nExtracting Test 1"
		extract_project()
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
	extract_project()
	print_test_header(2, astyleexe2)
	astyle = set_astyle_args(filepaths, excludes, astyleexe2)
	print_formatting_message(astyle, project)
	call_artistic_style(astyle, testfile)
	print_astyle_totals(testfile)

	# process formatted files
	diffs = compare_formatted_files(filepaths, len(excludes))
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

def compare_formatted_files(filepaths, numExcludes):
	"""Walk thru the top-level directory tree
	   and diff the files in the current and OLD directories.
	   Returns a list of the files with a diff.
	"""
	# process the filepaths
	totfiles = 0
	totdiffs = 0
	diffs = []
	print
	if numExcludes > 0:
		print "Compare includes excluded files"
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
			# Linux needs to be sorted to compare to Windows
			dirnames.sort()			# (key=str.lower) for case insensitive
			filenames .sort()
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
		# print a total for each filepath
		print "{0} files  {1} diffs".format(totfiles, totdiffs)
	fcout.close()
	# files may not be removed due to an active process from a previous run
	try:
		os.remove(fcfile)
	except WindowsError as e:
		print e		# print error and continue
	testout.close()
	return diffs

# -----------------------------------------------------------------------------

def extract_project():
	"""Extract files from archive to test directory.
	"""
	tarfile, ext = os.path.splitext(archive)
	print tarfile
	if ext == ".bz2":
		extract_test_tar(tarfile)
	if ext == ".zip" or ext == ".7z":
		extract_test_zip(tarfile)
	
# -----------------------------------------------------------------------------

def extract_test_tar(tarfile):
	"""Extract tar files from archive to test directory.
	"""
	libextract.remove_test_directory(project)
	libextract.extract_test_tar(archive, tarfile, source)

# -----------------------------------------------------------------------------

def extract_test_zip(tarfile):
	"""Extract zip files, including 7-zip, from archive to test directory.
	"""
	libextract.remove_test_directory(project)
	libextract.extract_test_zip(archive, tarfile, source)

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

def get_file_paths():
	"""Build filepaths variable from globals.
	"""
	filepaths = []
	for wildcard in source:
		filepaths.append(libastyle.get_test_directory(True) 
		                 + project + '/' +wildcard)
	return filepaths

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
				astyleexe1, astyleexe2)
	else:
		print "Using {0} {1}".format(astyleexe1, astyleexe2)

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
	regress1path = libastyle.get_astyle_directory() + "/regress/" + astyleexe1
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
	# verify exe2
	if not os.path.exists(exe2path):
		libastyle.system_exit("Cannot find executable 2: " + exe2path)

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
