#! /usr/bin/env python

# Check libSVN.bat to projects.bat to verify all .svn directories are backed up.

import sys
import os

# -----------------------------------------------------------------------------

def process_files():
	"""Read project and libSVN files and check the directories."""
	
	projects_path = "C:\Users\jp\Batch\projects.bat"
	libsvn_path = "C:\Users\jp\Batch\libSVN.bat"
	
	projects_directories = []	# directories in projects.bat
	libsvn_directories = []		# directories in  libSVN.bat 
	
	projects_directories = get_directories(projects_path)
	libsvn_directories = get_directories(libsvn_path)
	
	projects_directories = correct_projects_directories(projects_directories)
	projects_directories.sort()
	libsvn_directories.sort()
	find_diffs(projects_directories, libsvn_directories)

	# print projects_directories
	# print libsvn_directories

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
	projects_directories.append("AStyleTest\\build\\vs2008")
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
	diffs = 0
	i = 0
	j = 0

	print "Checking libSVN.bat directories to projects.bat."
	
	total_variables = len(projects_directories)
	if len(libsvn_directories) > total_variables:
		total_variables = len(libsvn_directories)
	print "There are {0} directories in the list.".format(total_variables)

	while i < len(projects_directories):
		if ( j >= len(libsvn_directories)
		or projects_directories[i] < libsvn_directories[j]):
			print "missing libSVN: " + projects_directories[i]
			diffs += 1
			i += 1
			continue
		if projects_directories[i] > libsvn_directories[j]:
			print "missing projects: " + libsvn_directories[j]
			diffs += 1
			j +=1
			continue
		i += 1
		j += 1
	# get extra libsvn_directories
	while j < len(libsvn_directories):
		print "missing projects: " + libsvn_directories[j]
		diffs += 1
		j += 1
		continue
	if diffs == 0:
		print "There are NO diffs in the directories!!!"
	else:
		print "There are {0} diffs in the directories.".format(diffs)

# -----------------------------------------------------------------------------

def get_directories(file_path):
	"""Read the batch file, find the 'for' statements, and save the directories."""
	
	directories = [] 
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
	return directories

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
	if os.name == "nt":
		process_files()
		# pause if script is not run from SciTE (argv[1] = 'scite')
		if len(sys.argv) == 1:
			raw_input("\nPress Enter to continue . . .")
	else:
		print "This test is for Windows only"

# -----------------------------------------------------------------------------
