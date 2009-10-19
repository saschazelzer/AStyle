#! /usr/bin/env python

# Check ASBeautifier copy constructor to verify all variables are copied.
# May need to change the file path and line number lists.
# Line number lists are the lines with opening and closing brackets.

import linecache

# -----------------------------------------------------------------------------

def process_file():
	"""Read ASBeautifier and process the lines."""
	file_path = "../../AStyle/src/ASBeautifier.cpp"
	class_lines1 = [74, 107]		# line numbers for class constructor
	class_lines2 = [270, 342]		# line numbers for class init() function
	copy_lines = [114, 226]		# line numbers for copy constructor
	copy_excludes = [126, 135]	# line numbers to exclude in copy constructor
	lines = 0							# line count
	class_variables = []				# variables in the class constructor
	copy_variables = []				# variables in the copy constructor
	
	file_in = open(file_path, 'r')

	verify_line_numbers(file_path, class_lines1)
	verify_line_numbers(file_path, class_lines2)
	verify_line_numbers(file_path, copy_lines)
	verify_line_numbers(file_path, copy_excludes)
		
	for line_in in file_in:
		lines += 1
		line = line_in.strip()
		line = extract_word(line)
		
		if len(line) == 0:
			continue

		if lines > copy_excludes[0] and lines <= copy_excludes[1]:
			continue
			
		if lines > copy_lines[0] and lines < copy_lines[1]:
			copy_variables.append(line)
						
		if ((lines > class_lines1[0] and lines < class_lines1[1])
		or (lines > class_lines2[0] and lines < class_lines2[1])):
			line = convert_class_function(line)
			if len(line) == 0:
				continue
			class_variables.append(line)
			if line.find("indentLength") != -1:
				class_variables.append("indentString")
				class_variables.append("minConditionalIndent")

	class_variables.sort()
	copy_variables.sort()
	remove_class_duplicates(class_variables)
	find_diffs(class_variables, copy_variables)
	
	print class_variables
	print copy_variables

	file_in.close()

# -----------------------------------------------------------------------------

def convert_class_function(line):
	"""Convert class initialization functions to the corresponding variable."""
	first_paren = line.find('(')
	if first_paren == -1:
		return line
	if line.find("initContainer") != -1:
		line = line[first_paren + 1:]
		first_comma = line.find(',')
		if first_comma != -1:
			line = line[0:first_comma]
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
	else:
		line = "unidentified function: " + line
	return line

# -----------------------------------------------------------------------------
	
def extract_word(line):
	"""Extract the first word in a line."""
	first_space = line.find(' ')
	if first_space != -1:
		line = line[0:first_space]
	first_tab = line.find('\t')
	if first_tab != -1:
		line = line[0:first_tab]
	if len(line) >= 1 and line[0] == '*':
		line =''
	if len(line) >= 2 and line[0] == '/' and line[1] == '/':
		line = ''
	return line

# -----------------------------------------------------------------------------

def find_diffs(class_variables, copy_variables):
	"""Find differences in class and copy variables lists."""
	diffs = 0
	i = 0
	j = 0
	while i < len(class_variables):
		if ( j >= len(copy_variables)
		or class_variables[i] < copy_variables[j]):
			print "missing copy: " + class_variables[i]
			diffs += 1
			i += 1
			continue
		if class_variables[i] > copy_variables[j]:
			print "missing class: " + copy_variables[j]
			diffs += 1
			j +=1
			continue
		i += 1
		j += 1
		
	# get extra copy_variables
	while j < len(copy_variables):
		print "missing class: " + copy_variables[j]
		diffs += 1
		j += 1
		continue
	if diffs == 0:
		print "There are no diffs in the variables!!!"
	else:
		print "There are {0} diffs in the variables.".format(diffs)

# -----------------------------------------------------------------------------

def remove_class_duplicates(class_variables):
	"""Remove duplicates in class variables list."""
	i = 1
	while i < len(class_variables):
		if class_variables[i - 1] == class_variables[i]:
			#  print "duplicate class: " + class_variables[i]
			class_variables.remove(class_variables[i])
			continue
		i +=1

# -----------------------------------------------------------------------------

def verify_line_numbers(file_path, copy_lines):
	cache_line = linecache.getline(file_path, copy_lines[0])
	extract_word(cache_line)
	if (cache_line.find('{') == -1
	and cache_line.find("tempStacks") == -1):
		print "bad beginning line: " + str(copy_lines[0])
	cache_line = linecache.getline(file_path, copy_lines[1])
	extract_word(cache_line)
	if cache_line.find('}') == -1:
		print "bad ending line: " + str(copy_lines[1])

# -----------------------------------------------------------------------------

# make the module executable
if __name__ == "__main__":
	process_file()
	# raw_input("\nPress Enter to continue . . .")

# -----------------------------------------------------------------------------
