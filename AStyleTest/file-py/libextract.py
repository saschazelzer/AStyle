#! /usr/bin/python
# Library files for AStyle test modules.
# Extract files in the TestArchives directory to the TestData directory.
# The 7zip program is called to extract the archives.
# The only function called externally is extract_project().
# Executed as stand-alone it will run a series of tests.

import glob
import libastyle		#local directory
import os
import shutil
import subprocess
import sys
import time

# global variables ------------------------------------------------------------

# set by extract_project function
extract_all_files = False

# -----------------------------------------------------------------------------

def extract_project(project, all_files_option):
	"""Call the procedure to extract the requested project.
	   The main processing procedure called by other functions.
	"""
	if all_files_option == True:
		extract_all_files = True
		print "extracting ALL files"
	if project == libastyle.CODEBLOCKS:
		extract_codeblocks()
	elif project == libastyle.DRJAVA:
		extract_drjava()
	elif project == libastyle.JEDIT:
		extract_jedit()
	elif project == libastyle.KDEVELOP:
		extract_kdevelop()
	elif project == libastyle.MONODEVELOP:
		extract_monodevelop()
	elif project == libastyle.SCITE:
		extract_scite()
	elif project == libastyle.SHARPDEVELOP:
		extract_sharpdevelop()
	elif project == libastyle.TESTPROJECT:
		extract_testproject()
	else:
		libastyle.system_exit("Bad extract_files project id: " + str(project))

# -----------------------------------------------------------------------------

def call_7zip(filepath, outdir, fileext):
	"""Call 7zip to extract an archive.
	"""
	filepath = filepath.replace('\\', '/')
	prtfile = strip_directory_prefix(filepath)
	print "extract " + prtfile
	exepath = libastyle.get_7zip_path()
	extract = [exepath, "x", "-ry", "-o" + outdir, filepath]
	if extract_all_files:
		extract.extend(fileext)
	filename = libastyle.get_temp_directory() + "/extract.txt"
	outfile = open(filename, 'w')
	retval = subprocess.call(extract, stdout=outfile)
	if retval:
		libastyle.system_exit("Bad 7zip return: " + str(retval))
	outfile.close()
	os.remove(filename)

# -----------------------------------------------------------------------------

def check_rename_ok(globpath, destination):
	"""Check that there is one and only one matching file.
	   More than one means the old file was not completely removed.
	   The file must be manually removed before continuing.
	   This is a problem on Windows only.
	   Returns the directory path of the one file.
	"""
	dirs = glob.glob(globpath)
	if len(dirs) == 0:
		libastyle.system_exit("No directory to rename")
	if len(dirs) == 1:
		return dirs[0]
	# try to remove the old directory one more time
	for directory in dirs:
		if directory[-len(destination):] == destination:
			print "remove retry"
			shutil.rmtree(directory, True)
	dirs = glob.glob(globpath)
	if len(dirs) > 1:
		libastyle.system_exit(str(dirs) + "\nCannot rename directory")
	return dirs[0]

# -----------------------------------------------------------------------------

def extract_codeblocks():
	"""Extract CodeBlocks files from archive to test directory.
	"""
	remove_test_directory("codeblocks-*")
	remove_test_directory("[Cc]ode[Bb]locks")
	extract_test_tar("codeblocks*.bz2", "codeblocks*.tar", ["*.cpp", "*.h"])
	rename_test_directory("codeblocks-*", "CodeBlocks")

# -----------------------------------------------------------------------------

def extract_drjava():
	"""Extract drjava files from archive to test directory.
	"""
	remove_test_directory("drjava-*")
	remove_test_directory("[Dd]r[Jj]ava")
	extract_test_zip("drjava*.zip", "", ["*.java"])
	rename_test_directory("drjava-*", "DrJava")

# -----------------------------------------------------------------------------

def extract_jedit():
	"""Extract jEdit files from archive to test directory.
	"""
	remove_test_directory("j[Ee]dit")
	remove_test_directory("build-support")
	extract_test_tar("jedit*.bz2", "jedit*.tar", ["*.java"])

# -----------------------------------------------------------------------------

def extract_kdevelop():
	"""Extract KDevelop 3.5.5 files from archive to test directory.
	"""
	remove_test_directory("kdevelop_*")
	remove_test_directory("[Kk][Dd]evelop")
	extract_test_tar("kdevelop*.gz", "hpO5ya*.tar", ["*.cpp", "*.h"])
	rename_test_directory("kdevelop-*", "KDevelop")

# -----------------------------------------------------------------------------

def extract_monodevelop():
	"""Extract MonoDevelop files from archive to test directory.
	"""
	remove_test_directory("monodevelop-*")
	remove_test_directory("[Mm]ono[Dd]evelop")
	extract_test_tar("monodevelop*.bz2", "monodevelop*.tar", ["*.cs"])
	rename_test_directory("monodevelop-*", "MonoDevelop")

# -----------------------------------------------------------------------------

def extract_scite():
	"""Extract SciTE files from archive to test directory.
	"""
	remove_test_directory("[Ss]ci[Tt][Ee]")
	extract_test_zip("scite*.zip", "scite", ["*.cxx","*.c","*.h"])
	# rename for Linux only
	if not os.name == "nt":
		rename_test_directory("scite", "SciTE")

# -----------------------------------------------------------------------------

def extract_sharpdevelop():
	"""Extract SharpDevelop files from archive to test directory.
	"""
	remove_test_directory("[Sh]harp[Dd]evelop")
	extract_test_zip("SharpDevelop*.zip", "SharpDevelop", ["*.cs"])

# -----------------------------------------------------------------------------

def extract_testproject():
	"""Extract Test files from archive to test directory.
	"""
	remove_test_directory("[Ss]ci[Tt][Ee]")
	remove_test_directory("[Tt]est[Pp]roject")
	extract_test_zip("scite*.zip", "scite", ["*.cxx","*.c","*.h"])
	rename_test_directory("scite", "TestProject")

# -----------------------------------------------------------------------------

def extract_test_tar(pattern, tarpattern, fileext):
	"""Extract a tarball given the search pattern.
	   If necessary, the tarball will be extracted first.
	   There must be one and only one matching file.
	   arg 1- search pattern for the compressed file.
	   arg 2- serach pattern for the tarball.
	   arg 3- a list of search patterns for the source files.
	"""
	arcdir = libastyle.get_archive_directory(True)
	testdir = libastyle.get_test_directory(True)
	# check for existing tarball
	files = glob.glob(arcdir + tarpattern)
	if len(files) == 1:
		call_7zip(files[0], testdir, fileext)
		return
	# extract the tarball
	files = glob.glob(arcdir + pattern)
	if len(files) == 0:
		libastyle.system_exit("No file to extract: " + pattern)
	if len(files) > 1:
		libastyle.system_exit(str(files) + "\nToo many files to extract")
	call_7zip(files[0], arcdir, [])
	# extract files from the tarball
	files = glob.glob(arcdir + tarpattern)
	if len(files) == 0:
		libastyle.system_exit("No tarball to extract: " + tarpattern)
	if len(files) > 1:
		libastyle.system_exit(str(files) + "\nToo many tarballs to extract")
	call_7zip(files[0], testdir, fileext)

# -----------------------------------------------------------------------------

def extract_test_zip(pattern, dirname, fileext):
	"""Extract a compressed zip given the search pattern.
	   There must be one and only one matching file.
	   arg 1- search pattern for the compressed file.
	   arg 2- name of the output top-level directory.
	   arg 3- a list of search patterns for the source files.
	"""
	arcdir = libastyle.get_archive_directory(True)
	testdir = libastyle.get_test_directory(True)
	# extract thezip
	files = glob.glob(arcdir + pattern)
	if len(files) == 0:
		libastyle.system_exit("No zip to extract")
	if len(files) > 1:
		libastyle.system_exit(str(files) + "\nToo many zips to extract")
	call_7zip(files[0], testdir + dirname.strip(), fileext)

# -----------------------------------------------------------------------------

def remove_test_directory(pattern):
	"""Find and remove pre-existing directory trees.
	   Also removes intermediate files from an aborted extract.
	"""
	testdir = libastyle.get_test_directory(True)
	files = glob.glob(testdir + pattern)
	for file in files:
		file = file.replace('\\', '/')
		prtfile = strip_directory_prefix(file)
		print "remove " + prtfile
		# removed the directory - this is a problem with Windows only
		imax = 5
		for i in range(0, imax):
			shutil.rmtree(file, True)
			if not os.path.isdir(file): break
			if i == imax - 1:
				libastyle.system_exit("Directory not removed: " + file)
			time.sleep(4)

# -----------------------------------------------------------------------------

def rename_test_directory(source, destination):
	"""Rename a directory in the test directory.
	   There must be one and only one matching directory.
	"""
	testdir = libastyle.get_test_directory(True)
	globpath = testdir + source
	dir = check_rename_ok(globpath, destination)
	dir = dir.replace('\\', '/')
	destpath = testdir + destination
	prtsrc = strip_directory_prefix(dir)
	prtdst = strip_directory_prefix(destpath)
	print "rename {0} {1}".format(prtsrc, prtdst)
	try:
		shutil.move(dir, destpath)
	except WindowsError as e:
		time.sleep(2)
		try:
			shutil.move(dir, destpath)
		except WindowsError as e:
			libastyle.system_exit(e.value)

# -----------------------------------------------------------------------------

def strip_directory_prefix(directory):
	"""Strip the prefix from a directory or file for printing.
	"""
	prefix = libastyle.get_project_directory(True)
	start = len(prefix)
	if start > len(directory): start = 0
	return directory[start:]

# -----------------------------------------------------------------------------

def test_all_compressed():
	"""Test extracts for all compressed files.
	"""
	starttime = time.time()
	print "TEST COMPRESSED\n"
	arcdir = libastyle.get_archive_directory()
	files = glob.glob(arcdir  + "/*.tar")
	for file in files:
		file = file.replace('\\', '/')
		prtfile = strip_directory_prefix(file)
		print "remove tar " + prtfile
		os.remove(file)
	print
	#extract_project(libastyle.CODEBLOCKS, False); print
	#extract_project(libastyle.DRJAVA, False); print
	#extract_project(libastyle.JEDIT, False); print
	#extract_project(libastyle.KDEVELOP, False); print
	#extract_project(libastyle.MONODEVELOP, False); print
	#extract_project(libastyle.SCITE, False); print
	extract_project(libastyle.SHARPDEVELOP, False); print
	extract_project(libastyle.TESTPROJECT, False); print
	stoptime = time.time()
	test_print_time(starttime, stoptime); print

# -----------------------------------------------------------------------------

def test_all_tarballs():
	"""Test extracts for all tarballs.
	    Assumes tarballs are present in the archive.
	"""
	starttime = time.time()
	print "TEST TARBALLS\n"
	extract_project(libastyle.CODEBLOCKS, False); print
	# no tarball for DRJAVA
	extract_project(libastyle.JEDIT, False); print
	extract_project(libastyle.KDEVELOP, False); print
	extract_project(libastyle.MONODEVELOP, False); print
	# no tarball for SCITE
	# no tarball for SHARPDEVELOP
	extract_project(libastyle.TESTPROJECT, False); print
	stoptime = time.time()
	test_print_time(starttime, stoptime)

# -----------------------------------------------------------------------------

def test_print_time(starttime, stoptime):
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
# run tests if executed as stand-alone
if __name__ == "__main__":
	libastyle.set_text_color()
	test_all_compressed()
	test_all_tarballs()
	libastyle.system_exit()

# -----------------------------------------------------------------------------
