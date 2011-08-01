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
# Settings shared between the build tree and install tree.


#-----------------------------------------------------------------------------
# Settings specific to the build tree.

# The "use" file.
SET(AStyle_USE_FILE ${AStyle_BINARY_DIR}/UseAStyle.cmake)

# Determine the include directories needed.
SET(AStyle_INCLUDE_DIRS_CONFIG
  ${AStyle_SOURCE_DIR}/src
)

# Build configuration information.
SET(AStyle_CONFIGURATION_TYPES_CONFIG ${CMAKE_CONFIGURATION_TYPES})
SET(AStyle_BUILD_TYPE_CONFIG ${CMAKE_BUILD_TYPE})

#-----------------------------------------------------------------------------
# Configure AStyleConfig.cmake for the build tree.
CONFIGURE_FILE(${AStyle_SOURCE_DIR}/AStyleConfig.cmake.in
               ${AStyle_BINARY_DIR}/AStyleConfig.cmake @ONLY IMMEDIATE)

#-----------------------------------------------------------------------------
# Settings specific to the install tree.

# TODO

#-----------------------------------------------------------------------------
# Configure AStyleConfig.cmake for the install tree.

# TODO
