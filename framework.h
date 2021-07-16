#pragma once

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files
#include <windows.h>
#include <iostream>
#include <string>
#include <fstream>

#include "Class.h"
#include "CustomAPI.h"
#include "Mem.h"
#include "detours.h"

#pragma comment(lib, "detours.lib")
#pragma warning(disable: 6387 26819 6011)