#! /usr/bin/python
# Test functions to print and parse the astyle report file.
# Test functions to extract the formatted files and call a diff viewer.

import libastyle		# local directory
import os
import re				# regular expressions
import subprocess
import sys

if os.name == "nt": import msvcrt		# Windows only for getch()
else: import tty, termios						# Linux only for getch()

# -----------------------------------------------------------------------------

def call_diff_program(filepath):
	"""Call diff program.
	"""
	diff = [libastyle.get_diff_path()]
	diff.append(filepath)
	diff.append(filepath + ".orig")
	try:
		subprocess.check_call(diff)
	except subprocess.CalledProcessError as e:
		system_exit("Bad diff return: " + str(e.returncode))
	except OSError:
		system_exit("Cannot find executable: " + diff[0])

# -----------------------------------------------------------------------------

def diff_formatted_files(files, totformat):
	"""Call the diff program for formatted files.
		This function requires keyboard input.
		It cannot be run from an editor.
	"""
	if not libastyle.is_executed_from_console():
		print "Run diff-print.py from the console to view the diffs"
		return
	numin = 0
	processed = 0
	for file in files:
		numin += 1
		stripfile = strip_test_directory_prefix(file)
		print "{0} of {1} {2}".format(numin, totformat, stripfile)
		ch = getch()		# local function
		if ch == '\000' or ch == '\xe0':
			ch = getch()
		if ch == 'n' or ch == 'm': continue
		if ch == 'z' : break
		processed += 1
		call_diff_program(file)
	print "{0} of {1} diffs processed".format(processed, len(files))

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
		system_exit("Cannot extract directory from line: " + line)
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
	infile = open(filename, 'rb')
	infile.seek(-100, os.SEEK_END)
	for line in infile:
		# use regular expressions to search the lines
		# find total line (with following commas)
		if (re.search("formatted,", line) != None
		and re.search("unchanged,", line) != None):
			totline = line.split()
			formatted = int(totline[0])
			unchanged = int(totline[2])
			if totline[5] == "min":
				minutes = int(totline[4])
				seconds = int(totline[6])
			else:
				minutes = 0
				if re.search('.', totline[4]) == None:
					seconds = int(totline[4])
				else:
					seconds = float(totline[4])
			return (formatted, unchanged, minutes, seconds)
	system_exit("Could Not find total line in libtest")

# -----------------------------------------------------------------------------

def getch():
	"""getch() for Windows and Linux.
	   This won't work unless run from a terminal.
	"""
	if os.name == "nt":
		ch = msvcrt.getch()
	else:
		fd = sys.stdin.fileno()
		old_settings = termios.tcgetattr(fd)
		try:
			tty.setraw(sys.stdin.fileno())
			ch = sys.stdin.read(1)
		finally:
			termios.tcsetattr(fd, termios.TCSADRAIN, old_settings)
	return ch

# -----------------------------------------------------------------------------

def  get_formatted_files(filename):
	"""Get a list of formatted files from the astyle output.
	   Returns a list of the formatted files.
	"""
	infile = open(filename, 'rb')
	formatted = []

	for line in infile:
		# use regular expressions to search the lines
		# main directory line (start of line with a following space)
		if re.match("directory ", line) != None:
			directory = extract_directory_from_line(line)
			continue
		# total line (with a following comma)
		if (re.search("formatted,", line) != None
		and re.search("unchanged,", line) != None):
			continue
		# formatted file line (start of line with a following space)
		if re.match("formatted ", line) != None:
			subline = line.split()
			formatted.append(directory + os.sep + subline[1])

	infile.close()
	return formatted

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
	testfile = "testx.txt"
	test_file_write(testfile)
	# begin tests -----------------------------------------
	files = get_formatted_files(testfile)
		# calls extract_directory_from_line()
	diff_formatted_files(files, 2)
		# calls call_diff_program() 
		# calls getch() 
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
		"directory /home/user/Projects/TestData/Project/*.cpp\n"
		"--------------------------------------------------\n"
		"formatted  plugins/astyle/astyle/ASFormatter.cpp\n"
		"unchanged* plugins/astyle/astyle/Unchanged.cpp\n"
		"formatted  plugins/codecompletion/parser.cpp\n"
		"unchanged* plugins/codecompletion/unchanged.cpp\n"
		"--------------------------------------------------\n"
		"2 formatted, 2 unchanged, 10 seconds, 1000 lines\n"
	)
	text.replace("/home/user", libastyle.get_home_directory())
	outfile.write(text)
	outfile.close()

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

# make the module executable
if __name__ == "__main__":
	test_all_functions()
	system_exit("")

# -----------------------------------------------------------------------------