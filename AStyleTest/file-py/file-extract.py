#! /usr/bin/python
# Calls libextract to extract files in the TestArchives directory.
# Change the global variables to the desired values.

import libastyle		#local directory
import libextract		#local directory
import os
import sys
import time

# global variables ------------------------------------------------------------

# select one of the following from libastyle
#   CODEBLOCKS
#   CODELITE
#   JEDIT
#   KDEVELOP
#  SHARPDEVELOP
# TEST
project = libastyle.TEST

# -----------------------------------------------------------------------------

def extract_project():
	"""Call the library procedure to extract the requested project.
	"""
	starttime = time.time()
	libextract.extract_project(project)
	stoptime = time.time()
	print_run_time(starttime, stoptime)

# -----------------------------------------------------------------------------

def system_exit(message):
	"""Accept keyboard input to assure a message is noticed.
	"""
	if len(message.strip()) > 0:
		libastyle.set_error_color()
		print message
	# pause if script is run from the console
	if libastyle.is_executed_from_console():
		if os.name == "nt":
			os.system("pause");
		else:
			raw_input("Press Enter to end . . .\n")
	sys.exit()

# -----------------------------------------------------------------------------

def print_run_time(starttime, stoptime):
	"""Print run time for the test.
	"""
	runtime = int(stoptime - starttime + 0.5)
	min = runtime / 60
	sec = runtime % 60
	if min == 0:
		print "{0} seconds".format(sec)
	else:
		print "{0} min {1} seconds".format(min, sec)

# -----------------------------------------------------------------------------

# make the module executable
if __name__ == "__main__":
	libastyle.set_text_color()
	extract_project()
	system_exit("")

# -----------------------------------------------------------------------------
