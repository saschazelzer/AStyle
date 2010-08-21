#! /usr/bin/python
# Enumerate selected locales and sort by codepage to determine 
# which  languages the locales support.

import libastyle		#local directory
import locale
import os

# -----------------------------------------------------------------------------

def enumerate_locales():
	"""Main processing function.
	"""
	if os.name != "nt":
		print "This script is for Windows only"
		return
		
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
		except locale.Error as e:
			print "unsupported locale: " + language
		# print locale.getlocale(locale.LC_CTYPE)
		localeName = locale.setlocale(locale.LC_ALL, None)

		localeNames.append( localeName)
	# sort the list of locale names
	localeNames.sort(sort_compare)
	# print the list of locale names
	previousCodepage = 0
	total1252 = 0
	for localeName in localeNames:
		codepage = get_codepage(localeName)
		if codepage == "1252":
			total1252 += 1
		if codepage != previousCodepage:
			if previousCodepage == "1252":
				print "1252 TOTAL " + str(total1252)
			print          # space
			previousCodepage = codepage
		print codepage + ' ' + localeName

# -----------------------------------------------------------------------------

def sort_compare(localeName1, localeName2):
	"""Sort comparison function.
	"""
	# get codepage from the locale
	codepage1 = get_codepage(localeName1)
	codepage2 = get_codepage(localeName2)
	# sort the smaller length first
	if len(codepage1) < len(codepage2):
		return -1
	if len(codepage1) > len(codepage2):
		return 1
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
	return codepage

# -----------------------------------------------------------------------------

# make the module executable
if __name__ == "__main__":
	enumerate_locales()
	libastyle.system_exit()

# -----------------------------------------------------------------------------
