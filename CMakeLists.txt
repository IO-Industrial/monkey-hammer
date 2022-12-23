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
PROJECT("monkey-hammer")
cmake_minimum_required (VERSION 3.12)

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

#message("CMAKE_MODULE_PATH = ${CMAKE_MODULE_PATH}")
include("colorized_output")


