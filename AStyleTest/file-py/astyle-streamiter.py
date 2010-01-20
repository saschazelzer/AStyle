#! /usr/bin/python
# Check ASStreamIterator constructor to class variables
#     in the header file to verify all variables are initialized .

import libastyle		#local directory
import sys
import os

# global variables ------------------------------------------------------------

print_detail = False				# print line numbers and total variables
print_variables = False			# print the variables in the lists

# -----------------------------------------------------------------------------

def process_files():
	"""Main processing function."""

	header_variables = []		# variables in astyle.h
	class_variables = []			# variables in the class constructor
	header_path = get_source_directory() + "/astyle_main.h"
	iterator_path = get_source_directory() + "/astyle_main.cpp"

	libastyle.set_text_color()
	get_header_variables(header_variables, header_path)
	get_constructor_variables(class_variables, iterator_path)

	print "Checking ASStreamIterator header to class constructor."
	total_variables = len(header_variables)
	print "There are {0} variables in the header list.".format(total_variables)

	find_class_diffs(header_variables, class_variables)

	if print_variables:
		print header_variables
		print class_variables

# -----------------------------------------------------------------------------

def convert_class_functions(line):
	"""Convert class initializer functions to the corresponding variable."""
	first_paren = line.find('(')
	if first_paren == -1:
		return line
	if line.find("buffer.reserve") != -1:
		line = ''
	elif line.find("setOutputEOL") != -1:
		line = "outputEOL[4]"
	else:
		line = "unidentified function: " + line
	return line

# -----------------------------------------------------------------------------

def find_class_diffs(header_variables, class_variables):
	"""Find differences in header and class variables lists."""
	# A set is an unordered collection with no duplicate elements
	# converting to a 'set' will remove duplicates
	missing_header =  set(class_variables) - set(header_variables)
	missing_class = set(header_variables) - set(class_variables)

	if len(missing_header) > 0:
		missing_header = list(missing_header)
		missing_header.sort()
		print str(len(missing_header)) + " missing header variables:"
		print missing_header

	if len(missing_class) > 0:
		missing_class = list(missing_class)
		missing_class.sort()
		print str(len(missing_class)) + " missing class constructor variables:"
		print missing_class

	diffs= len(missing_header) + len(missing_class)
	if diffs == 0:
		print "There are NO diffs in the class constructor variables!!!"
	else:
		print "There are {0} diffs in the class constructor variables.".format(diffs)

# -----------------------------------------------------------------------------

def get_constructor_variables(class_variables, iterator_path):
	"""Read the astyle_main file and save the class constuctor variables."""

	class_lines = [0,0]		# line numbers for class constructor
	class_total = 0			# total variables for class constructor
	lines = 0					# current input line number
	file_in = open(iterator_path, 'r')

	# get class constructor lines
	for line_in in file_in:
		lines += 1
		line = line_in.strip()
		if len(line) == 0:
			continue
		if line[:2] == "//":
			continue
		# start between the following lines
		if line.find("ASStreamIterator<T>::ASStreamIterator") != -1:
			class_lines[0] = lines + 1
			continue
		if (class_lines[0]  == 0
		or class_lines[0]  >= lines):
			continue
		# find ending bracket
		if line.find('}') != -1:
			class_lines[1] = lines
			break
		# get the variable name
		variable_name = line
		if line.find('(') != -1:
			variable_name = convert_class_functions(line)
		else:
			first_space = line.find(' ')
			if first_space != -1:
				variable_name = line[:first_space].strip()
			first_sqbr = variable_name.find('[')
			if first_sqbr != -1:
				variable_name = variable_name[:first_sqbr].strip()
		if len(variable_name) == 0:
			continue
		class_variables.append(variable_name)
		class_total += 1

	file_in.close()
	if print_detail:
		print "{0} {1} class constructor".format(class_lines, class_total)

# -----------------------------------------------------------------------------

def get_header_variables(header_variables, header_path):
	"""Read the header file and save the ASStreamIterator variables."""

	header_lines = [0,0]			# line numbers for header
	header_total = 0				# total variables for header
	lines = 0						# current input line number
	file_in = open(header_path, 'r')

	for line_in in file_in:
		lines += 1
		line = line_in.strip()
		if len(line) == 0:
			continue
		if line[:2] == "//":
			continue

		# start between the following lines
		if line.find("class ASStreamIterator") != -1:
			header_lines[0] = lines + 1
			continue
		if (header_lines[0]  == 0
		or header_lines[0]  >= lines):
			continue
		# find ending bracket - should find following comment instead
		if line.find('}') != -1:
			header_lines[1] = lines
			break
		# find ending comment
		if line.find("// inline functions") != -1:
			header_lines[1] = lines
			break
		if (line.find("public:") != -1
		or line.find("private:") != -1
		or line.find("protected:") != -1):
			continue
		# bypass functions
		if (line.find('(') != -1
		or line.find(')') != -1):
			continue
		# bypass static variables
		if line[:6] == "static":
			continue
		# bypass vectors and strings
		if line.find("buffer") != -1:
			continue
		if line.find("prevBuffer") != -1:
			continue
		# get the variable name
		semi_colon = line.find(';');
		if semi_colon == -1:
			continue
		first_space = line[:semi_colon].rfind(' ')
		if first_space == -1:
			continue
		variable_name = line[first_space:semi_colon].strip()
		first_sqbr = variable_name.find('[')
		if first_sqbr != -1:
			variable_name = variable_name[:first_sqbr].strip()
		if variable_name[0] == '*':
			variable_name = variable_name[1:]
		header_variables.append(variable_name)
		header_total += 1

	file_in.close()
	if print_detail:
		print "{0} {1} header".format(header_lines, header_total)

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
	libastyle.system_exit()

# -----------------------------------------------------------------------------
