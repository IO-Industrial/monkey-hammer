PROJECT("monkey-hammer")
# Monkey Hammer 
#
# Copyright (C) 2023  Joe Turner <joe@agavemountain.com>
#
#  This program is free software: you can redistribute it and/or modify
#  it under the terms of the GNU General Public License as published by
#  the Free Software Foundation, either version 3 of the License, or
#  (at your option) any later version.
#
#     This program is distributed in the hope that it will be useful,
#     but WITHOUT ANY WARRANTY; without even the implied warranty of
#     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#     GNU General Public License for more details.
#
#     You should have received a copy of the GNU General Public License
#     along with this program.  If not, see <https://www.gnu.org/licenses/>.
#
# Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
# SPDX-License-Identifier: GPL-3.0-or-later.
#
cmake_minimum_required (VERSION 3.12)

# FIXME: until automatic versioning is fixed, we hard code:
set(MONKEY_VERSION_MAJOR 0)
set(MONKEY_VERSION_MINOR 0)
set(MONKEY_VERSION_PATCH 0)

get_filename_component(MH_NATIVE_ROOT "${CMAKE_CURRENT_SOURCE_DIR}" ABSOLUTE)

# Add cmake subdirectory to CMAKE_MODULE_PATH CMAKE variable, which 
# contains a list of paths which could be used to search CMAKE 
# modules by "include()" or "find_package()".
# Additionally, we add ${CMAKE_INSTALL_LIBDIR}/cmake and 
# ${CMAKE_PREFIX_PATH}/lib/cmake to search list
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")
set(MH_MODULE_DIR "/${CMAKE_INSTALL_LIBDIR}/cmake")
string(REPLACE ";" "${MH_MODULE_DIR};" MH_MODULE_PATH "${CMAKE_PREFIX_PATH}${MH_MODULE_DIR}")
list(APPEND CMAKE_MODULE_PATH ${MH_MODULE_PATH})

include(colorized_output)

# Try to figure out what project version we are building
include(initialize_project_version)

set (CMAKE_CXX_STANDARD 11)

##############################################################################
# Check to see if this is an out-of-source build or not
##############################################################################
IF(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
	MESSAGE("${Red}Something is wrong... It looks like you are attempting to build${ColourReset}")
	MESSAGE("${Red}in the root directory.  Please don't.${ColourReset}")
    MESSAGE("${Red}Source directory = ${CMAKE_SOURCE_DIR}${ColourReset}")
    MESSAGE("${Red}Binary directory = ${CMAKE_BINARY_DIR}${ColourReset}")
    MESSAGE(FATAL_ERROR "Prevented in-tree build. This is bad practice.${ColourReset}")   
ENDIF(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})

include(external_dependencies)

# Add doxygen make target for source documentation
include(doxygen)
find_package(Sphinx)
include(CTest)
include(CPack)

add_subdirectory(monkey-core)
add_subdirectory(monkey-core-test)
add_subdirectory(monkey-comment)