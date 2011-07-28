#! /usr/bin/python
# Use a diff viewer to show diffs in files from the astyle report.

# to disable the print statement and use the print() function (version 3 format)
from __future__ import print_function

import libastyle		#local directory
import libtest			#local directory
import os

# -----------------------------------------------------------------------------

def process_diffs():
	"""Main processing function.
	"""
	libastyle.set_text_color()
	print (libastyle.get_python_version())
	os.chdir(libastyle.get_file_py_directory())
	testfile = "test-diff.txt"
	filepaths = get_diff_files(testfile)
	libtest.diff_formatted_files(filepaths, True)

# -----------------------------------------------------------------------------

def get_diff_files(testfile):
	"""Read the diff testfile and build a list of files with a diff.
	"""
#	infile = libtest.open_filein(testfile, 'rb')		# changed for version 3.2
	infile = libtest.open_filein(testfile, 'r')
	filepaths = []
	for line in infile:
		filepaths.append(line[:-1])
	infile.close()
	return filepaths
	
# -----------------------------------------------------------------------------

# make the module executable
if __name__ == "__main__":
	process_diffs()
	libastyle.system_exit()

# -----------------------------------------------------------------------------
