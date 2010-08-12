#! /usr/bin/python
# Test functions to print and parse the astyle report file.
# Test functions to extract the formatted files and call a diff viewer.

import libastyle		# local directory
import os
import re				# regular expressions
import subprocess
import sys

# -----------------------------------------------------------------------------

def call_diff_program(filepath1, filepath2):
	"""Call diff program.
	"""
	diff = [libastyle.get_diff_path(), filepath1, filepath2]
	try:
		subprocess.check_call(diff)
	except subprocess.CalledProcessError as e:
		libastyle.system_exit("Bad diff return: " + str(e.returncode))
	except OSError:
		libastyle.system_exit("Cannot find executable: " + diff[0])

# -----------------------------------------------------------------------------

def diff_formatted_files(filepaths, diffOLD=False):
	"""Call the diff program for formatted files.
	   diffOLD=True will diff files from the "OLD" directory.
	   Otherwise diff ".orig" files from the current directory.
	   This function requires keyboard input.
	   It cannot be run from an editor.
	"""
	if not libastyle.is_executed_from_console():
		if diffOLD: diffprog = "diff2-print.py"
		else: diffprog = "diff1-print.py"
		msg = "Run {0} from the console to view the diffs"
		print msg.format(diffprog)
		return
	numin = 0
	processed = 0
	for filepath in filepaths:
		numin += 1
		filepath = filepath.replace('\\', '/')
		stripfile = strip_test_directory_prefix(filepath)
		print "{0} of {1} {2}".format(numin, len(filepaths), stripfile)
		ch = libastyle.getch()
		if ch == 'n' or ch == 'N' or ch == 'm' or ch == 'M': continue
		if ch == 'z' : break
		processed += 1
		if diffOLD:
			oldpath = get_old_filepath(filepath)
			call_diff_program(filepath, oldpath)
		else:
			call_diff_program(filepath, filepath + ".orig")
	print "{0} of {1} diffs processed".format(processed, len(filepaths))

# -----------------------------------------------------------------------------

def extract_directory_from_line(line):
	"""Get the directory from the 'directory line' in the astyle report.
	"""
	# get the directory path
	linesplit = line.split()
	path = linesplit[1]
	# remove the wildcard
	pathsplit = os.path.split(path)
	directory = pathsplit[0]
	# verify result
	if directory == "":
		libastyle.system_exit("Cannot extract directory from line: " + line)
	return directory

# -----------------------------------------------------------------------------

def get_astyle_totals(filename):
	"""Print total information from the astyle total line.
	   The filename must be in the current directory.
	   Return 1 - Number of files formatted
	   Return 2 - Number of files unchanged
	   Return 3 - Runtime minutes
	   Return 4 - Runtime seconds
	"""
	infile = open_filein(filename, 'rb')
	infile.seek(-100, os.SEEK_END)
	for line in infile:
		# use regular expressions to search the lines
		# find total line (with following commas)
		if (re.search("formatted;", line) != None
		and re.search("unchanged;", line) != None):
			totline = line.split()
			formatted = int(totline[0])
			unchanged = int(totline[2])
			if totline[5] == "min":
				minutes = int(totline[4])
				seconds = int(totline[6])
			else:
				minutes = 0
				if totline[4].find('.') == -1:
					seconds = int(totline[4])
				else:
					seconds = float(totline[4])
			return (formatted, unchanged, minutes, seconds)
	libastyle.system_exit("Could Not find total line in libtest")

# -----------------------------------------------------------------------------

def  get_formatted_files(filename):
	"""Get a list of formatted files from the astyle output.
	   Returns a list of the formatted files.
	"""
	infile = open_filein(filename, 'rb')
	formatted = []

	for line in infile:
		# use regular expressions to search the lines
		# main directory line (start of line with a following space)
		if re.match("directory ", line) != None:
			directory = extract_directory_from_line(line)
			continue
		# total line (with a following comma)
		if (re.search("formatted;", line) != None
		and re.search("unchanged;", line) != None):
			continue
		# formatted file line (start of line with a following space)
		if re.match("formatted ", line) != None:
			subline = line[:-1].split()
			formatted.append(directory + os.sep + subline[1])

	infile.close()
	return formatted

# -----------------------------------------------------------------------------

def  get_old_filepath(filepath):
	"""Build a filepath for the "OLD" directory.
	"""
	testdir = libastyle.get_test_directory(True)
	subdir = filepath[len(testdir):]
	sep = subdir.find('/')
	dirname = subdir[:sep]
	oldpath = testdir + dirname + "OLD" + subdir[len(dirname):]
	return oldpath

# -----------------------------------------------------------------------------

def open_filein(filename, mode):
	"""Open an input file and handle the error.
	   Arguments are the same as for the python 'open' statement.
	"""
	try:
		infile = open(filename, mode)
	except IOError:
		libastyle.system_exit("Cannot open input file: " + filename)
	return infile

# -----------------------------------------------------------------------------

def strip_test_directory_prefix(file):
	"""Strip the test directory prefix from a directory or file for printing.
	"""
	prefix = libastyle.get_test_directory(True)
	start = len(prefix)
	if start > len(file): start = 0
	return file[start:]

# -----------------------------------------------------------------------------

def test_all_functions():
	"""Test all functions for syntax.
	   This must be run from a console to test the 'diff' functions.
	"""
	# write test file
	os.chdir(libastyle.get_file_py_directory())
	testfile = libastyle.get_temp_directory() + "libtest.txt"
	test_file_write(testfile)
	# begin tests -----------------------------------------
	files = get_formatted_files(testfile)
		# calls extract_directory_from_line()
	print "No files will be displayed in the comparison program."
	diff_formatted_files(files)
		# calls call_diff_program()
		# calls strip_test_directory_prefix()
	get_astyle_totals(testfile)
	# end tests -------------------------------------------
	os.remove(testfile)

# -----------------------------------------------------------------------------

def test_file_write(filename):
	"""Write a file for testing this module.
	"""
	outfile = open(filename, 'w')
	text = (
		"Artistic Style 1.xx\n"
		"--------------------------------------------------\n"
		"directory $HOME/Projects/TestData/Project/*.cpp\n"
		"--------------------------------------------------\n"
		"formatted  plugins/astyle/astyle/ASFormatter.cpp\n"
		"unchanged* plugins/astyle/astyle/Unchanged.cpp\n"
		"formatted  plugins/codecompletion/parser.cpp\n"
		"unchanged* plugins/codecompletion/unchanged.cpp\n"
		"--------------------------------------------------\n"
		"2 formatted, 2 unchanged, 10 seconds, 1000 lines\n"
	)
	text = text.replace("$HOME", libastyle.get_home_directory())
	outfile.write(text)
	outfile.close()

# -----------------------------------------------------------------------------

# make the module executable
if __name__ == "__main__":
	test_all_functions()
	libastyle.system_exit()

# -----------------------------------------------------------------------------