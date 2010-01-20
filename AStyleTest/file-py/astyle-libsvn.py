#! /usr/bin/python
# Check libSVN.bat to projects.bat to verify all .svn directories are backed up.

import libastyle		#local directory
import sys
import os

# global variables ------------------------------------------------------------

print_variables = False			# print the variables in the lists

# -----------------------------------------------------------------------------

def process_files():
	"""Read project and libSVN files and check the directories."""

	projects_path = get_batch_directory() + "/projects.bat"
	libsvn_path = get_batch_directory() + "/libSVN.bat"
	projects_directories = []	# directories in projects.bat
	libsvn_directories = []		# directories in  libSVN.bat

	libastyle.set_text_color()
	get_directories(projects_directories, projects_path)
	get_directories(libsvn_directories, libsvn_path)
	correct_projects_directories(projects_directories)
	
	print "Checking projects.bat directories to libSVN.bat."
	total_variables = len(projects_directories)
	print "There are {0} directories in the projects directories.".format(total_variables)

	find_diffs(projects_directories, libsvn_directories)

	if print_variables:
		print projects_directories
		print libsvn_directories

# -----------------------------------------------------------------------------

def correct_projects_directories(projects_directories):
	"""Make corrections to projects directories."""
	# add directories with .svn directories but no files
	projects_directories.append("AStyle")
	projects_directories.append("AStyle\\build")
	projects_directories.append("AStyleDev")
	projects_directories.append("AStyleDev\\build")
	projects_directories.append("AStyleTest")
	projects_directories.append("AStyleTest\\build")
	projects_directories.append("AStyleWeb")
	projects_directories.append("AStyleWeb\\build")
	# add directories not backed up by projects.bat
	projects_directories.append("AStyleDev\\test-c")
	projects_directories.append("AStyleDev\\test-j")
	projects_directories.append("AStyleDev\\test-s")
	# remove directories backed up but not in svn
	projects_directories.remove("AStyle\\regress")

	return projects_directories

# -----------------------------------------------------------------------------

def extract_word(line):
	"""Extract the first word in a line."""
	line = line.strip()
	first_space = line.find(' ')
	if first_space != -1:
		line = line[:first_space]
	first_tab = line.find('\t')
	if first_tab != -1:
		line = line[:first_tab]
	comma = line.find(',')
	if comma != -1:
		line = line[:comma]
	close_paren = line.find(')')
	if close_paren != -1:
		line = line[:close_paren]
	if len(line) >= 1 and line[0] == '#':
		line =''
	return line

# -----------------------------------------------------------------------------

def find_diffs(projects_directories, libsvn_directories):
	"""Find differences in directory lists."""
	# A set is an unordered collection with no duplicate elements
	# converting to a 'set' will remove duplicates
	missing_projects =  set(libsvn_directories) - set(projects_directories)
	missing_libsvn = set(projects_directories) - set(libsvn_directories)

	if len(missing_projects) > 0:
		missing_projects = list(missing_projects)
		missing_projects.sort()
		print str(len(missing_projects)) + " missing projects directories:"
		print missing_projects

	if len(missing_libsvn) > 0:
		missing_libsvn = list(missing_libsvn)
		missing_libsvn.sort()
		print str(len(missing_libsvn)) + " missing libSVN directories:"
		print missing_libsvn

	diffs= len(missing_projects) + len(missing_libsvn)
	if diffs == 0:
		print "There are NO diffs in the directories!!!"
	else:
		print "There are {0} diffs in the directories.".format(diffs)

# -----------------------------------------------------------------------------

def get_batch_directory():
	"""Get the AStyle/src directory for the os environment"""
	if os.name == "nt":
		return os.getenv("USERPROFILE") + "/batch"
	else:
		return os.getenv("HOME") + "/bin"


# -----------------------------------------------------------------------------

def get_directories(directories, file_path):
	"""Read the batch file, find the 'for' statements, and save the directories."""

	file_in = open(file_path, 'r')
	for_statement = 0

	for line_in in file_in:
		line = line_in.strip()
		if len(line) == 0:
			continue
		# save the directories in a 'for' statement and check for end
		if for_statement == 1:
			directory_name = extract_word(line)
			if is_svn_directory(directory_name):
				# print directory_name
				directories.append(directory_name)
			if line.find(')') != -1:
				for_statement = 0
			continue
		# find the 'for' statements and save the first directory
		first_word = line.find('for ')
		if first_word != -1:
			#print line
			for_statement = 1
			open_paren = line.find('(')
			if open_paren == -1:
				print "missing open paren: " + line
				continue
			directory_name = extract_word(line[open_paren+1:])
			if is_svn_directory(directory_name):
				# print directory_name
				directories.append(directory_name)
			continue

	file_in.close()

# -----------------------------------------------------------------------------

def is_svn_directory(directory_name):
	"""Check if the directory in a 'for' statement is in svn"""
	if len(directory_name) == 0:
		return 0
	if (directory_name == "AStyle"
			or directory_name[:7] == "AStyle\\"
			or directory_name[:9] == "AStyleDev"
			or directory_name[:10] == "AStyleTest"
			or directory_name[:9] == "AStyleWeb"):
		return 1
	return 0

# -----------------------------------------------------------------------------

# make the module executable
if __name__ == "__main__":
	if os.name != "nt":
		libastyle.set_text_color()
		print "This test is for Windows only!"
	else:
		process_files()
	libastyle.system_exit()

# -----------------------------------------------------------------------------
