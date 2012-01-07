/*
 * Copyright (C) 2005 - 2012 MaNGOS <http://www.getmangos.com/>
 *
 * Copyright (C) 2008 - 2012 Trinity <http://www.trinitycore.org/>
 *
 * Copyright (C) 2010 - 2012 ProjectSkyfire <http://www.projectskyfire.org/>
 * 
 * Copyright (C) 2011 ArkCORE <http://www.arkania.net/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#ifndef ARKCORE_DEFINE_H
#define ARKCORE_DEFINE_H

#include <sys/types.h>

#include <ace/Basic_Types.h>
#include <ace/ACE_export.h>

#include "CompilerDefs.h"

#define ARKCORE_LITTLEENDIAN 0
#define ARKCORE_BIGENDIAN    1

#if !defined(ARKCORE_ENDIAN)
#  if defined (ACE_BIG_ENDIAN)
#    define ARKCORE_ENDIAN ARKCORE_BIGENDIAN
#  else //ACE_BYTE_ORDER != ACE_BIG_ENDIAN
#    define ARKCORE_ENDIAN ARKCORE_LITTLEENDIAN
#  endif //ACE_BYTE_ORDER
#endif //ARKCORE_ENDIAN
#if PLATFORM == PLATFORM_WINDOWS
#  define ARKCORE_PATH_MAX MAX_PATH
#  ifndef DECLSPEC_NORETURN
#    define DECLSPEC_NORETURN __declspec(noreturn)
#  endif //DECLSPEC_NORETURN
#else //PLATFORM != PLATFORM_WINDOWS
#  define ARKCORE_PATH_MAX PATH_MAX
#  define DECLSPEC_NORETURN
#endif //PLATFORM
#if !defined(COREDEBUG)
#  define ARKCORE_INLINE inline
#else //COREDEBUG
#  if !defined(ARKCORE_DEBUG)
#    define ARKCORE_DEBUG
#  endif //ARKCORE_DEBUG
#  define ARKCORE_INLINE
#endif //!COREDEBUG
#if COMPILER == COMPILER_GNU
#  define ATTR_NORETURN __attribute__((noreturn))
#  define ATTR_PRINTF(F, V) __attribute__ ((format (printf, F, V)))
#else //COMPILER != COMPILER_GNU
#  define ATTR_NORETURN
#  define ATTR_PRINTF(F, V)
#endif //COMPILER == COMPILER_GNU
typedef ACE_INT64 int64;
typedef ACE_INT32 int32;
typedef ACE_INT16 int16;
typedef ACE_INT8 int8;
typedef ACE_UINT64 uint64;
typedef ACE_UINT32 uint32;
typedef ACE_UINT16 uint16;
typedef ACE_UINT8 uint8;

enum {
	FT_NA = 'x', //not used or unknown, 4 byte size
	FT_NA_BYTE = 'X', //not used or unknown, byte
	FT_STRING = 's', //char*
	FT_FLOAT = 'f', //float
	FT_INT = 'i', //uint32
	FT_BYTE = 'b', //uint8
	FT_SORT = 'd', //sorted by this field, field is not included
	FT_IND = 'n', //the same, but parsed to data
	FT_LOGIC = 'l', //Logical (boolean)
	FT_SQL_PRESENT = 'p', //Used in sql format to mark column present in sql dbc
	FT_SQL_ABSENT = 'a'
//Used in sql format to mark column absent in sql dbc
};

#endif //ARKCORE_DEFINE_H
