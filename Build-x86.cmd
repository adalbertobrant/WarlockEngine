@echo off

REM # [1] Build directory creation
mkdir Build\Windows\x86\Release\Object
mkdir Build\Windows\x86\Release\Assembly
mkdir Build\Windows\x86\Release\Log
mkdir Build\Windows\x86\Debug\Object
mkdir Build\Windows\x86\Debug\Assembly
mkdir Build\Windows\x86\Debug\Log

REM # [2] Source file compilation
cl /c /O2 /Ot /Oi /favor:blend /std:c++17 /FaBuild\Windows\x86\Release\Assembly\WarlockEngine.asm /FmBuild\Windows\x86\Release\WarlockEngine.map /FoBuild\Windows\x86\Release\Object\WarlockEngine.obj /nologo /MP2 /showIncludes /TP /utf-8 Source/WarlockEngine.cpp > Build\Windows\x86\Release\Log\Compiler.log
cl /c /Od /Ot /Oi /std:c++17 /FaBuild\Windows\x86\Debug\Assembly\WarlockEngine.asm /FdBuild\Windows\x86\Debug\WarlockEngine.pdb /FmBuild\Windows\x86\Debug\WarlockEngine.map /FoBuild\Windows\x86\Debug\Object\WarlockEngine.obj /nologo /MP2 /showIncludes /TP /utf-8 Source/WarlockEngine.cpp > Build\Windows\x86\Debug\Log\Compiler.log

REM # [3] Resource file compilation
rc /nologo /r /v /c 65001 /d WARLOCK_BUILD Source\WarlockEngine.rc > Build\Windows\x86\Release\Log\Resource.log
copy Build\Windows\x86\Release\Log\Resource.log Build\Windows\x86\Debug\Log\Resource.log
move Source\WarlockEngine.res Build\Windows\x86\Release\Object
copy Build\Windows\x86\Release\Object\WarlockEngine.res Build\Windows\x86\Debug\Object
del Build\Windows\x86\Release\WarlockEngine.res

REM # [4] Dynamic link library creation
link /nologo /DLL /SUBSYSTEM:WINDOWS /VERBOSE Build\Windows\x86\Release\Object\WarlockEngine.res Build\Windows\x86\Release\Object\WarlockEngine.obj /OUT:Build\Windows\x86\Release\WarlockEngine.dll > Build\Windows\x86\Release\Log\Linker.log
link /nologo /DEBUG:FULL /DLL /SUBSYSTEM:WINDOWS /VERBOSE Build\Windows\x86\Debug\Object\WarlockEngine.res Build\Windows\x86\Debug\Object\WarlockEngine.obj /OUT:Build\Windows\x86\Debug\WarlockEngine.dll > Build\Windows\x86\Debug\Log\Linker.log