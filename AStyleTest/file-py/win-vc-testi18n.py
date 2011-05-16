#! /usr/bin/python
# Run the Visual Studio AStyleTestI18n test using AppLocale to test non-ASCII files.

import libastyle		# local directory
import os
import subprocess
import time

# global variables ------------------------------------------------------------
# change the following for the correct VS version
# always uses the debug configuration
testdir = "../build/vs2010"

# -----------------------------------------------------------------------------

def process_files():
	"""Main processing function.
	"""
	# initialization
	libastyle.set_text_color()
	verify_os()
	build_testi18n_executable()

	# for some reason the subprocess call must be one long statement???
	exepath = "C:/Windows/AppPatch/AppLoc.exe"
	i18npath = testdir + "/debug/AStyleTestI18nd.exe"
	terse = "--terse_printer"
	command = exepath + ' ' + i18npath + ' ' + terse + ' '

	# run tests
	print "\nWAIT for a test to finish before running the next"
	print "Reply OK to continue ..."
	print "Running Greek Test"
	subprocess.call(command + "/L0408")
	time.sleep(2)		# must finish before running the next test
	print "Running Japanese Test"
	subprocess.call(command + "/L0411")
	time.sleep(2)		# must finish before running the next test
	print "Running Russian Test"
	subprocess.call(command + "/L0419")
	time.sleep(2)		# must finish before running the next test

# -----------------------------------------------------------------------------

def build_testi18n_executable():
	"""Build the Visual Studio AStyleTestI18n debug executable.
	"""
	print "Building Visual Studio AStyleTestI18n Debug"
	# Compile the astyle executable for Windows.
	sdk = "v3.5"
	vsdir = "vs2008"
	if testdir.find("vs2010") != -1:
		sdk = "v4.0.30319"
		vsdir = "vs2010"
	# remove the cache file as a precaution
	cachepath = (testdir
			+ "/AStyle.sln.cache")
	if os.path.isfile(cachepath):
		os.remove(cachepath)
	# call MSBuild
	buildpath =  (os.getenv("WINDIR")
			+ "/Microsoft.NET/Framework/"
			+ sdk
			+ "/MSBuild.exe")
	configProp = "/property:Configuration=Debug"
	slnpath = (testdir
			+ "/AStyleTestI18n.sln")
	platform = "/property:Platform=Win32"
	msbuild = ([buildpath, configProp, platform, slnpath])
	buildfile = libastyle.get_temp_directory() + "/build.txt"
	outfile = open(buildfile, 'w')
	retval = subprocess.call(msbuild, stdout=outfile)
	if retval:
		libastyle.system_exit("Bad msbuild return: " + str(retval))
	outfile.close()
	os.remove(buildfile)

# -----------------------------------------------------------------------------

def verify_os():
	"""Verify the operating system
	"""
	if os.name != "nt":
		print "This script is for Windows only"
		return

# -----------------------------------------------------------------------------

# make the module executable
if __name__ == "__main__":
	process_files()
	libastyle.system_exit()

# -----------------------------------------------------------------------------
