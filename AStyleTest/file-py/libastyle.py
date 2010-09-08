#! /usr/bin/python
# Library files for AStyle test modules.
# All directories and filepaths should be in this module.
# Executed as stand-alone it will run a series of tests.

import os
import subprocess
import sys

if os.name == "nt": import msvcrt		# Windows only for getch()
else: import termios, tty				# Linux only for getch()

# global variables ------------------------------------------------------------

# test project IDs
CODEBLOCKS   = "CodeBlocks"
CODELITE     = "CodeLite"
DRJAVA       = "DrJava"			# Java
JEDIT        = "jEdit"			# Java
KDEVELOP     = "KDevelop"
MONODEVELOP  = "MonoDevelop"	# C#
SCITE        = "SciTE"
SHARPDEVELOP = "SharpDevelop"	# C#
TESTPROJECT  = "TestProject"

# astyle test options
# NOTE: release 1.25, use after  astyle25b because of min-conditional-indent
# no options
OPT0 = ""
# align-pointer=type (k1), indent-brackets (B), add-brackets (j), break-blocks=all (F)
#     min-conditional-indent=0 (m0)
OPT1 = "-CSKBNLwM50m0yejoOcFpPHUxEk1"
# align-pointer=middle (k2), indent-blocks (G), add-one-line-brackets (J)
#     break-blocks (f), min-conditional-indent=3 (m3)
OPT2 = "-CSKGNLwM60m3yeJoOcfpPHUxEk2"
# align-pointer=name (k3), , min-conditional-indent=1 (m1)
# WITHOUT: indent-blocks (G), add-brackets (j,J),
#     break-blocks (f,F), pad-oper (p), pad-paren (P), delete-empty-lines (x)
OPT3 = "-CSKNLwM80m1yeoOcHUEk3"

# extract options, use True for speed
#SOURCE_ONLY = True
SOURCE_ONLY = False

# compile configurations
DEBUG   = "debug"
RELEASE = "release"
STATIC  = "static"

# Visual Studio release
#VS_RELEASE = "vs2008"
VS_RELEASE = "vs2010"

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
	astylepath = get_astyle_build_directory(config)
	if os.name == "nt":
		compile_astyle_windows(astylepath, config)
	else:
		compile_astyle_linux(astylepath, config)

# -----------------------------------------------------------------------------

def compile_astyle_linux(astylepath, config):
	"""Compile the astyle executable for Linux.
	"""
	if config == DEBUG:
		build = ["make", "debug"]
	else:
		build = ["make", "release"]
	buildfile = get_temp_directory() + "/build.txt"
	outfile = open(buildfile, 'w')
	retval = subprocess.call(build, cwd=astylepath, stdout=outfile)
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
		sdk = "v4.0.30319"
		vsdir = "vs2010"
	# remove the cache file as a precaution
	cachepath = (get_astyle_directory() 
			+ "/build/"
			+ vsdir
			+ "/AStyle.sln.cache")
	if os.path.isfile(cachepath):
		os.remove(cachepath)
	# call MSBuild
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
	slnpath = (get_astyle_directory()
			+ "/build/"
			+ vsdir
			+ "/AStyle.sln")
	platform = "/property:Platform=Win32"  
	msbuild = ([buildpath, configProp, platform, slnpath])
	buildfile = get_temp_directory() + "/build.txt"
	outfile = open(buildfile, 'w')
	retval = subprocess.call(msbuild, stdout=outfile)
	if retval:
		system_exit("Bad msbuild return: " + str(retval))
	outfile.close()
	os.remove(buildfile)

# -----------------------------------------------------------------------------

def get_7zip_path():
	"""Get the 7zip executable path for the os environment.
	"""
	if os.name == "nt":
		# exepath = os.getenv("PROGRAMFILES") + "/7-Zip/7z.exe"
		exepath = "C:/Program Files" + "/7-Zip/7z.exe"
		if not os.path.isfile(exepath):
			message = "Cannot find 7zip path: " + exepath
			system_exit(message)
	else:
		exepath = "7z"
	return exepath

# -----------------------------------------------------------------------------

def get_archive_directory(endsep=False):
	"""Get the archives directory for the os environment.
	   endsep = True will add an ending separator.
	"""
	arcdir = get_project_directory()  + "/TestArchives"
	if not os.path.isdir(arcdir):
		message = "Cannot find archive directory: " + arcdir
		system_exit(message)
	if endsep: arcdir += '/'
	return  arcdir

# -----------------------------------------------------------------------------

def get_astyle_build_directory(config):
	"""Get the AStyle build path for the os environment.
	"""
	if config != DEBUG and config != RELEASE and config != STATIC:
		system_exit("Bad arg in get_astyleexe_directory(): " + config)
	astyledir = get_astyle_directory()
	if os.name == "nt":
		subpath = "/build/" + VS_RELEASE
	else:
		subpath = "/build/gcc"
	astylepath = astyledir + subpath
	if not os.path.isdir(astylepath):
		message = "Cannot find astyle build directory: " + astylepath
		system_exit(message)
	return astylepath

# -----------------------------------------------------------------------------

def get_astyle_directory(endsep=False):
	"""Get the AStyle directory for the os environment.
	   endsep = True will add an ending separator.
	"""
	if endsep != True and endsep != False:
		system_exit("Bad arg in get_astyle_directory(): " + endsep)
	astyledir = get_project_directory() + "/AStyle"
	if not os.path.isdir(astyledir):
		message = "Cannot find astyle directory: " + astyledir
		system_exit(message)
	if endsep: astyledir += '/'
	return astyledir

# -----------------------------------------------------------------------------

def get_astyleexe_directory(config, endsep=False):
	"""Get the AStyle executable directory for the os environment.
	   endsep = True will add an ending separator.
	"""
	if config != DEBUG and config != RELEASE and config != STATIC:
		system_exit("Bad arg in get_astyleexe_directory(): " + config)
	astyledir = get_astyle_directory()
	if os.name == "nt":
		subpath = "/build/" + VS_RELEASE + "/bin"
		if config == DEBUG:
			subpath = subpath.replace("bin", "debug")
		elif  config == STATIC:
			subpath = subpath.replace("bin", "binstatic")
	else:
		subpath = "/build/gcc/bin"
	astylepath = astyledir + subpath
	if not os.path.isdir(astylepath):
		message = "Cannot find astyleexe directory: " + astylepath
		system_exit(message)
	if endsep: astylepath += '/'
	return astylepath

# -----------------------------------------------------------------------------

def get_astyleexe_path(config):
	"""Get the AStyle executable path for the os environment.
	"""
	if config != DEBUG and config != RELEASE and config != STATIC:
		system_exit("Bad arg in get_astyle_path(): " + config)
	astyledir = get_astyleexe_directory(config, True)
	if os.name == "nt":
		if config == DEBUG:
			progname = "AStyled.exe"
		else:
			progname = "AStyle.exe"
		astylepath = astyledir + progname
		if not os.path.isfile(astylepath):
			message = "Cannot find astyleexe path: " + astylepath
			system_exit(message)
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
	# this must be executed from a terminal
	if not is_executed_from_console():
		system_exit("libastyle.getch() must be run from the console")
	# WINDOWS uses msvcrt
	if os.name == "nt":
		# clear buffer
		while msvcrt.kbhit():
			msvcrt.getch()
		# read char
		ch = msvcrt.getch()
		if ch == '\000' or ch == '\xe0':		# function key
			msvcrt.getch()
	# LINUX uses termios and tty
	else:
		# clear buffer
		sys.stdin.flush()
		# read char
		fd = sys.stdin.fileno()
		old_settings = termios.tcgetattr(fd)
		try:
			tty.setraw(sys.stdin.fileno())
			ch = sys.stdin.read(1)
			if ch == '\x1b':			# alt key
				ch = sys.stdin.read(1)
		finally:
			termios.tcsetattr(fd, termios.TCSADRAIN, old_settings)
	print ch
	return ch

# -----------------------------------------------------------------------------

def get_diff_path():
	"""Get the diff executable path for the os environment.
	   endexe = True will add an ending '.exe' to Windows.
	"""
	if os.name == "nt":
		exepath = os.getenv("PROGRAMFILES") + "/WinMerge/WinMergeU.exe"
		if not os.path.isfile(exepath):
			message = "Cannot find diff path: " + exepath
			system_exit(message)
	else:
		exepath = "diffuse"
	return  exepath

# -----------------------------------------------------------------------------

def get_file_py_directory(endsep=False):
	"""Get the file-py directory for the os environment.
	   endsep = True will add an ending separator.
	"""
	# get the path where this file is located
	pydir = sys.path[0]
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
	   Extract the Project directory from path[0]
	   endsep = True will add an ending separator.
	"""
	# get the path where this file is located
	pydir = sys.path[0]
	# get project directory
	testdir, tail = os.path.split(pydir)
	projdir, tail = os.path.split(testdir)
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
		excludes.append("--exclude=wx/wxscintilla.h")
		excludes.append("--exclude=wx/propgrid/advprops.h")
		excludes.append("--exclude=wx/propgrid/manager.h")
		excludes.append("--exclude=wx/propgrid/propgrid.h")
		excludes.append("--exclude=propgrid/propgrid.cpp")
	elif project == CODELITE:
		None
	elif project == DRJAVA:
		None
	elif project == JEDIT:
		None
	elif project == KDEVELOP:
		None  # excludes.append("--exclude=app_templates")
	elif project == MONODEVELOP:
		None 
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
	elif project == DRJAVA:
		filepaths.append(testDirectory + "/DrJava/*.java")
	elif project == JEDIT:
		filepaths.append(testDirectory + "/jEdit/*.java")
	elif project == KDEVELOP:
		filepaths.append(testDirectory + "/KDevelop/*.cpp")
		filepaths.append(testDirectory + "/KDevelop/*.h")
	elif project == MONODEVELOP:
		filepaths.append(testDirectory + "/MonoDevelop/src/*.cs")
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
	testdir = get_project_directory()  + "/TestData"
	if not os.path.isdir(testdir):
		message = "Cannot find test directory: " + testdir
		system_exit(message)
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
			os.system("color 0C")
		else:
			os.system("echo -n '[1;31m'")

# -----------------------------------------------------------------------------

def set_ok_color():
	"""Change text color if script is run from the console.
	"""
	if is_executed_from_console():
		if os.name == "nt":
			os.system("color 0A")
		else:
			os.system("echo -n '[1;32m'")

# -----------------------------------------------------------------------------

def set_text_color():
	"""Change text color if script is run from the console.
	"""
	if is_executed_from_console():
		if os.name == "nt":
			os.system("color 0E")
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
