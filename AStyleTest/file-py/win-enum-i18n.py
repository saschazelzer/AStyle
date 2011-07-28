#! /usr/bin/python
# Enumerate selected locales and sort by codepage to determine
# which  languages the locales support.

# to disable the print statement and use the print() function (version 3 format)
from __future__ import print_function

import libastyle		#local directory
import locale
import os
import sys

# -----------------------------------------------------------------------------

def enumerate_locales():
	"""Main processing function.
	"""
	if os.name != "nt":
		libastyle.system_exit("This script is for Windows only!")

	libastyle.set_text_color()
	print (libastyle.get_python_version())
	
	languages = (
			# "chinese",					# returns chinese-simplified
			"chinese-simplified",
			"chinese-traditional",
			"czech",
			"danish",
			"dutch",
			"belgian",
			"english",
			"finnish",
			"french",
			"german",
			"greek",
			"hungarian",
			"icelandic",
			"italian",
			"japanese",
			"korean",
			"norwegian",
			"polish",
			"portuguese",
			"russian",
			"slovak",
			"spanish",
			"swedish",
			"turkish",
			)

	# build list of locale names
	localeNames = []
	for language in languages:
		# print language
		try:
			locale.setlocale(locale.LC_ALL, language)
		except locale.Error:
			print ("unsupported locale: " + language)
		# print locale.getlocale(locale.LC_CTYPE)
		localeName = locale.setlocale(locale.LC_ALL, None)

		localeNames.append( localeName)
	# sort the list of locale names
	# the call changed with version 3
	if sys.version_info[0] < 3:
		localeNames.sort(sort_compare)
	else:
		localeNames.sort(key=get_codepage)
	# print the list of locale names
	previousCodepage = 0
	total1252 = 0
	for localeName in localeNames:
		codepage = get_codepage(localeName)
		if codepage == "1252":
			total1252 += 1
		if codepage != previousCodepage:
			if previousCodepage == "1252":
				print ("1252 TOTAL " + str(total1252))
			print ()
			previousCodepage = codepage
		print (codepage + ' ' + localeName)

# -----------------------------------------------------------------------------

def sort_compare(localeName1, localeName2):
	"""Sort comparison function.
	   Not used by version 3.
	"""
	# get codepage from the locale
	codepage1 = get_codepage(localeName1)
	codepage2 = get_codepage(localeName2)
	# then sort by codepage
	if codepage1 < codepage2:
		return -1
	if codepage1 > codepage2:
		return 1
	# codepage is equal, sort by name
	if localeName1 < localeName2:
		return -1
	return 1

# -----------------------------------------------------------------------------

def get_codepage(localeName):
	"""Extract codepage from the locale name.
	"""
	# extract codepage
	codepageSep = localeName.rfind('.')
	if codepageSep == -1:
		codepage = "0"
	else:
		codepage = localeName[codepageSep+1:]
	# if less than 4 bytes prefix with a zero
	if len(codepage) == 3:
		codepage = '0' + codepage
	return codepage

# -----------------------------------------------------------------------------

# make the module executable
if __name__ == "__main__":
	enumerate_locales()
	libastyle.system_exit()

# -----------------------------------------------------------------------------
