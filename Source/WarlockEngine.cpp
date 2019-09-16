//-------------------------------------------------------------------------------------------------
// Warlock® Application Engine
// Copyright © 2019 Miguel Nischor
//
// File: Source/WarlockEngine.cpp
// Description: Entry point function for the compiled shared library.
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
#include "Platform/Platform.hpp"

#if (WARLOCK_SYSTEM_WINDOWS_X86 || WARLOCK_SYSTEM_WINDOWS_X64)
int WINAPI DllMain(HINSTANCE Instance, DWORD Reason, LPVOID Reserved)
{
    switch (Reason)
    {
        case DLL_PROCESS_ATTACH:
            DisableThreadLibraryCalls(Instance);
            break;

        case DLL_PROCESS_DETACH:
            break;

        case DLL_THREAD_ATTACH:
            break;

        case DLL_THREAD_DETACH:
            break;
    };

    return 0;
};
#endif // Microsoft Windows