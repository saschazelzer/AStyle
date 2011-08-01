###########################################################################
#
# Copyright (c) German Cancer Research Center,
#   Division of Medical and Biological Informatics
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.commontk.org/LICENSE
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
###########################################################################

#-----------------------------------------------------------------------------
# See http://cmake.org/cmake/help/cmake-2-8-docs.html#section_Policies for details
#

set(project_policies
  CMP0001 # NEW: CMAKE_BACKWARDS_COMPATIBILITY should no longer be used.
  CMP0002 # NEW: Logical target names must be globally unique.
  CMP0003 # NEW: Libraries linked via full path no longer produce linker search paths.
  CMP0004 # NEW: Libraries linked may NOT have leading or trailing whitespace.
  CMP0005 # NEW: Preprocessor definition values are now escaped automatically.
  CMP0006 # NEW: Installing MACOSX_BUNDLE targets requires a BUNDLE DESTINATION.
  CMP0007 # NEW: List command no longer ignores empty elements.
  CMP0008 # NEW: Libraries linked by full-path must have a valid library file name.
  CMP0009 # NEW: FILE GLOB_RECURSE calls should not follow symlinks by default.
  CMP0010 # NEW: Bad variable reference syntax is an error.
  CMP0011 # NEW: Included scripts do automatic cmake_policy PUSH and POP.
  CMP0012 # NEW: if() recognizes numbers and boolean constants.
  CMP0013 # NEW: Duplicate binary directories are not allowed.
  CMP0014 # NEW: Input directories must have CMakeLists.txt
  )
foreach(policy ${project_policies})
  if(POLICY ${policy})
    cmake_policy(SET ${policy} NEW)
  endif()
endforeach()

#-----------------------------------------------------------------------------
project(AStyle)
#-----------------------------------------------------------------------------

set(LIB_NAME astyle)

#-----------------------------------------------------------------------------
# Library type - Statically built
#
set(BUILD_SHARED_LIBS FALSE)

#-----------------------------------------------------------------------------
# Output directories.
#
set(output_dir ${AStyle_BINARY_DIR}/bin)
foreach(type LIBRARY RUNTIME ARCHIVE)
  if(NOT DEFINED CMAKE_${type}_OUTPUT_DIRECTORY)
    set(CMAKE_${type}_OUTPUT_DIRECTORY ${output_dir} CACHE INTERNAL "Single output directory for building all libraries.")
  endif()
endforeach()

#-----------------------------------------------------------------------------
# Update C/CXX Flags
#
set(CMAKE_CXX_FLAGS "-DASTYLE_LIB -fPIC ${CMAKE_CXX_FLAGS}")

#-----------------------------------------------------------------------------
# Sources

file(GLOB SRC_FILES
  src/*.cpp
  src/*.h
  )
    
#-----------------------------------------------------------------------------
# Build the library

add_library(${LIB_NAME} ${SRC_FILES})

#-----------------------------------------------------------------------------
# Generate AStyleConfig file
#
configure_file(UseAStyle.cmake.in
               ${AStyle_BINARY_DIR}/UseAStyle.cmake COPYONLY)

include(GenerateAStyleConfig.cmake)


#-----------------------------------------------------------------------------
# Install rules

#file(GLOB InstallHeaders
#     "${CMAKE_CURRENT_SOURCE_DIR}/src/*.h"
#     )
#install(FILES ${InstallHeaders}
#        DESTINATION include/log4qt/${dir} COMPONENT Development )

#install(TARGETS ${LIB_NAME} DESTINATION lib COMPONENT Development )
