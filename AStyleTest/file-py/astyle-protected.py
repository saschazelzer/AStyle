#! /usr/bin/env python

# Check ASBeautifier protected variables to verify all variables are 
# replaced in the activeBeautifierStack.

import sys
import os

# global variables ------------------------------------------------------------

first_header_line = 0		# start line in astyle.h
first_beautifier_line = 0		# start line in ASBeautifier.cpp

# -----------------------------------------------------------------------------

def process_files():
	"""Read astyle.h and ASBeautifier.cpp files and check variables."""
	
	header_variables = []			# variables in astyle.h
	beautifier_variables = []		# variables in ASBeautifier.cpp 
	
	header_path = get_source_directory() + "/astyle.h"
	beautifier_path = get_source_directory() + "/ASBeautifier.cpp"
	
	header_variables = get_header_variables(header_path)
	beautifier_variables = get_beautifier_variables(beautifier_path)
	
	header_variables.sort()
	beautifier_variables.sort()
	find_diffs(header_variables, beautifier_variables)

	# print header_variables
	# print beautifier_variables

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

def get_beautifier_variables(beautifier_path):
	"""Read the beautifier file and save the variable updatess."""
	
	global first_beautifier_line
	variables = []
	file_in = open(beautifier_path, 'r')
	lines = 0
		
	for line_in in file_in:
		lines += 1
		line = line_in.strip()
		if len(line) == 0:
			continue
		if line[:2] == "//":
			continue
		# start here for 20 lines
		if line.find("activeBeautifierStack->back()->") == -1:
			continue
		if first_beautifier_line == 0:
			first_beautifier_line = lines
		if lines > first_beautifier_line + 20:
			break
		# bypass the variable type
		assignment = line.find('=')
		if assignment == -1:
			continue
		# get the variable name
		variable_name = line[assignment+1:-1].strip()
		# print variable_name
		variables.append(variable_name)

	file_in.close()
	return variables

# -----------------------------------------------------------------------------

def get_header_variables(header_path):
	"""Read the header file and save the protected variables."""
	
	global first_header_line
	variables = []
	file_in = open(header_path, 'r')
	lines = 0
	
	for line_in in file_in:
		lines += 1
		line = line_in.strip()
		if len(line) == 0:
			continue
		# start between the following lines
		if line.find("// variables set by ASFormatter") != -1:
			first_header_line = lines
			continue
		if first_header_line == 0:
			continue
		if line.find("private:") != -1:
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
		variables.append(variable_name)
		
	file_in.close()
	return variables

# -----------------------------------------------------------------------------

def get_source_directory():
	"""Get the AStyle/src directory for the os environment"""
	
	if os.name == "nt":
		return os.getenv("USERPROFILE") + "/Projects/AStyle/src"
	else:
		return os.getenv("HOME") + "/Projects/AStyle/src"

# -----------------------------------------------------------------------------

# make the module executable
if __name__ == "__main__":
	process_files()
	# pause if script is not run from SciTE (argv[1] = 'scite')
	if len(sys.argv) == 1:
		raw_input("\nPress Enter to continue . . .")

# -----------------------------------------------------------------------------
