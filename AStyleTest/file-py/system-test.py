#! /usr/bin/python
# Run the AStyle system test.
# Tests every possible combination of bracket changes.
# Change the global variables to the desired values.
# Run each bracket type twice to verify there are no changes.
# Run brackets=none after each new bracket type to verify
#     there are no changes and to check for consistency.
# Files with undesired changes will be copied to a Test directory
#     where they can be checked with a diff program.

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
#  CODEBLOCKS
#  CODELITE
#  DRJAVA			# cannot compile
#  JEDIT
#  KDEVELOP			# cannot compile
#  MONODEVELOP		# can compile on Linux only
#  SCITE
#  SHARPDEVELOP
#  TESTPROJECT
project = libastyle.JEDIT

# select OPT0 thru OPT3, or use customized options
#options = "-tapO"
options = libastyle.OPT3

# executable for test
astyleexe = "astyle"

# extract all files option, use False for speed, use True to compile
#all_files_option = True
all_files_option = False

# test number to start with (usually 1)
start = 1

# select one of the following to unarchive files
extractfiles = True
#extractfiles = False

# -----------------------------------------------------------------------------

def process_files():
	"""Main processing function.
	"""
	# bracket options and the order they are tested
	brackets = "__aa_bb_ll_gg_aa_ll_bb_gg_bb_aa_gg_ll_aa_"
	# total files formatted in error
	errors = 0
	errtests = []

	#initialization
	starttime = time.time()
	libastyle.set_text_color()
	locale.setlocale(locale.LC_ALL, "")
	print_run_header()
	os.chdir(libastyle.get_file_py_directory())
	filepaths = libastyle.get_project_filepaths(project)
	excludes = libastyle.get_project_excludes(project)
	index = set_test_start(brackets)
	libastyle.build_astyle_executable(get_astyle_config())
	if extractfiles:
		print "\nExtracting files"
		libextract.extract_project(project, all_files_option)

	# process the bracket options
	while index < len(brackets):
		print_test_header(brackets, index)
		testfile = get_test_file_name(index)
		astyle = set_astyle_args(filepaths, excludes, brackets, index)
		print_formatting_message(astyle, project)
		call_artistic_style(astyle, testfile)
		totformat, totfiles = print_astyle_totals(testfile)
		files = check_formatted_files(testfile, brackets, index)
		if len(files) > 0:
			errors += totformat
			errtests.append( get_test_directory_name(index)) 
			copy_formatted_files(files, testfile, index)
			verify_formatted_files(len(files), totformat)
		os.remove(testfile)
		index += 1

	print_run_total(errors, errtests, starttime)

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

def check_formatted_files(testfile, brackets, index):
	"""Check the output for files that were formatted.
	   Return is the number of files formatted.
	"""
	# check for conditions that are not errors
	if index == 0:
		return []
	if (brackets[index] != brackets[index - 1]
	and brackets[index] != '_'):
		return []
	# get formatted files from the astyle report
	files = libtest.get_formatted_files(testfile)
	return files

# -----------------------------------------------------------------------------

def copy_formatted_files(files, testfile, index):
	"""Copy formatted files to a test directory.
	"""
	testdir = get_test_directory_name(index)
	if os.path.exists(testdir):
		shutil.rmtree(testdir)
	os.mkdir(testdir)
	shutil.copy (testfile, testdir)
	for file in files:
		print "copying " + strip_directory_prefix(file)
		shutil.copy(file, testdir)
		shutil.copy(file + ".orig", testdir)

# -----------------------------------------------------------------------------

def get_astyle_config():
	"""Get the build configuration from the executalbe name.
	"""
	config = libastyle.DEBUG
	if astyleexe.lower() == "astyle":
		config = libastyle.RELEASE
	return config

# -----------------------------------------------------------------------------

def get_test_directory_name(index):
	"""Get name of the test directory for the given index.
	"""
	return 	"test{0}" .format(index+1)

# -----------------------------------------------------------------------------

def print_astyle_totals(filename):
	"""Print total information from the astyle total line.
	   Returns files formatted and total files from the report total line.
	"""
	formatted, totfiles, min, sec = libtest.get_astyle_totals(filename)
	if min == 0:
		printline = "{0:n} formatted; {1:n} files; {2} seconds"
		print printline.format(formatted, totfiles, sec)
	else:
		printline = "{0:n} formatted; {1:n} files; {2} min {3} seconds"
		print printline.format(formatted, totfiles, min, sec)
	return (formatted, totfiles)

# -----------------------------------------------------------------------------

def get_test_file_name(index):
	"""Get name of the test file for the given index.
	"""
	return 	"test{0}.txt".format(index+1)

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
		print "Using ({0}) {1}".format(libastyle.VS_RELEASE, astyleexe),
	else:
		print "Using {0}".format(astyleexe),
	if options == libastyle.OPT0:
		print "OPT0" 
	elif options == libastyle.OPT1:
		print "OPT1" 
	elif options == libastyle.OPT2:
		print "OPT2"
	elif options == libastyle.OPT3:
		print "OPT3" 
	else:
		print options
		
# -----------------------------------------------------------------------------

def print_run_total(errors, errtests, starttime):
	"""Print total information for the entire run.
	"""
	print
	print '-' * 60
	stoptime = time.time()
	runtime = int(stoptime - starttime + 0.5)
	min = runtime / 60
	sec = runtime % 60
	if min == 0:
		print "{0} seconds total run time".format(sec)
	else:
		print "{0} min {1} seconds total run time".format(min, sec)
	if errors == 0:
		print str(errors) + " errors"
	else:
		libastyle.set_error_color()
		print str(errors) + " errors in",
		for test in errtests:
			print test,
		print

# -----------------------------------------------------------------------------

def print_test_header(brackets, index):
	"""Print header information for a test.
	"""
	testNo = index + 1
	print '\n' + ('-' * 60) + '\n'
	print "TEST {0} OF {1}".format(testNo, len(brackets))
	print brackets[:testNo]
	print brackets

# -----------------------------------------------------------------------------

def remove_test_directories(brackets, index):
	"""Remove test directories for this run.
	"""
	for i in range(index, len(brackets)):
		testdir = get_test_directory_name(i)
		if os.path.exists(testdir):
			shutil.rmtree(testdir)

# -----------------------------------------------------------------------------

def set_astyle_args(filepath, excludes, brackets, index):
	"""Set args for calling artistic style.
	"""
	# set astyle executable
	args = [libastyle.get_astyleexe_path(get_astyle_config())]
	# set filepaths
	for file in filepath:
		args.append(file)
	# set options
	if len(options) > 0:
		args.append(options)
	args.append("-vRQ")
	if brackets[index] != '_':
		args.append('-' + brackets[index])
	# set excludes
	for exclude in excludes:
		args.append(exclude)
	return args

# -----------------------------------------------------------------------------

def set_test_start(brackets):
	"""Set the test number for start.
	   Returns the starting index.
	"""
	if start <= 1:
		index = 0
	else:
		index = start - 1
	if index > 0:
		print "Start with test {0}".format(index+1)
		# if needed decrease by one test
		if brackets[index] == brackets[index-1]:
			index -= 1
			print "Starting with test {0} to avoid diffs".format(index+1)
		elif brackets[index] == '_':
			if index >= 2:
				index -= 2
			else:
				index -= 1
			print "Starting with test {0} to apply format".format(index+1)
	remove_test_directories(brackets, index)
	return index

# -----------------------------------------------------------------------------

def strip_directory_prefix(directory):
	"""Strip the prefix from a directory or file for printing.
	"""
	prefix = libastyle.get_test_directory(True)
	start = len(prefix)
	if start > len(directory): start = 0
	return directory[start:]

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
