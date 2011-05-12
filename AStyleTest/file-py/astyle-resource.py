#! /usr/bin/python
# Check ASResource vectors for various criteria.

import libastyle		#local directory
import sys
import os

# global variables ------------------------------------------------------------

print_detail = False				# print line numbers and total variables
print_variables = False			# print the variables in the lists

# -----------------------------------------------------------------------------

def process_files():
	"""Main processing function."""

	header_variables = []				# header vector variables
	np_header_variables = []			# non-paren header variables
	pre_block_variables = []			# pre-block statement variables
	pre_command_variables = []		# pre-command header variables
	resource_path = libastyle.get_astyle_directory() + "/src/ASResource.cpp"

	libastyle.set_text_color()
	get_header_variables(header_variables, resource_path)
	get_np_header_variables(np_header_variables, resource_path)
	get_pre_block_variables(pre_block_variables, resource_path)
	get_pre_command_variables(pre_command_variables, resource_path)

	print "Checking header variables to non-paren, pre-block, and pre-command."
	total_variables = len(header_variables)
	print "There are {0} variables in the header list.".format(total_variables)

	find_header_diffs(header_variables, np_header_variables)
	find_pre_block_diffs(header_variables, pre_block_variables)
	find_pre_command_diffs(header_variables, pre_command_variables)

	if print_variables:
		print header_variables
		print np_header_variables
		print pre_block_variables
		print pre_command_variables

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

def find_header_diffs(header_variables, np_header_variables):
	"""Find differences in header and non-paren header variables lists."""
	# A set is an unordered collection with no duplicate elements
	# converting to a 'set' will remove duplicates
	missing_header =  set(np_header_variables) - set(header_variables)

	if len(missing_header) > 0:
		missing_header = list(missing_header)
		missing_header.sort()
		print str(len(missing_header)) + " missing header variables:"
		print missing_header

	diffs= len(missing_header)
	if diffs == 0:
		print "There are NO missing non-paren header variables!!!"
	else:
		print "There are {0} missing non-paren header variables.".format(diffs)

# -----------------------------------------------------------------------------

def find_pre_block_diffs(header_variables, pre_block_variables):
	"""Find differences in header and pre-block variables lists."""
	# A set is an unordered collection with no duplicate elements
	# converting to a 'set' will remove duplicates
	pre_block_set = set(pre_block_variables)		# remove duplicates for comparison
	duplicate_header =  set(pre_block_variables) - set(header_variables)

	diffs= len(duplicate_header) - len(pre_block_set)
	if diffs != 0:
		duplicate_header = list(missing_header)
		duplicate_header.sort()
		print str(len(duplicate_header)) + " duplicate pre-block variables:"
		print duplicate_header

	if diffs == 0:
		print "There are NO duplicates in the pre-block variables!!!"
	else:
		print "There are {0} duplicates in the pre-block variables.".format(diffs)

# -----------------------------------------------------------------------------

def find_pre_command_diffs(header_variables, pre_command_variables):
	"""Find differences in header and pre-comand variables lists."""
	# A set is an unordered collection with no duplicate elements
	# converting to a 'set' will remove duplicates
	pre_command_set = set(pre_command_variables)		# remove duplicates for comparison
	duplicate_header =  set(pre_command_variables) - set(header_variables)

	diffs= len(duplicate_header) - len(pre_command_set)
	if diffs != 0:
		duplicate_header = list(missing_header)
		duplicate_header.sort()
		print str(len(duplicate_header)) + " duplicate pre-command variables:"
		print duplicate_header

	if diffs == 0:
		print "There are NO duplicates in the pre-command variables!!!"
	else:
		print "There are {0} duplicates in the pre-command variables.".format(diffs)

# -----------------------------------------------------------------------------

def get_header_variables(header_variables, resource_path):
	"""Read the ASResource file and save the header variables."""
	header_total = 0			# total variables for headers
	lines = 0					# current input line number
	file_in = open(resource_path, 'r')

	for line_in in file_in:
		lines += 1
		line = line_in.strip()
		if len(line) == 0:
			continue
		if line.startswith("//"):
			continue

		# find the header write commands
		if line.find("headers->push_back") == -1:
			continue
		# get the variable name
		start = line.find("AS_");
		if start == -1:
			continue
		end = line[start :].find(')')
		if end  == -1:
			continue
		variable_name = line[start:start+end].strip()
		header_variables.append(variable_name)
		header_total += 1

	file_in.close()
	if print_detail:
		print "{0} headers".format(header_total)

# -----------------------------------------------------------------------------

def get_np_header_variables(np_header_variables, resource_path):
	"""Read the ASResource file and save the non-paren header variables."""
	np_header_total = 0		# total variables for non-paren headers
	lines = 0					# current input line number
	file_in = open(resource_path, 'r')

	for line_in in file_in:
		lines += 1
		line = line_in.strip()
		if len(line) == 0:
			continue
		if line.startswith("//"):
			continue

		# find the non-paren header write commands
		if line.find("nonParenHeaders->push_back") == -1:
			continue
		# get the variable name
		start = line.find("AS_");
		if start == -1:
			continue
		end = line[start :].find(')')
		if end  == -1:
			continue
		variable_name = line[start:start+end].strip()
		np_header_variables.append(variable_name)
		np_header_total += 1

	file_in.close()
	if print_detail:
		print "{0} non-paren headers".format(np_header_total)

# -----------------------------------------------------------------------------

def get_pre_block_variables(pre_block_variables, resource_path):
	"""Read the ASResource file and save the pre-block statement variables."""
	pre_block_total = 0		# total variables for pre-block statements
	lines = 0					# current input line number
	file_in = open(resource_path, 'r')

	for line_in in file_in:
		lines += 1
		line = line_in.strip()
		if len(line) == 0:
			continue
		if line.startswith("//"):
			continue

		# find the pre-block statement write commands
		if line.find("preBlockStatements->push_back") == -1:
			continue
		# get the variable name
		start = line.find("AS_");
		if start == -1:
			continue
		end = line[start :].find(')')
		if end  == -1:
			continue
		variable_name = line[start:start+end].strip()
		pre_block_variables.append(variable_name)
		pre_block_total += 1

	file_in.close()
	if print_detail:
		print "{0} pre-block statements".format(pre_block_total)

	# -----------------------------------------------------------------------------

def get_pre_command_variables(pre_command_variables, resource_path):
	"""Read the ASResource file and save the pre-command header variables."""
	pre_command_total = 0	# total variables for pre-command headers
	lines = 0						# current input line number
	file_in = open(resource_path, 'r')

	for line_in in file_in:
		lines += 1
		line = line_in.strip()
		if len(line) == 0:
			continue
		if line.startswith("//"):
			continue

		# find the pre-command header write commands
		if line.find("preCommandHeaders->push_back") == -1:
			continue
		# get the variable name
		start = line.find("AS_");
		if start == -1:
			continue
		end = line[start :].find(')')
		if end  == -1:
			continue
		variable_name = line[start:start+end].strip()
		pre_command_variables.append(variable_name)
		pre_command_total += 1

	file_in.close()
	if print_detail:
		print "{0} pre-command headers".format(pre_command_total)

# -----------------------------------------------------------------------------

# make the module executable
if __name__ == "__main__":
	process_files()
	libastyle.system_exit()

# -----------------------------------------------------------------------------
