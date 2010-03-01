#! /usr/bin/python
# Library files for AStyle test modules.
# All directories and filepaths should be in this module.
# Executed as stand-alone it will run a series of tests.

import os
import subprocess
import sys

if os.name == "nt": import msvcrt		# Windows only for getch()
else: import tty, termios						# Linux only for getch()

# global variables ------------------------------------------------------------

# test project IDs
CODEBLOCKS   = "CodeBlocks"
CODELITE     = "CodeLite"
JEDIT        = "jEdit"
KDEVELOP     = "KDevelop"
SCITE        = "SciTE"
SHARPDEVELOP = "SharpDevelop"
TESTPROJECT  = "TestProject"

# astyle test options
# no options
OPT1 = ""
# align-pointer=type (k1), indent-brackets (B), add-brackets (j), break-blocks=all (F)
OPT2 = "-CSKBNLwM50m10yejoOcFpPHUxEk1"
# align-pointer=middle (k2), indent-blocks (G), add-one-line-brackets (J), break-blocks (f)
OPT3 = "-CSKGNLwM50m10yeJoOcfpPHUxEk2"
# align-pointer=name (k3), WITHOUT: indent-blocks (G), add-brackets (j,J),
#     break-blocks (f,F), pad-oper (p), pad-paren (P), delete-empty-lines (x)
OPT4 = "-CSKNLwM50m10yeoOcHUEk3"

# compile configurations
DEBUG   = "debug"
RELEASE = "release"
STATIC  = "static"

# -----------------------------------------------------------------------------

def build_astyle_executable(config):
	"""Build the astyle executable.
	"""
	if config == DEBUG:
		print "Building AStyle Debug"
	elif config == RELEASE:
		print "Building AStyle Release"
	elif config == STATIC and os.name == "nt":
		print "Building AStyle Static"
	else:
		system_exit("Bad arg in build_astyle_executable(): " + config)
	astylepath = get_astyleexe_path(config)
	if os.name == "nt":
		# must have the extension for this
		if not astylepath.endswith(".exe"):
			astylepath += ".exe"
		compile_astyle_windows(astylepath, config)
	else:
		compile_astyle_linux(astylepath, config)

# -----------------------------------------------------------------------------

def compile_astyle_linux(astylepath, config):
	"""Compile the astyle executable for Linux.
	"""
	# get makefile directory
	sep = astylepath.find("bin")
	if sep == -1:
		message = "Cannot find bin directory: " + filepath
		system_exit(message)
	makedir = astylepath[:sep]
	if config == DEBUG:
		build = ["make", "debug"]
	else:
		build = ["make", "release"]
	buildfile = get_temp_directory() + "/build.txt"
	outfile = open(buildfile, 'w')
	retval = subprocess.call(build, cwd=makedir, stdout=outfile)
	if retval:
		system_exit("Bad build return: " + str(retval))
	outfile.close()
	os.remove(buildfile)

# -----------------------------------------------------------------------------

def compile_astyle_windows(astylepath, config):
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
	elif config == STATIC:
		configProp = "/property:Configuration=Static"
	else:
		configProp = "/property:Configuration=Release"
	slnpath = (get_home_directory()
			+ "/Projects/AStyle/build/"
			+ vsdir
			+ "/AStyle.sln")
	msbuild = ([buildpath, configProp, slnpath])
	buildfile = get_temp_directory() + "/build.txt"
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
	if endsep != True and endsep != False:
		system_exit("Bad arg in get_astyle_directory(): " + endsep)
	astyledir = get_home_directory() + "/Projects/AStyle"
	if endsep: astyledir += '/'
	return astyledir

# -----------------------------------------------------------------------------

def get_astyleexe_directory(config, endsep=False):
	"""Get the AStyle executable directory for the os environment.
	   endsep = True will add an ending separator.
	"""
	if config != DEBUG and config != RELEASE and config != STATIC:
		system_exit("Bad arg in get_astyleexe_directory(): " + config)
	homedir = get_astyle_directory()
	if os.name == "nt":
		subpath = "/build/vs2008/bin"
		if config == DEBUG:
			subpath = subpath.replace("bin", "debug")
		elif  config == STATIC:
			subpath = subpath.replace("bin", "binstatic")
	else:
		subpath = "/build/gcc/bin"
	astylepath = homedir + subpath
	if endsep: astylepath += '/'
	return astylepath

# -----------------------------------------------------------------------------

def get_astyleexe_path(config, endexe=False):
	"""Get the AStyle executable path for the os environment.
	   endexe = True will add an ending '.exe' to Windows.
	"""
	if config != DEBUG and config != RELEASE and config != STATIC:
		system_exit("Bad arg in get_astyle_path(): " + config)
	astyledir = get_astyleexe_directory(config, True)
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

def getch():
	"""getch() for Windows and Linux.
	   This won't work unless run from a terminal.
	"""
	if os.name == "nt":
		ch = msvcrt.getch()
	else:
		fd = sys.stdin.fileno()
		old_settings = termios.tcgetattr(fd)
		try:
			tty.setraw(sys.stdin.fileno())
			ch = sys.stdin.read(1)
		finally:
			termios.tcsetattr(fd, termios.TCSADRAIN, old_settings)
	print ch
	return ch

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

def get_project_excludes(project):
	"""Get the project excludes list for AStyle processing.
	    Argument must be one of the global variables.
	    Returns a list of excludes.
	"""
	excludes = []
	testDirectory = get_test_directory()
	if project == CODEBLOCKS:
		# excludes because of %pythoncode
		# advprops.h is __WXPYTHON__ at line 192
		# propgrid.cpp is the macro IMPLEMENT_GET_VALUE		
		excludes.append("--exclude=wx\wxscintilla.h")
		excludes.append("--exclude=wx\propgrid\advprops.h")
		excludes.append("--exclude=wx\propgrid\manager.h")
		excludes.append("--exclude=wx\propgrid\propgrid.h")
		excludes.append("--exclude=propgrid\propgrid.cpp")
	elif project == CODELITE:
		None
	elif project == JEDIT:
		None
	elif project == KDEVELOP:
		excludes.append("--exclude=app_templates")
	elif project == SCITE:
		excludes.append("--exclude=lua")
	elif project == SHARPDEVELOP:
		None
	elif project == TESTPROJECT:
		None
	else:
		system_exit("Bad get_project_excludes() project id: " + project)
	return excludes

# -----------------------------------------------------------------------------

def get_project_filepaths(project):
	"""Get filepath list for AStyle processing.
	    Argument must be one of the global variables.
	    Returns a list of filepaths to process.
	"""
	filepaths = []
	testDirectory = get_test_directory()
	if project == CODEBLOCKS:
		filepaths.append(testDirectory + "/CodeBlocks/src/*.cpp")
		# filepath.append(testDirectory + "/CodeBlocks/src/*.cxx")
		filepaths.append(testDirectory + "/CodeBlocks/src/*.h")
	elif project == CODELITE:
		filepaths.append(testDirectory + "/CodeLite/*.cpp")
		filepaths.append(testDirectory + "/CodeLite/*.cxx")
		filepaths.append(testDirectory + "/CodeLite/*.h")
	elif project == JEDIT:
		filepaths.append(testDirectory + "/jEdit/*.java")
	elif project == KDEVELOP:
		filepaths.append(testDirectory + "/KDevelop/*.cpp")
		filepaths.append(testDirectory + "/KDevelop/*.h")
	elif project == SCITE:
		filepaths.append(testDirectory + "/SciTE/*.cxx")
		filepaths.append(testDirectory + "/SciTE/*.h")
	elif project == SHARPDEVELOP:
		filepaths.append(testDirectory + "/SharpDevelop/src/*.cs")
	elif project == TESTPROJECT:
		# the test file paths can be changed depending n the circumstances
		# if the test is not CodeBlocks change extract_testproject() in libextract.py
		filepaths.append(testDirectory + "/TestProject/scite/gtk/*.cxx")
		filepaths.append(testDirectory + "/TestProject/scite/gtk/*.h")
	else:
		system_exit("Bad get_project_filepaths() project id: " + project)
	return filepaths

# -----------------------------------------------------------------------------

def get_temp_directory(endsep=False):
	"""Get the temporary directory for the os environment.
	   endsep = True will add an ending separator.
	"""
	if os.name == "nt":
		tempdir =  os.getenv("TEMP")
		tempdir = tempdir.replace('\\', '/')
	else:
		tempdir = "/tmp"
	if endsep: tempdir += '/'
	return  tempdir

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

def system_exit(message=''):
	"""Accept keyboard input to assure a message is noticed.
	"""
	if len(message.strip()) > 0:
		set_error_color()
		print message
	# pause if script is run from the console
	if is_executed_from_console():
		print "\nPress any key to end . . ."
		getch()
	sys.exit()

# -----------------------------------------------------------------------------

def test_all_functions():
	"""Test all functions for syntax.
	"""
	build_astyle_executable(DEBUG)		# calls compile_astyle_linux() or ..._windows()
	get_7zip_path()
	get_archive_directory()
	get_astyle_directory()
	get_astyleexe_directory(DEBUG)
	get_astyleexe_path(DEBUG)
	get_diff_path()
	get_file_py_directory()
	get_home_directory()
	get_project_directory()
	get_project_excludes(TESTPROJECT)
	get_project_filepaths(TESTPROJECT)
	get_temp_directory()
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
	system_exit()
