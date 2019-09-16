//-------------------------------------------------------------------------------------------------
// Warlock® Application Engine
// Copyright © 2019 Miguel Nischor
//
// File: Source/Platform/Platform.hpp
// Description: Compiler macro detection to configure the engine build system.
//-------------------------------------------------------------------------------------------------
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//-------------------------------------------------------------------------------------------------
#ifndef WARLOCK_PLATFORM_HPP
#define WARLOCK_PLATFORM_HPP

//-------------------------------------------------------------------------------------------------
// Microsoft Visual C++
//-------------------------------------------------------------------------------------------------
#if _MSC_VER
#define WARLOCK_COMPILER_ID 1
#define WARLOCK_COMPILER_STRING "Microsoft Visual C++"
#define WARLOCK_COMPILER_VERSION_SHORT _MSC_VER
#define WARLOCK_COMPILER_VERSION_FULL _MSC_FULL_VER
#define WARLOCK_COMPILER_LANGUAGE_VERSION _MSVC_LANG

#if (WARLOCK_COMPILER_VERSION_SHORT < 1914)
#error "This engine requires Microsoft Visual C++ 19.14 or higher"
#endif

#if (WARLOCK_COMPILER_LANGUAGE_VERSION < 201703L)
#error "This engine requires a compiler with ISO/IEC 14882:2017 support"
#endif

static constexpr auto WCS_COMPILER_ID = WARLOCK_COMPILER_ID;
static constexpr auto WCS_COMPILER_STRING = WARLOCK_COMPILER_STRING;
static constexpr auto WCS_COMPILER_VERSION_SHORT = WARLOCK_COMPILER_VERSION_SHORT;
static constexpr auto WCS_COMPILER_VERSION_FULL = WARLOCK_COMPILER_VERSION_FULL;
static constexpr auto WCS_COMPILER_LANGUAGE_VERSION = WARLOCK_COMPILER_LANGUAGE_VERSION;

//-------------------------------------------------------------------------------------------------
// Compiler size detection
//-------------------------------------------------------------------------------------------------
#define WARLOCK_SIZE_INT sizeof(int)
#define WARLOCK_SIZE_BOOL sizeof(bool)
#define WARLOCK_SIZE_CHAR sizeof(char)
#define WARLOCK_SIZE_LONG sizeof(long)
#define WARLOCK_SIZE_FLOAT sizeof(float)
#define WARLOCK_SIZE_SHORT sizeof(short)
#define WARLOCK_SIZE_DOUBLE sizeof(double)
#define WARLOCK_SIZE_LONG_LONG sizeof(long long)
#define WARLOCK_SIZE_LONG_DOUBLE sizeof(long double)
#define WARLOCK_SIZE_UNSIGNED_INT sizeof(unsigned int)
#define WARLOCK_SIZE_UNSIGNED_CHAR sizeof(unsigned char)
#define WARLOCK_SIZE_UNSIGNED_LONG sizeof(unsigned long)
#define WARLOCK_SIZE_UNSIGNED_SHORT sizeof(unsigned short)
#define WARLOCK_SIZE_UNSIGNED_LONG_LONG sizeof(unsigned long long)

static constexpr auto WCS_SIZE_INT = WARLOCK_SIZE_INT;
static constexpr auto WCS_SIZE_BOOL = WARLOCK_SIZE_BOOL;
static constexpr auto WCS_SIZE_CHAR = WARLOCK_SIZE_CHAR;
static constexpr auto WCS_SIZE_LONG = WARLOCK_SIZE_LONG;
static constexpr auto WCS_SIZE_FLOAT = WARLOCK_SIZE_FLOAT;
static constexpr auto WCS_SIZE_SHORT = WARLOCK_SIZE_SHORT;
static constexpr auto WCS_SIZE_DOUBLE = WARLOCK_SIZE_DOUBLE;
static constexpr auto WCS_SIZE_LONG_LONG = WARLOCK_SIZE_LONG_LONG;
static constexpr auto WCS_SIZE_LONG_DOUBLE = WARLOCK_SIZE_LONG_DOUBLE;
static constexpr auto WCS_SIZE_UNSIGNED_INT = WARLOCK_SIZE_UNSIGNED_INT;
static constexpr auto WCS_SIZE_UNSIGNED_CHAR = WARLOCK_SIZE_UNSIGNED_CHAR;
static constexpr auto WCS_SIZE_UNSIGNED_LONG = WARLOCK_SIZE_UNSIGNED_LONG;
static constexpr auto WCS_SIZE_UNSIGNED_SHORT = WARLOCK_SIZE_UNSIGNED_SHORT;
static constexpr auto WCS_SIZE_UNSIGNED_LONG_LONG = WARLOCK_SIZE_UNSIGNED_LONG_LONG;

//-------------------------------------------------------------------------------------------------
// Target processor architecture detection
//-------------------------------------------------------------------------------------------------
#if (_M_IX86 || __i386__ || _X86_)
#define WARLOCK_ARCHITECTURE_X86 1
#endif // WARLOCK_ARCHITECTURE_X86

#if (_M_AMD64 || __amd64__ || __x86_64__)
#define WARLOCK_ARCHITECTURE_X64 1
#endif // WARLOCK_ARCHITECTURE_X64

#if (_M_ARM || __arm__ || _ARM)
#define WARLOCK_ARCHITECTURE_ARM 1
#endif // WARLOCK_ARCHITECTURE_ARM 1

#if (_M_ARM64 || __aarch64__)
#define WARLOCK_ARCHITECTURE_ARM64 1
#endif // WARLOCK_ARCHITECTURE_ARM64

#if (_M_MIPS || __mips__)
#define WARLOCK_ARCHITECTURE_MIPS 1
#endif // WARLOCK_ARCHITECTURE_MIPS

//-------------------------------------------------------------------------------------------------
// Target build type detection
//-------------------------------------------------------------------------------------------------
#if _DEBUG
#define WARLOCK_BUILD_DEBUG 1
#else
#define WARLOCK_BUILD_RELEASE 1
#endif

//-------------------------------------------------------------------------------------------------
// Target system detection
//-------------------------------------------------------------------------------------------------
#if _WIN16
#error "This engine does not support 16 bit systems"
#endif

#if _WIN32
#define WARLOCK_SYSTEM_WINDOWS_X86 1
#endif // WARLOCK_SYSTEM_WINDOWS_X64

#if _WIN64
#define WARLOCK_SYSTEM_WINDOWS_X64 1
#endif // WARLOCK_SYSTEM_WINDOWS_X64

#if __ANDROID__
#define WARLOCK_SYSTEM_ANDROID 1
#endif // WARLOCK_SYSTEM_ANDROID

#if __FreeBSD__
#define WARLOCK_SYSTEM_FREEBSD 1
#endif // WARLOCK_SYSTEM_FREEBSD

#if __NetBSD__
#define WARLOCK_SYSTEM_NETBSD 1
#endif // WARLOCK_SYSTEM_NETBSD

#if __OpenBSD__
#define WARLOCK_SYSTEM_OPENBSD 1
#endif // WARLOCK_SYSTEM_OPENBSD

#if __CYGWIN__
#define WARLOCK_SYSTEM_CYGWIN 1
#endif // WARLOCK_SYSTEM_CYGWIN

#if (__linux__ && !defined(__ANDROID__))
#define WARLOCK_SYSTEM_LINUX 1
#endif // WARLOCK_SYSTEM_LINUX

//-------------------------------------------------------------------------------------------------
// Import/export macros
//-------------------------------------------------------------------------------------------------
#if WARLOCK_BUILD
    #if (WARLOCK_SYSTEM_WINDOWS_X86 || WARLOCK_SYSTEM_WINDOWS_X64)
        #ifndef WARLOCK_API
        #define WARLOCK_API __declspec(dllexport)
        #endif // WARLOCK_API
    #else
        #ifndef WARLOCK_API
        #define WARLOCK_API
        #endif // WARLOCK_API
    #endif // Microsoft Windows
#else
    #if (WARLOCK_SYSTEM_WINDOWS_X86 || WARLOCK_SYSTEM_WINDOWS_X64)
        #ifndef WARLOCK_API
        #define WARLOCK_API __declspec(dllimport)
        #endif // WARLOCK_API
    #else
        #ifndef WARLOCK_API
        #define WARLOCK_API
        #endif // WARLOCK_API
    #endif // Microsoft Windows
#endif // WARLOCK_BUILD

//-------------------------------------------------------------------------------------------------
// Configuration for Android
//-------------------------------------------------------------------------------------------------
#if WARLOCK_SYSTEM_ANDROID
#include <android/api-level.h>

#if (__ANDROID_API__ < 24)
#error "This engine requires Android NDK with API level 24 or higher"
#endif
#endif // Android

//-------------------------------------------------------------------------------------------------
// Configuration for Microsoft Windows
//-------------------------------------------------------------------------------------------------
#if (WARLOCK_SYSTEM_WINDOWS_X86 || WARLOCK_SYSTEM_WINDOWS_X64)
#include <winsdkver.h>

#if (_WIN32_WINNT_MAXVER < 0x0501)
#error "This engine requires Microsoft Windows XP or higher"
#endif

#ifndef WINVER
#define WINVER WINVER_MAXVER
#endif

#ifndef _WIN32_IE
#define _WIN32_IE _WIN32_IE_MAXVER
#endif

#ifndef _WIN32_WINNT
#define _WIN32_WINNT _WIN32_WINNT_MAXVER
#endif

#ifndef _WIN32_WINDOWS
#define _WIN32_WINDOWS _WIN32_WINDOWS_MAXVER
#endif

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#ifndef _CRT_DEPRECATED_NO_WARNINGS
#define _CRT_DEPRECATED_NO_WARNINGS
#endif

#ifndef _SCL_DEPRECATED_NO_WARNINGS
#define _SCL_DEPRECATED_NO_WARNINGS
#endif

#include <windows.h>
#endif // Microsoft Windows
#endif // Microsoft Visual C++

//-------------------------------------------------------------------------------------------------
// LLVM Clang
//-------------------------------------------------------------------------------------------------
#if __clang__
#define WARLOCK_COMPILER_ID 2
#define WARLOCK_COMPILER_STRING "LLVM Clang"
#define WARLOCK_COMPILER_VERSION_SHORT (__clang_major__ * 10000 + __clang_minor__ * 100)
#define WARLOCK_COMPILER_VERSION_FULL (__clang_major__ * 10000 + __clang_minor__ * 100 + __clang_patchlevel__)
#define WARLOCK_COMPILER_LANGUAGE_VERSION __cplusplus

#if (WARLOCK_COMPILER_VERSION_SHORT < 50000)
#error "This engine requires LLVM Clang 5.0 or higher"
#endif

#if (WARLOCK_COMPILER_LANGUAGE_VERSION < 201703L)
#error "This engine requires a compiler with ISO/IEC 14882:2017 support"
#endif

static constexpr auto WCS_COMPILER_ID = WARLOCK_COMPILER_ID;
static constexpr auto WCS_COMPILER_STRING = WARLOCK_COMPILER_STRING;
static constexpr auto WCS_COMPILER_VERSION_SHORT = WARLOCK_COMPILER_VERSION_SHORT;
static constexpr auto WCS_COMPILER_VERSION_FULL = WARLOCK_COMPILER_VERSION_FULL;
static constexpr auto WCS_COMPILER_LANGUAGE_VERSION = WARLOCK_COMPILER_LANGUAGE_VERSION;

//-------------------------------------------------------------------------------------------------
// Compiler size detection
//-------------------------------------------------------------------------------------------------
#define WARLOCK_SIZE_INT sizeof(int)
#define WARLOCK_SIZE_BOOL sizeof(bool)
#define WARLOCK_SIZE_CHAR sizeof(char)
#define WARLOCK_SIZE_LONG sizeof(long)
#define WARLOCK_SIZE_FLOAT sizeof(float)
#define WARLOCK_SIZE_SHORT sizeof(short)
#define WARLOCK_SIZE_DOUBLE sizeof(double)
#define WARLOCK_SIZE_LONG_LONG sizeof(long long)
#define WARLOCK_SIZE_LONG_DOUBLE sizeof(long double)
#define WARLOCK_SIZE_UNSIGNED_INT sizeof(unsigned int)
#define WARLOCK_SIZE_UNSIGNED_CHAR sizeof(unsigned char)
#define WARLOCK_SIZE_UNSIGNED_LONG sizeof(unsigned long)
#define WARLOCK_SIZE_UNSIGNED_SHORT sizeof(unsigned short)
#define WARLOCK_SIZE_UNSIGNED_LONG_LONG sizeof(unsigned long long)

static constexpr auto WCS_SIZE_INT = WARLOCK_SIZE_INT;
static constexpr auto WCS_SIZE_BOOL = WARLOCK_SIZE_BOOL;
static constexpr auto WCS_SIZE_CHAR = WARLOCK_SIZE_CHAR;
static constexpr auto WCS_SIZE_LONG = WARLOCK_SIZE_LONG;
static constexpr auto WCS_SIZE_FLOAT = WARLOCK_SIZE_FLOAT;
static constexpr auto WCS_SIZE_SHORT = WARLOCK_SIZE_SHORT;
static constexpr auto WCS_SIZE_DOUBLE = WARLOCK_SIZE_DOUBLE;
static constexpr auto WCS_SIZE_LONG_LONG = WARLOCK_SIZE_LONG_LONG;
static constexpr auto WCS_SIZE_LONG_DOUBLE = WARLOCK_SIZE_LONG_DOUBLE;
static constexpr auto WCS_SIZE_UNSIGNED_INT = WARLOCK_SIZE_UNSIGNED_INT;
static constexpr auto WCS_SIZE_UNSIGNED_CHAR = WARLOCK_SIZE_UNSIGNED_CHAR;
static constexpr auto WCS_SIZE_UNSIGNED_LONG = WARLOCK_SIZE_UNSIGNED_LONG;
static constexpr auto WCS_SIZE_UNSIGNED_SHORT = WARLOCK_SIZE_UNSIGNED_SHORT;
static constexpr auto WCS_SIZE_UNSIGNED_LONG_LONG = WARLOCK_SIZE_UNSIGNED_LONG_LONG;

//-------------------------------------------------------------------------------------------------
// Target processor architecture detection
//-------------------------------------------------------------------------------------------------
#if (_M_IX86 || __i386__ || _X86_)
#define WARLOCK_ARCHITECTURE_X86 1
#endif // WARLOCK_ARCHITECTURE_X86

#if (_M_AMD64 || __amd64__ || __x86_64__)
#define WARLOCK_ARCHITECTURE_X64 1
#endif // WARLOCK_ARCHITECTURE_X64

#if (_M_ARM || __arm__ || _ARM)
#define WARLOCK_ARCHITECTURE_ARM 1
#endif // WARLOCK_ARCHITECTURE_ARM 1

#if (_M_ARM64 || __aarch64__)
#define WARLOCK_ARCHITECTURE_ARM64 1
#endif // WARLOCK_ARCHITECTURE_ARM64

#if (_M_MIPS || __mips__)
#define WARLOCK_ARCHITECTURE_MIPS 1
#endif // WARLOCK_ARCHITECTURE_MIPS

//-------------------------------------------------------------------------------------------------
// Target build type detection
//-------------------------------------------------------------------------------------------------
#if _DEBUG
#define WARLOCK_BUILD_DEBUG 1
#else
#define WARLOCK_BUILD_RELEASE 1
#endif

//-------------------------------------------------------------------------------------------------
// Target system detection
//-------------------------------------------------------------------------------------------------
#if _WIN16
#error "This engine does not support 16 bit systems"
#endif

#if _WIN32
#define WARLOCK_SYSTEM_WINDOWS_X86 1
#endif // WARLOCK_SYSTEM_WINDOWS_X64

#if _WIN64
#define WARLOCK_SYSTEM_WINDOWS_X64 1
#endif // WARLOCK_SYSTEM_WINDOWS_X64

#if __ANDROID__
#define WARLOCK_SYSTEM_ANDROID 1
#endif // WARLOCK_SYSTEM_ANDROID

#if __FreeBSD__
#define WARLOCK_SYSTEM_FREEBSD 1
#endif // WARLOCK_SYSTEM_FREEBSD

#if __NetBSD__
#define WARLOCK_SYSTEM_NETBSD 1
#endif // WARLOCK_SYSTEM_NETBSD

#if __OpenBSD__
#define WARLOCK_SYSTEM_OPENBSD 1
#endif // WARLOCK_SYSTEM_OPENBSD

#if __CYGWIN__
#define WARLOCK_SYSTEM_CYGWIN 1
#endif // WARLOCK_SYSTEM_CYGWIN

#if (__linux__ && !defined(__ANDROID__))
#define WARLOCK_SYSTEM_LINUX 1
#endif // WARLOCK_SYSTEM_LINUX

//-------------------------------------------------------------------------------------------------
// Import/export macros
//-------------------------------------------------------------------------------------------------
#if WARLOCK_BUILD
    #if (WARLOCK_SYSTEM_WINDOWS_X86 || WARLOCK_SYSTEM_WINDOWS_X64)
        #ifndef WARLOCK_API
        #define WARLOCK_API __declspec(dllexport)
        #endif // WARLOCK_API
    #else
        #ifndef WARLOCK_API
        #define WARLOCK_API
        #endif // WARLOCK_API
    #endif // Microsoft Windows
#else
    #if (WARLOCK_SYSTEM_WINDOWS_X86 || WARLOCK_SYSTEM_WINDOWS_X64)
        #ifndef WARLOCK_API
        #define WARLOCK_API __declspec(dllimport)
        #endif // WARLOCK_API
    #else
        #ifndef WARLOCK_API
        #define WARLOCK_API
        #endif // WARLOCK_API
    #endif // Microsoft Windows
#endif // WARLOCK_BUILD

//-------------------------------------------------------------------------------------------------
// Configuration for Android
//-------------------------------------------------------------------------------------------------
#if WARLOCK_SYSTEM_ANDROID
#include <android/api-level.h>

#if (__ANDROID_API__ < 24)
#error "This engine requires Android NDK with API level 24 or higher"
#endif
#endif // Android

//-------------------------------------------------------------------------------------------------
// Configuration for Microsoft Windows
//-------------------------------------------------------------------------------------------------
#if (WARLOCK_SYSTEM_WINDOWS_X86 || WARLOCK_SYSTEM_WINDOWS_X64)
#include <winsdkver.h>

#if (_WIN32_WINNT_MAXVER < 0x0501)
#error "This engine requires Microsoft Windows XP or higher"
#endif

#ifndef WINVER
#define WINVER WINVER_MAXVER
#endif

#ifndef _WIN32_IE
#define _WIN32_IE _WIN32_IE_MAXVER
#endif

#ifndef _WIN32_WINNT
#define _WIN32_WINNT _WIN32_WINNT_MAXVER
#endif

#ifndef _WIN32_WINDOWS
#define _WIN32_WINDOWS _WIN32_WINDOWS_MAXVER
#endif

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#ifndef _CRT_DEPRECATED_NO_WARNINGS
#define _CRT_DEPRECATED_NO_WARNINGS
#endif

#ifndef _SCL_DEPRECATED_NO_WARNINGS
#define _SCL_DEPRECATED_NO_WARNINGS
#endif

#include <windows.h>
#endif // Microsoft Windows
#endif // LLVM Clang
#endif // WARLOCK_PLATFORM_HPP
