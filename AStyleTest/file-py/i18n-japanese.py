#! /usr/bin/python
# Run AStyle to test the i18n component for Japanese.
# Tests the input where the GTest programs test only the processing and output.
# The global variables may be changed to the desired values.
# WINDOWS
# The "Region and Language" setting should be set to Japanese. 
# Set both the "Format" and the "Language for non-Unicode programs" (system locale).
# Cannot use AppLocale for this.
# LINUX
# Linux uses UTF-8 locales and requires no system changes.

import libastyle		#local directory
import libextract		#local directory
import libtest			#local directory
import locale
import glob
import os
import shutil
import subprocess
import time

# global variables ------------------------------------------------------------

# Japanese codec - llisted in the documantation under "codecs (module)
if os.name == "nt":
	japanese = "cp932"	
else:
	japanese = "utf_8"
	
# test directory
testpath = "/Projects/AStyleTest/ut-testcon"
testdir = libastyle.get_home_directory() + testpath

# subdirectories are the same as in AStyleTestI18n.cpp
# variables are converted to multi-byte Japanese
subdir1   = u"/アイウオ".encode(japanese)
subdir1a  = u"/アイウオ/カキク".encode(japanese)
subdir1b  = u"/アイウオ/ケコサ".encode(japanese)
subdir2   = u"/スセタチ".encode(japanese)

# formatting options
options = ""

# executable for test
astyleexe = "astyled"

# -----------------------------------------------------------------------------

def process_files():
	"""Main processing function.
	"""
	# initialization
	libastyle.set_text_color()
	verify_locale()
	os.chdir(libastyle.get_file_py_directory())
	libastyle.build_astyle_executable(get_astyle_config())
	print "Cleaning test directory"
	clean_test_directory(testdir)
	# run tests
	test_recursive_1()
	test_recursive_2()
	test_recursive_3()
	test_recursive_exclude()
	test_recursive_suffix()
	#clean_test_directory(testdir)

# -----------------------------------------------------------------------------

def call_artistic_style(astyle, testfile):
	"""Call artistic style.
	"""
	outfile = open(testfile, 'w')
	try:
		subprocess.check_call(astyle, stdout=outfile)
	except subprocess.CalledProcessError as e:
		libastyle.system_exit("Bad astyle return: " + str(e.returncode))
	except OSError:
		libastyle.system_exit("Cannot find executable: " + astyle[0])
	outfile.close()

# -----------------------------------------------------------------------------

def clean_test_directory(testdir):
	"""Find and remove ALL pre-existing files and directories.
	"""
	imax = 2	# max number of retries
	files = glob.glob(testdir)
	for file in files:
		file = file.replace('\\', '/')
		prtfile = libextract.strip_directory_prefix(file)
		# removed the directory - this is a problem with Windows only
		for i in range(0, imax):
			shutil.rmtree(file, True)
			if not os.path.isdir(file): break
			if i == imax - 1:
				print "Directory not removed: " + file
				libastyle.system_exit("Remove the directory manually")
			time.sleep(1)
	# Windows has to wait for the all directories to be removed
	for i in range(0, imax):
		if not os.path.isdir(testdir): break
		time.sleep(1)

# -----------------------------------------------------------------------------

def create_test_files():
	"""Create the directories and files used for testing.
	   These are the same directories and files created in
	   AStyleTestI18n_I18n.
	"""
	prtdir = testdir
	prtdir = prtdir.replace('\\', '/')
	prtdir = libextract.strip_directory_prefix(prtdir)
	# create the test directory
	imax = 2	# max number of retries
	for i in range(0, imax):
		try:
			os.mkdir(testdir)
		except WindowsError:
			print "mkdir WindowsError"	# print a message and retry
		if os.path.isdir(testdir): break
		if i == imax - 1:
			libastyle.system_exit("mkdir WindowsError " + testdir)
		time.sleep(1)
	# create Japanese sub directories
	os.mkdir(testdir + subdir1)
	os.mkdir(testdir + subdir1a)
	os.mkdir(testdir + subdir1b)
	os.mkdir(testdir + subdir2)

	# create the test files
	text = (
		"\nvoid foo()\n"
		"{\n"
		"bar();\n"
		"}\n"
	)
	fileNames = []
	fileNames.append(testdir +  "/recursive1.cpp")
	fileNames.append(testdir + subdir1  + "/recursive2.cpp")
	fileNames.append(testdir + subdir1  + "/recursive3.cpp")
	fileNames.append(testdir + subdir1a + "/recursive4.cpp")
	fileNames.append(testdir + subdir1a + "/recursive5.cpp")
	fileNames.append(testdir + subdir1b + "/recursive6.cpp")
	fileNames.append(testdir + subdir1b + "/recursive7.cpp")
	fileNames.append(testdir + subdir2  + "/recursive8.cpp")
	fileNames.append(testdir + subdir2  + "/recursive9.cpp")
	for file in fileNames:
		outfile = open(file, 'w')
		outfile.write(text)
		outfile.close()
	return fileNames

# -----------------------------------------------------------------------------

def get_astyle_config():
	"""Get the build configuration from the executalbe name.
	"""
	config = libastyle.DEBUG
	if astyleexe.lower() == "astyle":
		config = libastyle.RELEASE
	return config

# -----------------------------------------------------------------------------

def get_astyle_path(astyleexe):
	"""Get the astyle executable path.
	"""
	config = get_astyle_config()
	astylepath = libastyle.get_astyleexe_directory(config, True) + astyleexe
	return astylepath

# -----------------------------------------------------------------------------

def set_astyle_args(filepath, excludes, astyleexe):
	"""Set args for calling artistic style.
	"""
	astylepath = get_astyle_path(astyleexe)
	args = [astylepath]
	# set filepath
	args.append(filepath)
	# set options
	args.append("-vRQ")
	if len(options.strip()) > 0:
		args.append(options)
	# set excludes
	for exclude in excludes:
		args.append(exclude)
	return args

# -----------------------------------------------------------------------------

def test_recursive_1():
	"""Test multi-byte recursive option.
	   This is the same test as Recursive1 in AStyleTestI18n_I18n
	   except this tests the astyle input.
	"""
	print "Running test_recursive_1"
	# create test files
	clean_test_directory(testdir)
	fileNames = create_test_files()
	# run the test
	filepaths = testdir + "/*.cpp"
	excludes = []
	astyle = set_astyle_args(filepaths, excludes, astyleexe)
	testfile = "test1.txt"
	call_artistic_style(astyle, testfile)
	# check the fileName vector
	fileName = libtest.get_formatted_files(testfile)
	if len(fileNames) != len(fileName):
		print "Error 1 in test_recursive_1"
		return
	for i in range(0, len(fileNames)):
		fileName[i] = fileName[i].replace('\\', '/')
		# NOTE: to print the unicode files use "print repr(filename)"
		if fileNames[i] != fileName[i]:
			print "Error 2 in test_recursive_1"
			return

# -----------------------------------------------------------------------------

def test_recursive_2():
	"""Test multi-byte recursive option with a multi-byte directory.
	   This is the same test as Recursive2 in AStyleTestI18n_I18n
	   except this tests the astyle input.
	"""
	print "Running test_recursive_2"
	# create test files
	clean_test_directory(testdir)
	fileNames = create_test_files()
	# delete the entries that are not in the path
	# do not use remove in a "for" loop
	fileNames.remove(testdir +  "/recursive1.cpp")
	fileNames.remove(testdir + subdir2  + "/recursive8.cpp")
	fileNames.remove(testdir + subdir2  + "/recursive9.cpp")
	# run the test
	filepaths = testdir + subdir1 + "/*.cpp"
	excludes = []
	astyle = set_astyle_args(filepaths, excludes, astyleexe)
	testfile = "test2.txt"
	call_artistic_style(astyle, testfile)
	# check the fileName vector
	fileName = libtest.get_formatted_files(testfile)
	if len(fileNames) != len(fileName):
		print "Error 1 in test_recursive_2"
		return
	for i in range(0, len(fileNames)):
		fileName[i] = fileName[i].replace('\\', '/')
		# NOTE: to print the unicode files use "print repr(filename)"
		if fileNames[i] != fileName[i]:
			print "Error 2 in test_recursive_2"
			return

# -----------------------------------------------------------------------------

def test_recursive_3():
	"""Test multi-byte recursive option with a multi-byte filename
	   and extension.
	   This is the same test as Recursive3 in AStyleTestI18n_I18n
	   except this tests the astyle input.
	"""
	print "Running test_recursive_3"
	# create test files
	clean_test_directory(testdir)
	fileNames = create_test_files()
	# write the multi-byte filename and extension
	# create the test files
	text = (
		"\nvoid foo()\n"
		"{\n"
		"bar();\n"
		"}\n"
	)
	# filename and extension converted to multi-byte Japanese
	fileNameJ = u"/ツテヌネ".encode(japanese)
	fileExtJ  = u".ホマ".encode(japanese)
	file = testdir + subdir1  + fileNameJ + fileExtJ;
	outfile = open(file, 'w')
	outfile.write(text)
	outfile.close()
	# run the test
	filepaths = testdir + "/*" + fileExtJ
	excludes = []
	astyle = set_astyle_args(filepaths, excludes, astyleexe)
	testfile = "test3.txt"
	call_artistic_style(astyle, testfile)
	# check the fileName vector
	fileName = libtest.get_formatted_files(testfile)
	if len(fileName)  != 1 :
		print "Error 1 in test_recursive_3"
		return
	fileName[0] = fileName[0].replace('\\', '/')
	# NOTE: to print the unicode files use "print repr(filename)"
	if fileName[0] !=  file:
		print "Error 2 in test_recursive_3"
		return
			
# -----------------------------------------------------------------------------

def test_recursive_exclude():
	"""Test multi-byte recursive option with a multi-byte excludes.
	   This is the same test as RecursiveExclude in AStyleTestI18n_I18n
	   except this tests the astyle input.
	"""
	print "Running test_recursive_exclude"
	# create test files
	clean_test_directory(testdir)
	fileNames = create_test_files()
	# create the excludes
	excludes = []
	# file
	excludes.append("--exclude=recursive1.cpp")
	# directory - subdir1a, 2nd directory
	lastSep = subdir1a.rfind('/')
	if lastSep == -1:
		print "Error in subdir1a.rfind"
	excludes.append("--exclude=" + subdir1a[lastSep:])
	# sub directory
	excludes.append("--exclude=" + subdir1b)
	# full path file
	filePath9 = testdir + subdir2 + "/recursive9.cpp"
	excludes.append("--exclude=" + filePath9)
	# delete the excluded entries
	# do not use remove in a "for" loop
	fileNames.remove(testdir +  "/recursive1.cpp")
	fileNames.remove(testdir + subdir1a  + "/recursive4.cpp")
	fileNames.remove(testdir + subdir1a  + "/recursive5.cpp")
	fileNames.remove(testdir + subdir1b  + "/recursive6.cpp")
	fileNames.remove(testdir + subdir1b  + "/recursive7.cpp")
	fileNames.remove(testdir + subdir2   + "/recursive9.cpp")
	# run the test
	filepaths = testdir + "/*"
	astyle = set_astyle_args(filepaths, excludes, astyleexe)
	testfile = "testex.txt"
	call_artistic_style(astyle, testfile)
	# check the fileName vector
	fileName = libtest.get_formatted_files(testfile)
	if len(fileNames) != len(fileName):
		print "Error 1 in test_recursive_exclude"
		return
	for i in range(0, len(fileNames)):
		fileName[i] = fileName[i].replace('\\', '/')
		if fileNames[i] != fileName[i]:
			print "Error 2 in test_recursive_exclude"
			return
			
# -----------------------------------------------------------------------------

def test_recursive_suffix():
	"""Test multi-byte recursive option with a multi-byte backup suffix.
	   This is the same test as RecursiveSuffix in AStyleTestI18n_I18n
	   except this tests the astyle input.
	"""
	print "Running test_recursive_suffix"
	# create test files
	clean_test_directory(testdir)
	fileNames = create_test_files()
	# create the suffix as an exclude option
	# must encode the Japanese suffix to astyle
	excludes = []
	suffix = u".ラルヰ".encode(japanese)
	excludes.append("--suffix=" + suffix);
	# run the test
	filepaths = testdir + "/*"
	astyle = set_astyle_args(filepaths, excludes, astyleexe)
	testfile = "testsx.txt"
	call_artistic_style(astyle, testfile)
	
	# check the fileName vector
	fileName = libtest.get_formatted_files(testfile)
	if len(fileNames) != len(fileName):
		print "Error 1 in test_recursive_suffix"
		return
	for i in range(0, len(fileNames)):
		fileSuffix =  fileNames[i] + suffix
		if not os.path.isfile(fileSuffix): 
			print "Error 2 in test_recursive_suffix"
			return

# -----------------------------------------------------------------------------

def verify_locale():
	"""For Windows, verifies that the correct locale is set.
	"""
	# only Windows is checked
	lang, codepage = locale.getdefaultlocale()
	if os.name == "nt":
		if lang == "ja_JP":
			print "Testing JAPANESE " + codepage
		else:
			print "LOCALE NOT SET TO JAPANESE: " + lang
	else:
		print "Testing JAPANESE " + codepage

# -----------------------------------------------------------------------------

# make the module executable
if __name__ == "__main__":
	process_files()
	libastyle.system_exit()

# -----------------------------------------------------------------------------
