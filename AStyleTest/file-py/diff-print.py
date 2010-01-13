#! /usr/bin/python
# Use a diff viewer to show diffs in files from the astyle report.

import libastyle		#local directory
import libtest			#local directory
import os
import sys

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

def system_exit(message):
	"""Accept keyboard input to assure a message is noticed.
	"""
	if len(message.strip()) > 0:
		libastyle.set_error_color()
		print message
	# pause if script is not run from SciTE (argv[1] = 'scite')
	if libastyle.is_executed_from_console():
		if os.name == "nt":
			os.system("pause");
		else:
			raw_input("Press Enter to end . . .\n")
	sys.exit()

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
	system_exit("")

# -----------------------------------------------------------------------------
