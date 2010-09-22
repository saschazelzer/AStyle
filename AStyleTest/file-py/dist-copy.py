#! /usr/bin/python
# Create the distribution files for Artistic Style.

import glob
import libastyle		#local directory
import os
import shutil
import subprocess
import sys

# global variables ------------------------------------------------------------

# release number for distribution file
release = "2.01"
# inut from AStyle directory
astyleDir = libastyle.get_astyle_directory()
# output to AStyle directory
baseDir =  libastyle.get_astyle_directory() 

# -----------------------------------------------------------------------------

def create_distributions():
	"""Main processing function.
	"""
	libastyle.set_text_color()
	os.chdir(libastyle.get_file_py_directory())
	remove_dist_directories()
	build_linux_distribution()
	build_mac_distribution()
	build_vms_distribution()
	build_windows_distribution()

# -----------------------------------------------------------------------------

def build_linux_distribution():
	"""Copy astyle files to the linux directory.
	"""
	print
	print "* * * * * * * * * * * * * * * * * * * * * * * * * * * * *"
	print "*              Copying Linux Distribution               *"
	print "* * * * * * * * * * * * * * * * * * * * * * * * * * * * *"
	distBase = baseDir + "/DistLinux"
	distAStyle = distBase + "/astyle"
	os.makedirs(distAStyle)

	# doc directory
	distDoc = distAStyle + "/doc/"
	os.mkdir(distDoc)
	copy_astyle_doc(distDoc)

	# src directory
	distSrc = distAStyle +  "/src/"
	os.mkdir(distSrc)
	copy_astyle_src(distSrc)

	# build/gcc directory
	astyleBuildGcc = astyleDir + "/build/gcc/"
	distBuildGcc = distAStyle +  "/build/gcc/"
	os.makedirs(distBuildGcc)
	shutil.copy(astyleBuildGcc + "/Makefile", distBuildGcc)
	print "build/gcc copied"

	# build/intel directory
	astyleBuildIntel = astyleDir + "/build/intel/"
	distBuildIntel = distAStyle +  "/build/intel/"
	os.makedirs(distBuildIntel)
	shutil.copy(astyleBuildIntel + "/Makefile", distBuildIntel)
	shutil.copy(astyleBuildIntel + "/make.sh", distBuildIntel)
	print "build/intel copied"

	# create tar.bz2
	tarname = "astyle_{0}_linux.tar".format(release)
	call_7zip(distBase, tarname)
	bz2name = tarname + ".gz"
	call_7zip(distBase, bz2name)
	

# -----------------------------------------------------------------------------

def build_mac_distribution():
	"""Copy astyle files to the mac directory.
	"""
	print
	print "* * * * * * * * * * * * * * * * * * * * * * * * * * * * *"
	print "*               Copying Mac Distribution                *"
	print "* * * * * * * * * * * * * * * * * * * * * * * * * * * * *"
	distBase = baseDir + "/DistMac"
	distAStyle = distBase + "/astyle"
	os.makedirs(distAStyle)

	# doc directory
	distDoc = distAStyle + "/doc/"
	os.mkdir(distDoc)
	copy_astyle_doc(distDoc)

	# src directory
	distSrc = distAStyle +  "/src/"
	os.mkdir(distSrc)
	copy_astyle_src(distSrc)

	# build/mac directory
	astyleBuildMac = astyleDir + "/build/mac/"
	distBuildMac = distAStyle +  "/build/mac/"
	os.makedirs(distBuildMac)
	shutil.copy(astyleBuildMac + "/Makefile", distBuildMac)
	print "build/mac copied"
	
	# create tar.gz
	tarname = "astyle_{0}_macosx.tar".format(release)
	call_7zip(distBase, tarname)
	gzname = tarname + ".gz"
	call_7zip(distBase, gzname)

# -----------------------------------------------------------------------------

def build_vms_distribution():
	"""Copy astyle files to the open vms directory.
	"""
	print
	print "* * * * * * * * * * * * * * * * * * * * * * * * * * * * *"
	print "*             Copying OpenVMS Distribution              *"
	print "* * * * * * * * * * * * * * * * * * * * * * * * * * * * *"
	distBase = baseDir + "/DistVMS"
	distAStyle = distBase + "/astyle"
	os.makedirs(distAStyle)

	# doc directory
	distDoc = distAStyle + "/doc/"
	os.mkdir(distDoc)
	copy_astyle_doc(distDoc)

	# src directory
	distSrc = distAStyle +  "/src/"
	os.mkdir(distSrc)
	copy_astyle_src(distSrc)

	# build/mac directory
	astyleBuildVms = astyleDir + "/build/vms/"
	distBuildVms = distAStyle + "/build/vms/"
	os.makedirs(distBuildVms)
	for file in ("descrip.mms",
			     "java.opt",
			     "lib.opt",
			     "vmsbuild.com"):
		shutil.copy(astyleBuildVms + file, distBuildVms)
	print "build/vms copied"

	# create zip
	zipfile = "astyle_{0}_openvms.zip".format(release)
	call_7zip(distBase, zipfile)

# -----------------------------------------------------------------------------

def build_windows_distribution():
	"""Copy astyle files to the windows directory.
	"""
	# windows files are not available on linux
	if os.name != "nt":
		return
	print
	print "* * * * * * * * * * * * * * * * * * * * * * * * * * * * *"
	print "*             Copying Windows Distribution              *"
	print "* * * * * * * * * * * * * * * * * * * * * * * * * * * * *"
	distBase = baseDir + "/DistWindows"
	distAStyle = distBase + "/AStyle"
	os.makedirs(distAStyle)

	# Windows includes an executable in the bin directory
	libastyle.build_astyle_executable(libastyle.STATIC)
	distAStyleBin = distAStyle +  "/bin/"
	os.mkdir(distAStyleBin)
	astyle_build_directory = libastyle.get_astyle_build_directory(libastyle.STATIC)
	shutil.copy(astyle_build_directory + "/binstatic/AStyle.exe", distAStyleBin)
	vsi = astyle_build_directory.find("vs20")
	if vsi != -1:
		vsdir = astyle_build_directory[vsi:vsi+6]
	print "exe copied ({0})".format(vsdir)
	
	# doc directory
	distDoc = distAStyle + "/doc/"
	os.mkdir(distDoc)
	copy_astyle_doc(distDoc, True)

	# src directory
	distSrc = distAStyle +  "/src/"
	os.mkdir(distSrc)
	copy_astyle_src(distSrc, True)

	# build directory
	astyleBuildDir = astyleDir + "/build"
	distAStyleBuild = distAStyle +  "/build"
	os.mkdir(distAStyleBuild)
	# copy_vs2003_directory(astyleBuildDir, distAStyleBuild)
	copy_vs20xx_directories(astyleBuildDir, distAStyleBuild)
	
	# create zip
	zipfile = "AStyle_{0}_windows.zip".format(release)
	call_7zip(distBase, zipfile)

# -----------------------------------------------------------------------------

def call_7zip(distBase, compressedFile):
	"""Call 7zip to create an archive.
	   arg 1- the directory to compress.
	   arg 2- name of the compressed file.	  
	"""
	exepath = libastyle.get_7zip_path()
	compress = [exepath, "a", compressedFile]
	# check file ending to see if it is a tarball
	if compressedFile.endswith((".gz", ".bz2")):
		compress.append("*.tar")
	# stdout file must have full path since 'cwd' is used in call
	filename = libastyle.get_file_py_directory(True) + "compress.txt"
	outfile = open(filename, 'w')
	retval = subprocess.call(compress, cwd=distBase, stdout=outfile)
	if retval:
		libastyle.system_exit("Bad 7zip return: "  + str(retval))
	outfile.close()
	os.remove(filename)
	print compressedFile + " created"

# -----------------------------------------------------------------------------

def convert_line_ends(distDir, toDos):
	"""Convert line ends to dos (CRLF) or linux (LF).
	   All files in a directory are converted
	"""
	files = glob.glob(distDir + "*")
	if os.name == "nt":
		exedir = "C:/Programs/tofrodos/"
		if toDos: call_list = [exedir + "todos"] + files
		else:     call_list = [exedir + "fromdos"] + files
	else:
		if toDos: call_list = ["todos"] + files
		else:     call_list = ["fromdos"] + files

	# call the conversion program
	retval = subprocess.call(call_list)
	if retval:
		libastyle.system_exit("Bad tofro return: " + str(retval))
	
# -----------------------------------------------------------------------------

def copy_astyle_doc(distDoc, toDos=False):
	"""Copy astyle doc directory to a distribution directory.
	"""
	docfiles = glob.glob(astyleDir + "/doc/*")
	for filepath in docfiles:
		shutil.copy(filepath, distDoc)
	convert_line_ends(distDoc, toDos)
	# verify copy - had a problem with bad filenames
	distfiles = (glob.glob(distDoc + "/*.html") 
					+ glob.glob(distDoc + "/*.css"))
	if len(distfiles) != len(docfiles):
		libastyle.system_exit("Error copying doc: " + str(len(distfiles)))
	print "doc copied"
	
# -----------------------------------------------------------------------------

def copy_astyle_src(distSrc, toDos=False):
	"""Copy astyle src directory to a distribution directory.
	"""
	srcfiles = glob.glob(astyleDir + "/src/*")
	for srcpath in srcfiles:
		shutil.copy(srcpath, distSrc)
	convert_line_ends(distSrc, toDos)
	# verify copy - had a problem with bad filenames
	distfiles = (glob.glob(distSrc + "/*.cpp") 
					+ glob.glob(distSrc + "/*.h"))
	if len(distfiles) != len(srcfiles):
		libastyle.system_exit("Error copying src: " + str(len(distfiles)))
	print "src copied"

# -----------------------------------------------------------------------------

#~ def copy_vs2003_directory(astyleBuildDir, distAStyleBuild):
	#~ """Copy the build/vs2003 directory to the distribution directory.
	#~ """
	#~ distAStyleVS2003 = distAStyleBuild +  "/vs2003/"
	#~ os.mkdir(distAStyleVS2003)
	#~ shutil.copy(astyleBuildDir + "/vs2003/AStyle.sln", distAStyleVS2003)
	#~ shutil.copy(astyleBuildDir + "/vs2003/AStyle.vcproj", distAStyleVS2003)
	#~ print "build/vs2003 copied"

# -----------------------------------------------------------------------------

def copy_vs20xx_directories(astyleBuildDir, distAStyleBuild):
	"""Copy the build/vs20xx directories to the distribution directory.
	"""
	for vsdir in ("/vs2005/",
				  "/vs2008/",
				  "/vs2010/"):

		# copy solution files
		distAStyleVS20xx = distAStyleBuild + vsdir
		os.mkdir(distAStyleVS20xx)
		slnfiles = glob.glob(astyleBuildDir + vsdir + "*.sln")
		for sln in slnfiles:
			shutil.copy(sln, distAStyleVS20xx)

		# build project directories
		for projdir in ("/AStyle/",
					    "/AStyleDll/",
					    "/AStyleJava/",
					    "/AStyleLib/"):
			distAStyleProj = distAStyleVS20xx[:-1] + projdir
			os.mkdir(distAStyleProj)

			# copy project files
			projfiles = glob.glob(astyleBuildDir + vsdir[:-1] + projdir + "*.*proj")
			for proj in projfiles:
				shutil.copy(proj, distAStyleProj)
			if vsdir[1:-1] >= "vs2010":
				filtfiles = glob.glob(astyleBuildDir + vsdir[:-1] + projdir + "*.*.filters")
				for filter in filtfiles:
					shutil.copy(filter, distAStyleProj)

		print "build/" + vsdir[1:-1] + " copied"
		
# -----------------------------------------------------------------------------

def remove_dist_directories():
	"""Remove directories from a previous run.
	"""
	dirs = glob.glob(baseDir + "/[Dd]ist*/")
	for directory in dirs:
		directory = directory.replace('\\', '/')
		print "remove " + directory
		shutil.rmtree(directory, True)
		# this is a problem with Windows only
		if os.path.isdir(directory):
			libastyle.system_exit("Directory not removed: " + directory)

# -----------------------------------------------------------------------------

# make the module executable
if __name__ == "__main__":
	create_distributions()
	libastyle.system_exit()

# -----------------------------------------------------------------------------
