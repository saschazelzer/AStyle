#! /usr/bin/python
# Library files for AStyle test modules.
# All directories and filepaths should be in this module.
# Executed as stand-alone it will run a series of tests.

import os
import subprocess
import sys

# global variables ------------------------------------------------------------

# test projects
CODEBLOCKS = 0
CODELITE = 1
JEDIT = 2
KDEVELOP = 3
SHARPDEVELOP  = 4
TEST = 5

# compile configurations
DEBUG = 0
RELEASE = 1

# change the following to the desired configuration
config = DEBUG

# -----------------------------------------------------------------------------

def build_astyle_executable():
	"""Build the astyle executable.
	"""
	if config == DEBUG:
		print "Building AStyle Debug"
	else:
		print "Building AStyle Release"
	astylepath = get_astyle_path()
	if os.name == "nt":
		# must have the extension for this
		if not astylepath.endswith(".exe"):
			astylepath += ".exe"
		compile_astyle_windows(astylepath)
	else:
		compile_astyle_linux(astylepath)

# -----------------------------------------------------------------------------

def compile_astyle_linux(astylepath):
	"""Compile the astyle executable for Linux.
	"""
	savedir = os.getcwd()
	# get makefile directory
	sep = astylepath.find("bin")
	if sep == -1:
		message = "Cannot find bin directory: " + filepath
		system_exit(message)
	os.chdir(astylepath[:sep])
	if config == DEBUG:
		build = ["make", "debug"]
	else:
		build = ["make", "release"]
	buildfile = savedir  + "/build.txt"
	outfile = open(buildfile, 'w')
	retval = subprocess.call(build, stdout=outfile)
	if retval:
		system_exit("Bad build return: " + str(retval))
	outfile.close()
	os.remove(buildfile)
	os.chdir(savedir)

# -----------------------------------------------------------------------------

def compile_astyle_windows(astylepath):
	"""Compile the astyle executable for Windows.
	"""
	sdk = "v3.5"
	vsdir = "vs2008"
	if astylepath.find("vs2010") != -1:
		sdk = "v4.0.21006"
		vsdir = "vs2010"
	buildpath =  (os.getenv("WINDIR")
			+ "/Microsoft.NET/Framework/"
			+ sdk
			+ "/MSBuild.exe")
	if config == DEBUG:
		configProp = "/property:Configuration=Debug"
	else:
		configProp = "/property:Configuration=Release"
	slnpath = (get_home_directory()
			+ "/Projects/AStyle/build/"
			+ vsdir
			+ "/AStyle.sln")
	msbuild = ([buildpath, configProp, slnpath])
	buildfile = "build.txt"
	outfile = open(buildfile, 'w')
	retval = subprocess.call(msbuild, stdout=outfile)
	if retval:
		system_exit("Bad msbuild return: " + str(retval))
	outfile.close()
	os.remove(buildfile)

# -----------------------------------------------------------------------------

def get_7zip_path(endexe=False):
	"""Get the 7zip executable path for the os environment.
	   endexe = True will add an ending '.exe' to Windows.
	"""
	if os.name == "nt":
		exepath = os.getenv("PROGRAMFILES") + "/7-Zip/7z"
		if endexe: exepath += ".exe"
	else:
		exepath = "7z"
	return exepath

# -----------------------------------------------------------------------------

def get_archive_directory(endsep=False):
	"""Get the archives directory for the os environment.
	   endsep = True will add an ending separator.
	"""
	arcdir = get_home_directory()  + "/Projects/TestArchives"
	if endsep: arcdir += '/'
	return  arcdir

# -----------------------------------------------------------------------------

def get_astyle_directory(endsep=False):
	"""Get the AStyle directory for the os environment.
	   endsep = True will add an ending separator.
	"""
	homedir = get_home_directory()
	if os.name == "nt":
		subpath = "/Projects/AStyle/build/vs2008/bin"
		if config == DEBUG:
			subpath = subpath.replace("bin", "debug")
	else:
		subpath = "/Projects/AStyle/build/gcc/bin"
	astylepath = homedir + subpath
	if endsep: astylepath += '/'
	return astylepath

# -----------------------------------------------------------------------------

def get_astyle_path(endexe=False):
	"""Get the AStyle executable path for the os environment
	   endexe = True will add an ending '.exe' to Windows.
	"""
	astyledir = get_astyle_directory(True)
	if os.name == "nt":
		if config == DEBUG: 
			progname = "AStyled"
		else:
			progname = "AStyle"
		if endexe: progname += ".exe"
	else:
		if config == DEBUG:
			progname = "astyled"
		else:
			progname = "astyle"
	astylepath = astyledir + progname
	return astylepath

# -----------------------------------------------------------------------------

def get_diff_path(endexe=False):
	"""Get the diff executable path for the os environment.
	   endexe = True will add an ending '.exe' to Windows.
	"""
	if os.name == "nt":
		exepath = os.getenv("PROGRAMFILES") + "/WinMerge/WinMergeU"
		if endexe: exepath += ".exe"
	else:
		exepath = "diffuse"
	return  exepath

# -----------------------------------------------------------------------------

def get_file_py_directory(endsep=False):
	"""Get the file-py directory for the os environment.
	   endsep = True will add an ending separator.
	"""
	pydir = get_home_directory() + "/Projects/AStyleTest/file-py"
	if endsep: pydir += '/'
	return  pydir

# -----------------------------------------------------------------------------

def get_home_directory(endsep=False):
	"""Get the home directory for the os environment.
	   endsep = True will add an ending separator.
	"""
	if os.name == "nt":
		homedir =  os.getenv("USERPROFILE")
		homedir = homedir.replace('\\', '/')
	else:
		homedir = os.getenv("HOME")
	if endsep: homedir += '/'
	return  homedir

# -----------------------------------------------------------------------------

def get_project_directory(endsep=False):
	"""Get the Project directory for the os environment.
	   endsep = True will add an ending separator.
	"""
	projdir = get_home_directory(True)  + "Projects"
	if endsep: projdir += '/'
	return  projdir

# -----------------------------------------------------------------------------

def get_project_filepaths(project):
	"""Get filepath list for AStyle processing.
	    Argument must be one of the global variables.
	    Returns a list of filepaths to process.
	"""
	filepaths = []
	testDirectory = get_home_directory()  + "/Projects/TestData"
	if project == CODEBLOCKS:
		filepaths.append(testDirectory + "/CodeBlocks/src/*.cpp")
		# filepath.append(testDirectory + "/CodeBlocks/src/*.cxx")
		filepaths.append(testDirectory + "/CodeBlocks/src/*.cpp")
	elif project == CODELITE:
		filepaths.append(testDirectory + "/CodeLite/*.cpp")
		filepaths.append(testDirectory + "/CodeLite/*.cxx")
		filepaths.append(testDirectory + "/CodeLite/*.h")
	elif project == JEDIT:
		filepaths.append(testDirectory + "/jEdit/*.java")
	elif project == KDEVELOP:
		filepaths.append(testDirectory + "/KDevelop/*.cpp")
		filepaths.append(testDirectory + "/KDevelop/*.h")
	elif project == SHARPDEVELOP:
		filepaths.append(testDirectory + "/SharpDevelop/src/*.cs")
	elif project == TEST:
		# the test file paths can be changed depending n the circumstances
		# if the test is not CodeBlocks change in extract_project() libextract.py
		filepaths.append(testDirectory + "/CodeBlocks/src/plugins/astyle/astyle/*.cpp")
		filepaths.append(testDirectory + "/CodeBlocks/src/plugins/codecompletion/parser/*.cpp")
	else:
		system_exit("Bad get_project_filepaths() project id: " + project)
	return filepaths

# -----------------------------------------------------------------------------

def get_project_name(project):
	"""Get the project name.
	   Argument must be one of the global variables.
	   Returns the project name.
	"""
	if project == CODEBLOCKS:
		return "CodeBlocks"
	elif project == CODELITE:
		return "CodeLite"
	elif project == JEDIT:
		return "jEdit"
	elif project == KDEVELOP:
		return "KDevelop"
	elif project == SHARPDEVELOP:
		return "SharpDevelop"
	elif project == TEST:
		return "TestProject"
	else:
		system_exit("Bad get_project_name() project id: " + project)

# -----------------------------------------------------------------------------

def get_test_directory(endsep=False):
	"""Get the test directory for the os environment.
	   endsep = True will add an ending separator.
	"""
	testdir = get_home_directory()  + "/Projects/TestData"
	if endsep: testdir += '/'
	return  testdir

# -----------------------------------------------------------------------------

def is_executed_from_console():
	"""Check if this run is from a console or from SciTE.
	   If run from SciTE the first arg will be 'scite'.
	"""
	if (len(sys.argv) > 1 
	and sys.argv[1].lower() == "scite"):
		return False
	return True
		
# -----------------------------------------------------------------------------

def set_error_color():
	"""Change text color if script is run from the console.
	"""
	if is_executed_from_console():
		if os.name == "nt":
			os.system("color 0C");
		else:
			os.system("echo -n '[1;31m'")

# -----------------------------------------------------------------------------

def set_ok_color():
	"""Change text color if script is run from the console.
	"""
	if is_executed_from_console():
		if os.name == "nt":
			os.system("color 0A");
		else:
			os.system("echo -n '[1;32m'")

# -----------------------------------------------------------------------------

def set_text_color():
	"""Change text color if script is run from the console.
	"""
	if is_executed_from_console():
		if os.name == "nt":
			os.system("color 0E");
		else:
			os.system("echo -n '[1;33m'")

# -----------------------------------------------------------------------------

def system_exit(message):
	"""Accept keyboard input to assure a message is noticed.
	"""
	if len(message.strip()) > 0:
		libastyle.set_error_color()
		print message
	# pause if script is run from the console
	if is_executed_from_console():
		if os.name == "nt":
			os.system("pause");
		else:
			raw_input("Press Enter to end . . .\n")
	sys.exit()

# -----------------------------------------------------------------------------

def test_all_functions():
	"""Test all functions for syntax.
	"""
	build_astyle_executable()		# calls compile_astyle_linux() or ..._windows()
	get_7zip_path()
	get_archive_directory()
	get_astyle_directory()
	get_astyle_path()
	get_diff_path()
	get_file_py_directory()
	get_home_directory()
	get_project_directory()
	get_project_filepaths(SHARPDEVELOP)
	get_project_name(SHARPDEVELOP)
	get_test_directory()
	is_executed_from_console()
	set_error_color()
	set_ok_color()
	set_text_color()

# -----------------------------------------------------------------------------

# make the module executable
# run tests if executed as stand-alone
if __name__ == "__main__":
	set_text_color()
	test_all_functions()
	system_exit("")
