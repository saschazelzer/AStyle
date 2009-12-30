#! /usr/bin/python
# Run the AStyle system test.
# Calls system-test.bat in file-bat to call Artistic Style and checks the results.
# Tests every possible combination of bracket changes.
# Run each bracket type twice to verify there are no changes.
# Run brackets=none afterwards to verify there are no changes
#     and to check for consistency.

import sys
import os

# global variables ------------------------------------------------------------

start = 1	# test number to start with (usually 1)

# select one of the following
project = "CodeBlocks"
# project = "jEdit"
# project = "KDevelop"
# project = "SharpDevelop"

# select one of the following
options = ""
#  indent-brackets (B), add-brackets (j), break-blocks=all (F), align-pointer=type (k1)
# options = "-CSKBNLwM50m10yejoOcFpPHUxEk1"
# indent-blocks (G), add-one-line-brackets (J), break-blocks (f), align-pointer=middle (k2)
# options = "-CSKGNLwM50m10yeJoOcfpPHUxEk2"

# -----------------------------------------------------------------------------

def process_files():
	"""Main processing function."""

	# bracket options and the order they are tested
	brackets = "__aa_bb_ll_gg_aa_ll_bb_gg_bb_aa_gg_ll_aa_"
	
	# call system-test.bat with the requested options
	i, testdata1, testdata2 = set_processing_variables(brackets)
	os.chdir("../file-bat")
	while i < len(brackets):
		print_test_header(brackets, i)
		call_batch_file(testdata1, testdata2, brackets, i)
		i += 1
	print
	print "-----------------------------------------"

# -----------------------------------------------------------------------------

def call_batch_file(testdata1, testdata2, brackets, i):
	"""Call a batch file using the command processor."""
	cmdPath = "C:/Windows/System32/cmd"
	batchId = "system-test.bat"
	prevBracket = '0'
	if i > 0:
		prevBracket = brackets[i-1]
	# args 1-3 to cmd.exe
	args = ["cmd.exe", "/c", batchId]
	# args 4+ to artistic style
	args += [project, brackets[i], prevBracket, testdata1, testdata2, "-vRQ"]
	if len(options) > 0:
		args.append(options)
	os.spawnv(os.P_WAIT, cmdPath, args)
	
# -----------------------------------------------------------------------------

def print_test_header(brackets, i):
	"""Print header information for a test."""
	print
	print "-----------------------------------------"
	print
	print "TEST " + str(i+1) + " OF " + str(len(brackets))
	print brackets
	print brackets[:i+1]

# -----------------------------------------------------------------------------
 
def set_processing_variables(brackets):
	"""Set variables for processing."""
	if project == "CodeBlocks":
		testdata1 = "CodeBlocks/src/*.cpp"
		testdata2 = "CodeBlocks/src/*.h"
	elif project == "jEdit":
		testdata1 = "\jEdit\*.java"
		testdata2 = ""
	elif project == "KDevelop":
		testdata1 = "\kdevelop\*.cpp"
		testdata2 = "\kdevelop\*.h"
	elif project == "SharpDevelop":
		testdata1 = "SharpDevelop\src\*.cs"
		testdata2 = ""
	else:
		sys.exit("Bad project: " + project)
	print "\nTesting {0}".format(project)
	if start < 1: 
		i = 0
	else:
		i = start - 1
	if i > 0:
		print "\nStart with test {0}".format(i+1)
		# if needed decrease by one test
		if brackets[i] == brackets[i-1]:
			i -= 1
			print "Starting with test {0} to avoid diffs".format(i+1) 
	return 	i, testdata1, testdata2
	
# -----------------------------------------------------------------------------	
	
# make the module executable
if __name__ == "__main__":
	process_files()
	# pause if script is not run from SciTE (argv[1] = 'scite')
	if (os.name == "nt"
	and len(sys.argv) == 1):
		os.system("pause")
		# raw_input("\nPress Enter to continue . . .")

# -----------------------------------------------------------------------------
