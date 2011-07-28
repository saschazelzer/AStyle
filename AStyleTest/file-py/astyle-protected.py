#! /usr/bin/python
# Check ASBeautifier protected variables to verify all variables are
# replaced in the activeBeautifierStack.

# to disable the print statement and use the print() function (version 3 format)
from __future__ import print_function

import libastyle		#local directory

# global variables ------------------------------------------------------------

print_detail = False				# print line numbers and total variables
print_variables = False			# print the variables in the lists

# -----------------------------------------------------------------------------

def process_files():
	"""Read astyle.h and ASBeautifier.cpp files and check protected variables."""

	header_variables = []			# protected variables in astyle.h
	beautifier_variables = []		# activeBeautifierStack variables in ASBeautifier.cpp
	header_path = libastyle.get_astyle_directory() + "/src/astyle.h"
	beautifier_path = libastyle.get_astyle_directory() + "/src/ASBeautifier.cpp"

	libastyle.set_text_color()
	print (libastyle.get_python_version())
	get_header_variables(header_variables, header_path)
	get_beautifier_variables(beautifier_variables, beautifier_path)
	header_variables.sort()
	beautifier_variables.sort()

	print ("Checking ASBeautifier protected variables to activeBeautifierStack.")
	total_variables = len(header_variables)
	print ("There are {0} protected variables in the header list.".format(total_variables))

	find_class_diffs(header_variables, beautifier_variables)

	if print_variables:
		print (header_variables)
		print (beautifier_variables)

# -----------------------------------------------------------------------------

def find_class_diffs(header_variables, beautifier_variables):
	"""Find differences in header and class variables lists."""
	# A set is an unordered collection with no duplicate elements
	# converting to a 'set' will remove duplicates
	missing_header =  set(beautifier_variables) - set(header_variables)
	missing_class = set(header_variables) - set(beautifier_variables)

	if len(missing_header) > 0:
		missing_header = list(missing_header)
		missing_header.sort()
		print (str(len(missing_header)) + " missing protected header variables:")
		print (missing_header)

	if len(missing_class) > 0:
		missing_class = list(missing_class)
		missing_class.sort()
		print (str(len(missing_class)) + " missing activeBeautifierStack beautifier variables:")
		print (missing_class)

	diffs= len(missing_header) + len(missing_class)
	if diffs == 0:
		print ("There are NO diffs in the activeBeautifierStack variables!!!")
	else:
		print ("There are {0} diffs in the activeBeautifierStack variables.".format(diffs))

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
		if line.startswith("//"):
			continue
		# start here for 20 lines
		if (beautifier_lines[0] == 0
		and line.find("activeBeautifierStack->back()->") != -1):
			beautifier_lines[0] = lines
		if beautifier_lines[0] == 0:
			continue
		if line.startswith("return"):
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
		print ("{0} {1} activeBeautifierStack".format(beautifier_lines, beautifier_total))

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
		if line.startswith("//"):
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
		print ("{0} {1} header protected".format(header_lines, header_total))

# -----------------------------------------------------------------------------

# make the module executable
if __name__ == "__main__":
	process_files()
	libastyle.system_exit()

# -----------------------------------------------------------------------------
