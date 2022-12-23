/**
 *  @file: Version.h
 *
 *  Copyright (C) 2018  Joe Turner <joe@agavemountain.com>
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *     This program is distributed in the hope that it will be useful,
 *     but WITHOUT ANY WARRANTY; without even the implied warranty of
 *     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *     GNU General Public License for more details.
 *
 *     You should have received a copy of the GNU General Public License
 *     along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */
#pragma once
#include <monkey/core/core_exports.h>

namespace Monkey
{
//! \brief Software versions
namespace Version
{
	//! \brief Get library version string
	//! \returns
	//!		library version as a string
	MKY_CORE_API const char* GetVersionString();

	//! \brief Get compiler version string
	//! \returns
	//! 	returns compiler version string
	MKY_CORE_API const char* GetCompilerVersionString();

} //namespace Version
} //namespace Monkey
