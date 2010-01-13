#! /usr/bin/python
# Run the AStyle system test.
# Tests every possible combination of bracket changes.
# Change the global variables to the desired values.
# Run each bracket type twice to verify there are no changes.
# Run brackets=none after each new bracket type to verify
#     there are no changes and to check for consistency.
# Files with undesired changes will be copied to a Test directory
#     where they can be checked with a diff program.

import libastyle		#local directory
import libextract		#local directory
import libtest			#local directory
import os
import shutil
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
project = libastyle.TEST

# select one of the following
# options = ""
# indent-brackets (B), add-brackets (j), break-blocks=all (F), align-pointer=type (k1)
# options = "-CSKBNLwM50m10yejoOcFpPHUxEk1"
# indent-blocks (G), add-one-line-brackets (J), break-blocks (f), align-pointer=middle (k2)
options = "-CSKGNLwM50m10yeJoOcfpPHUxEk2"

# test number to start with (usually 1)
start = 1

# select one of the following to unarchive files
extractfiles = True
#extractfiles = False

# -----------------------------------------------------------------------------

def process_files():
	"""Main processing function."""

	# bracket options and the order they are tested
	brackets = "__aa_bb_ll_gg_aa_ll_bb_gg_bb_aa_gg_ll_aa_"
	# total files formatted in error
	errors = 0
	errtests = []

	#initialization
	starttime = time.time()
	libastyle.set_text_color()
	print "Testing " +  libastyle.get_project_name(project)
	os.chdir(libastyle.get_file_py_directory())
	filepaths = libastyle.get_project_filepaths(project)
	index = set_test_start(brackets)
	libastyle.build_astyle_executable()
	if extractfiles:
		print "Extracting files"
		libextract.extract_project(project)

	# process the bracket options
	while index < len(brackets):
		print_test_header(brackets, index)
		testfile = get_test_file_name(index)
		astyle = set_astyle_args(filepaths, brackets, index)
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
		system_exit("Bad astyle return: " + str(e.returncode))
	except OSError:
		system_exit("Cannot find executable: " + astyle[0])
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

def get_test_directory_name(index):
	"""Get name of the test directory for the given index.
	"""
	return 	"test{0}" .format(index+1)

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

def get_test_file_name(index):
	"""Get name of the test file for the given index.
	"""
	return 	"test{0}.txt".format(index+1)

# -----------------------------------------------------------------------------

def print_formatting_message(args, project):
	"""Print the formatting message at the start of a test.
	   Input is the command list used to call astyle.
	"""
	print "Formatting " +  libastyle.get_project_name(project),
	# print args starting with a '-'
	for arg in args:
		if arg[0] == '-':
			print arg,
	print

# -----------------------------------------------------------------------------

def print_run_total(errors, errtests, starttime):
	"""Print total information for the entire run.
	"""
	print
	print "-----------------------------------------"
	if errors == 0: libastyle.set_ok_color()
	else: libastyle.set_error_color()
	if errors == 0:
		print str(errors) + " errors"
	else:
		print str(errors) + " errors in",
		for test in errtests:
			print test,
		print
	stoptime = time.time()
	runtime = int(stoptime - starttime + 0.5)
	min = runtime / 60
	sec = runtime % 60
	if min == 0:
		print "{0} seconds".format(sec)
	else:
		print "{0} min {1} seconds".format(min, sec)

# -----------------------------------------------------------------------------

def print_test_header(brackets, i):
	"""Print header information for a test.
	"""
	print "\n-----------------------------------------\n"
	print "TEST {0} OF {1}".format(i+1, len(brackets))
	print brackets
	print brackets[:i+1]

# -----------------------------------------------------------------------------

def remove_test_directories(brackets, index):
	"""Remove test directories for this run.
	"""
	i = index
	while i < len(brackets):
		testdir = get_test_directory_name(i)
		if os.path.exists(testdir):
			shutil.rmtree(testdir)
		i += 1

# -----------------------------------------------------------------------------

def set_astyle_args(filepath, brackets, index):
	"""Set args for calling artistic style.
	"""
	# set astyle executable
	args = [libastyle.get_astyle_path()]
	# set filepaths
	for file in filepath:
		args.append(file)
	# set options
	if len(options) > 0:
		args.append(options)
	args.append("-vRQ")
	if brackets[index] != '_':
		args.append('-' + brackets[index])
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

def system_exit(message):
	"""Accept keyboard input to assure a message is noticed.
	"""
	if len(message.strip()) > 0:
		libastyle.set_error_color()
		print message
	# pause if script is run from the console
	if libastyle.is_executed_from_console():
		if os.name == "nt":
			os.system("pause");
		else:
			raw_input("Press Enter to end . . .\n")
	sys.exit()

# -----------------------------------------------------------------------------

def verify_formatted_files(numformat, totformat):
	"""Check that the formatted files list equals the astyle report total.
	"""
	if totformat != numformat:
		message = "files != report ({0},{1})".format(numformat, totformat)
		system_exit(message)

# -----------------------------------------------------------------------------

# make the module executable
if __name__ == "__main__":
	process_files()
	system_exit("")

# -----------------------------------------------------------------------------
