#! /usr/bin/python
# Use a diff viewer to show diffs in files from the astyle report.

import libastyle		#local directory
import libtest			#local directory
import os
import sys

# -----------------------------------------------------------------------------

def process_diffs():
	"""Main processing function.
	"""
	libastyle.set_text_color()
	os.chdir(libastyle.get_file_py_directory())
	testfile = "test.txt"
	formatted, unchanged, min, sec = libtest.get_astyle_totals(testfile)
	files = libtest.get_formatted_files(testfile)
	verify_formatted_files(len(files), formatted)
	libtest.diff_formatted_files(files, formatted)

# -----------------------------------------------------------------------------

def verify_formatted_files(numformat, totformat):
	"""Check that the formatted files list equals the astyle report total.
	"""
	if totformat != numformat:
		message = "files != report ({0},{1})".format(numformat, totformat)
		system_exit(message)

# -----------------------------------------------------------------------------

# make the module executable
if __name__ == "__main__":
	process_diffs()
	libastyle.system_exit()

# -----------------------------------------------------------------------------
