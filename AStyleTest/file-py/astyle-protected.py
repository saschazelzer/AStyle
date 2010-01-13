#! /usr/bin/python
# Check ASBeautifier protected variables to verify all variables are
# replaced in the activeBeautifierStack.

import libastyle		#local directory
import sys
import os

# global variables ------------------------------------------------------------

print_detail = False				# print line numbers and total variables
print_variables = False			# print the variables in the lists

# -----------------------------------------------------------------------------

def process_files():
	"""Read astyle.h and ASBeautifier.cpp files and check protected variables."""

	header_variables = []			# protected variables in astyle.h
	beautifier_variables = []		# activeBeautifierStack variables in ASBeautifier.cpp
	header_path = get_source_directory() + "/astyle.h"
	beautifier_path = get_source_directory() + "/ASBeautifier.cpp"

	libastyle.set_text_color()
	get_header_variables(header_variables, header_path)
	get_beautifier_variables(beautifier_variables, beautifier_path)
	header_variables.sort()
	beautifier_variables.sort()
	find_diffs(header_variables, beautifier_variables)

	if print_variables:
		print header_variables
		print beautifier_variables

# -----------------------------------------------------------------------------

def find_diffs(header_variables, beautifier_variables):
	"""Find differences in variable lists."""

	diffs = 0
	i = 0
	j = 0

	print "Checking ASBeautifier protected variables to activeBeautifierStack."

	total_variables = len(header_variables)
	if len(beautifier_variables) > total_variables:
		total_variables = len(beautifier_variables)
	print "There are {0} variables in the list.".format(total_variables)

	while i < len(header_variables):
		if ( j >= len(beautifier_variables)
		or header_variables[i] < beautifier_variables[j]):
			print "missing beautifier: " + header_variables[i]
			diffs += 1
			i += 1
			continue
		if header_variables[i] > beautifier_variables[j]:
			print "missing header: " + beautifier_variables[j]
			diffs += 1
			j +=1
			continue
		i += 1
		j += 1

	# get extra beautifier_variables
	while j < len(beautifier_variables):
		print "missing header: " + beautifier_variables[j]
		diffs += 1
		j += 1
		continue

	if diffs == 0:
		print "There are NO diffs in the variables!!!"
	else:
		print "There are {0} diffs in the variables.".format(diffs)

# -----------------------------------------------------------------------------

def get_beautifier_variables(beautifier_variables, beautifier_path):
	"""Read the beautifier file and save the variable updates."""

	beautifier_lines = [0,0]		# line numbers for activeBeautifierStack
	beautifier_total = 0			# total variables activeBeautifierStack
	lines = 0						# current input line number
	file_in = open(beautifier_path, 'r')

	for line_in in file_in:
		lines += 1
		line = line_in.strip()
		if len(line) == 0:
			continue
		if line[:2] == "//":
			continue
		# start here for 20 lines
		if (beautifier_lines[0] == 0
		and line.find("activeBeautifierStack->back()->") != -1):
			beautifier_lines[0] = lines
		if beautifier_lines[0] == 0:
			continue
		if line[0:6] == "return":
			beautifier_lines[1] = lines
			break
		# bypass the variable type
		assignment = line.find('=')
		if assignment == -1:
			continue
		# get the variable name
		variable_name = line[assignment+1:-1].strip()
		# print variable_name
		beautifier_variables.append(variable_name)
		beautifier_total += 1

	file_in.close()
	if print_detail:
		print "{0} {1} activeBeautifierStack".format(beautifier_lines, beautifier_total)

# -----------------------------------------------------------------------------

def get_header_variables(header_variables, header_path):
	"""Read the header file and save the protected variables."""

	header_lines = [0,0]		# line numbers for header
	header_total = 0			# total variables for header
	lines = 0					# current input line number
	file_in = open(header_path, 'r')

	for line_in in file_in:
		lines += 1
		line = line_in.strip()
		if len(line) == 0:
			continue
		# start between the following lines
		if line.find("// variables set by ASFormatter") != -1:
			header_lines[0] = lines
			continue
		if header_lines[0] == 0:
			continue
		if line.find("private:") != -1:
			header_lines[1] = lines -1
			break
		if line[:2] == "//":
			continue
		# bypass the variable type
		last_space = line.rfind(' ')
		if last_space == -1:
			continue
		# get the variable name
		variable_name = line[last_space:-1].strip()
		# print variable_name
		header_variables.append(variable_name)
		header_total += 1

	file_in.close()
	if print_detail:
		print "{0} {1} header protected".format(header_lines, header_total)

# -----------------------------------------------------------------------------

def get_source_directory():
	"""Get the AStyle/src directory for the os environment"""
	if os.name == "nt":
		sourcedir = os.getenv("USERPROFILE") + "/Projects/AStyle/src"
	else:
		sourcedir = os.getenv("HOME") + "/Projects/AStyle/src"
	return sourcedir

# -----------------------------------------------------------------------------

# make the module executable
if __name__ == "__main__":
	process_files()
	# pause if script is not run from SciTE (argv[1] = 'scite')
	if len(sys.argv) == 1:
		if os.name == "nt":
			os.system("pause");
		else:
			raw_input("\nPress Enter to end . . .\n")

# -----------------------------------------------------------------------------
