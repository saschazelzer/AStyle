#! /usr/bin/python
# Check astyle_main.cpp "settext" translations to the test variables in AStyleTestI18n_Localizer.cpp.
# The test for the individual languages are done by AStyleTestI18n_Localizer.cpp.

import libastyle		#local directory
import sys
import os

# global variables ------------------------------------------------------------

print_detail = False				# print line numbers and total variables
print_strings = False			# print the variables in the lists

# -----------------------------------------------------------------------------

def process_files():
	"""Main processing function."""

	astyle_strings = []		# _() translation strings in astyle_main.cpp
	test_strings = []			# test strings in TranslationF
	astyle_path = libastyle.get_astyle_directory() + "/src/astyle_main.cpp"
	test_path = libastyle.get_astyletest_directory() + "/srci18n/AStyleTestI18n_Localizer.cpp"
	libastyle.set_text_color()
	# process the files
	get_astyle_strings(astyle_strings, astyle_path)
	get_test_strings(test_strings, test_path)
	find_string_diffs(astyle_strings, test_strings)

	if print_strings:
		astyle_strings.sort()
		test_strings.sort()
		print astyle_strings
		print test_strings

# -----------------------------------------------------------------------------

def find_string_diffs(astyle_strings, test_strings):
	"""Find differences in header and class variables lists."""
	# A set is an unordered collection with no duplicate elements
	# converting to a 'set' will remove duplicates
	missing_test =  set(astyle_strings) - set(test_strings)
	missing_astyle = set(test_strings) - set(astyle_strings)

	if len(missing_test) > 0:
		missing_test = list(missing_test)
		missing_test.sort()
		print str(len(missing_test)) + " missing test strings",
		print missing_test

	if len(missing_astyle) > 0:
		missing_astyle = list(missing_astyle)
		missing_astyle.sort()
		print str(len(missing_astyle)) + " test not in astyle  ",
		print missing_astyle

	diffs= len(missing_test) + len(missing_astyle)
	if diffs == 0:
		print "There are NO diffs in the test strings!!!"
	else:
		print "There are {0} diffs in the test strings.".format(diffs)

# -----------------------------------------------------------------------------

def get_astyle_strings(astyle_strings, astyle_path):
	"""Read the astyle_main.cpp file and save the settext strings."""

	astyle_total = 0			# total strings extracted
	lines = 0					# current input line number
	file_in = open(astyle_path, 'r')

	# get astyle settext strings
	for line_in in file_in:
		lines += 1
		line = line_in.strip()
		if len(line) == 0:
			continue
		if line[:2] == "//":
			continue
		# get the _() settext strings
		start = line.find('_("')
		if start == -1:
			continue
		start += 3;
		end = line.find('")', start)
		if end == -1:
			continue
		settext_string = line[start:end]
		astyle_strings.append(settext_string)
		astyle_total += 1

	file_in.close()
	if print_detail:
		print "{0} astyle strings".format(astyle_total)

# -----------------------------------------------------------------------------

def get_test_strings(test_strings, test_path):
	"""Read the AStyleTestI18n_Localizer.cpp file and save the test strings."""

	test_lines = [0,0]		# line numbers for TranslationF constructor
	test_total = 0				# total variables for header
	test_brackets = 0		#  unmatched brackets in the header
	lines = 0						# current input line number
	file_in = open(test_path, 'r')

	for line_in in file_in:
		lines += 1
		line = line_in.strip()
		if len(line) == 0:
			continue
		if line[:2] == "//":
			continue

		# start between the following lines
		if line.startswith("TranslationF()"):
			test_lines[0] = lines + 1
			continue
		if test_lines[0]  == 0:
			continue
		# count brackets
		if line.find('{') != -1:
			test_brackets += 1
		if line.find('}') != -1:
			test_brackets -= 1
		if  test_brackets == 0:
			test_lines[1] = lines
			break
		# extract the string
		if line.find('m_ascii.push_back("') == -1:
			continue
		start = line.find('("') 
		if start == -1:
			continue
		start += 2
		end = line.find('")', start)
		if end == -1:
			continue
		test_string = line[start:end]
		test_strings.append(test_string)
		test_total += 1

	file_in.close()
	if print_detail:
		print "{0} {1} test strings".format(test_lines, test_total)

# -----------------------------------------------------------------------------

# make the module executable
if __name__ == "__main__":
	process_files()
	libastyle.system_exit()

# -----------------------------------------------------------------------------
