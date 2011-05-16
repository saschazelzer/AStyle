#! /usr/bin/python
# Check ASBeautifier constructor and copy constructor to class variables
#     in the header file to verify all variables are initialized and copied.

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
	copy_variables = []			# variables in the copy constructor
	header_path = libastyle.get_astyle_directory() + "/src/astyle.h"
	beautifier_path = libastyle.get_astyle_directory() + "/src/ASBeautifier.cpp"

	libastyle.set_text_color()
	get_header_variables(header_variables, header_path)
	get_constructor_variables(class_variables, beautifier_path)
	get_initializer_variables(class_variables, beautifier_path)
	get_copy_variables(copy_variables, beautifier_path)
	header_variables.sort()

	print "Checking ASBeautifier header to class constructor and copy constructor."
	total_variables = len(header_variables)
	print "There are {0} variables in the header list.".format(total_variables)

	find_class_diffs(header_variables, class_variables)
	find_copy_diffs(header_variables, copy_variables)

	if print_variables:
		print header_variables
		print class_variables
		print copy_variables

# -----------------------------------------------------------------------------

def convert_class_functions(line):
	"""Convert class initializer functions to the corresponding variable."""
	first_paren = line.find('(')
	if first_paren == -1:
		return line
	if line.find("initContainer") != -1:
		line = line[first_paren + 1:]
		first_comma = line.find(',')
		if first_comma != -1:
			line = line[:first_comma]
		line = line.strip()
	elif line.find("->") != -1:
		line = ''
	elif line.find("initVectors") != -1:
		line = ''
	elif line.find("ASBase::init") != -1:
		line = ''
	elif line.find("initStatic") != -1:
		line = ''
	elif line.find("setSpaceIndentation") != -1:
		line = "indentLength"
	elif line.find("setMaxInStatementIndentLength") != -1:
		line = "maxInStatementIndent"
	elif line.find("setClassIndent") != -1:
		line = "classIndent"
	elif line.find("setSwitchIndent") != -1:
		line = "switchIndent"
	elif line.find("setCaseIndent") != -1:
		line = "caseIndent"
	elif line.find("setBlockIndent") != -1:
		line = "blockIndent"
	elif line.find("setBracketIndent") != -1:
		line = "bracketIndent"
	elif line.find("setNamespaceIndent") != -1:
		line = "namespaceIndent"
	elif line.find("setLabelIndent") != -1:
		line = "labelIndent"
	elif line.find("setEmptyLineFill") != -1:
		line = "emptyLineFill"
	elif line.find("setCStyle") != -1:
		line = "fileType"
	elif line.find("setPreprocessorIndent") != -1:
		line = "preprocessorIndent"
	elif line.find("setMinConditionalIndentOption") != -1:
		line = "minConditionalOption"
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
		print str(len(missing_class)) + " missing class variables:"
		print missing_class

	diffs= len(missing_header) + len(missing_class)
	if diffs == 0:
		print "There are NO diffs in the class constructor variables!!!"
	else:
		print "There are {0} diffs in the class constructor variables.".format(diffs)

# -----------------------------------------------------------------------------

def find_copy_diffs(header_variables, copy_variables):
	"""Find differences in header and copy variables lists."""
	# A set is an unordered collection with no duplicate elements
	# converting to a 'set' will remove duplicates
	missing_header =  set(copy_variables) - set(header_variables)
	missing_copy = set(header_variables) - set(copy_variables)

	if len(missing_header) > 0:
		missing_header = list(missing_header)
		missing_header.sort()
		print str(len(missing_header)) + " missing header variables:"
		print missing_header

	if len(missing_copy) > 0:
		missing_copy = list(missing_copy)
		missing_copy.sort()
		print str(len(missing_copy)) + " missing copy constructor variables:"
		print missing_copy

	diffs= len(missing_header) + len(missing_copy)
	if diffs == 0:
		print "There are NO diffs in the copy constructor variables!!!"
	else:
		print "There are {0} diffs in the copy constructor variables.".format(diffs)

# -----------------------------------------------------------------------------

def get_constructor_variables(class_variables, beautifier_path):
	"""Read the ASBeautifier file and save the class constuctor variables."""

	class_lines = [0,0]		# line numbers for class constructor
	class_total = 0			# total variables for class constructor
	lines = 0					# current input line number
	file_in = open(beautifier_path, 'r')

	# get class constructor lines
	for line_in in file_in:
		lines += 1
		line = line_in.strip()
		if len(line) == 0:
			continue
		if line.startswith("//"):
			continue
		# start between the following lines
		if line.find("ASBeautifier::ASBeautifier") != -1:
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
				variable_name = line[0:first_space].strip()
		if len(variable_name) == 0:
			continue
		class_variables.append(variable_name)
		class_total += 1
		if variable_name == "indentLength":
			class_variables.append("indentString")
			class_variables.append("minConditionalIndent")
			class_total += 2

	file_in.close()
	if print_detail:
		print "{0} {1} class constructor".format(class_lines, class_total)

# -----------------------------------------------------------------------------

def get_copy_variables(copy_variables, beautifier_path):
	"""Read the ASBeautifier file and save the copy constuctor variables."""

	copy_lines = [0,0]			# line numbers for copy constructor
	copy_total = 0				# total variables for copy constructor
	copy_brackets  = 0			#  unmatched brackets in the copy constructor
	lines = 0						# current input line number
	file_in = open(beautifier_path, 'r')

	for line_in in file_in:
		lines += 1
		line = line_in.strip()
		if len(line) == 0:
			continue
		if line.startswith("//"):
			continue

		# start between the following lines
		if line.find("ASBeautifier(const ASBeautifier") != -1:
			copy_lines[0] = lines + 1
			copy_brackets += 1
			continue
		if (copy_lines[0]  == 0
		or copy_lines[0]  >= lines):
			continue
		# count brackets
		if line.find('{') != -1:
			copy_brackets += 1
		if line.find('}') != -1:
			copy_brackets -= 1
		if  copy_brackets == 0:
			copy_lines[1] = lines
			break
		# get the variable name
		first_space = line.find(' ')
		if first_space == -1:
			continue
		variable_name = line[:first_space].strip()
		# value-of variables are duplicates
		if variable_name[0] == '*':
			continue
		copy_variables.append(variable_name)
		copy_total += 1

	file_in.close()
	if print_detail:
		print "{0} {1} copy constructor".format(copy_lines, copy_total)

# -----------------------------------------------------------------------------

def get_header_variables(header_variables, header_path):
	"""Read the header file and save the ASBeautifier variables."""

	header_lines = [0,0]		# line numbers for header
	header_total = 0			# total variables for header
	lines = 0					# current input line number
	file_in = open(header_path, 'r')

	for line_in in file_in:
		lines += 1
		line = line_in.strip()
		if len(line) == 0:
			continue
		if line.startswith("//"):
			continue

		# start between the following lines
		if line.find("class ASBeautifier") != -1:
			header_lines[0] = lines + 1
			continue
		if (header_lines[0]  == 0
		or header_lines[0]  >= lines):
			continue
		# find ending bracket
		if line.find('}') != -1:
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
		# get the variable name
		semi_colon = line.find(';');
		if semi_colon == -1:
			continue
		last_space = line[:semi_colon].rfind(' ')
		if last_space == -1:
			continue
		variable_name = line[last_space:semi_colon].strip()
		if variable_name[0] == '*':
			variable_name = variable_name[1:]
		header_variables.append(variable_name)
		header_total += 1

	file_in.close()
	if print_detail:
		print "{0} {1} header".format(header_lines, header_total)

# -----------------------------------------------------------------------------

def get_initializer_variables(class_variables, beautifier_path):
	"""Read the ASBeautifier file and save the class initializer variables."""

	class_lines_init = [0,0]		# line numbers for class init() function
	class_total_init = 0			# total variables for class init() function
	lines_init = 0					# current input line number
	file_in_init = open(beautifier_path, 'r')

	# get class initializer lines
	for line_in in file_in_init:
		lines_init += 1
		line = line_in.strip()
		if len(line) == 0:
			continue
		if line.startswith("//"):
			continue
		# start between the following lines
		if line.find("void ASBeautifier::init()") != -1:
			class_lines_init[0] = lines_init + 1
			continue
		if (class_lines_init[0]  == 0
		or class_lines_init[0]  >= lines_init):
			continue
		# find ending bracket
		if line.find('}') != -1:
			class_lines_init[1] = lines_init
			break
		# get the variable name
		variable_name = line
		if line.find('(') != -1:
			variable_name = convert_class_functions(line)
		else:
			first_space = line.find(' ')
			if first_space != -1:
				variable_name = line[:first_space].strip()
		if len(variable_name) == 0:
			continue
		class_variables.append(variable_name)
		class_total_init += 1

	file_in_init.close()
	if print_detail:
		print "{0} {1} class initializer".format(class_lines_init, class_total_init)

# -----------------------------------------------------------------------------

# make the module executable
if __name__ == "__main__":
	process_files()
	libastyle.system_exit()

# -----------------------------------------------------------------------------
