///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Memory Leak Test
// uses Memory(-Leak) and Exception Trace from
// http://www.codeproject.com/KB/applications/leakfinder.aspx
//

// instantiate leak-finder
#if defined(LEAK_FINDER) && defined(_DEBUG) && defined(_MSC_VER)
// instantiate leak-finder:
#define INIT_LEAK_FINDER
// additional, use the XML-Output-File to analyse with "MemLeakAnalyse.exe"
//#define XML_LEAK_FINDER
#pragma warning(disable: 4100)  // unreferenced formal parameter from LeakFinder.h
#include <cstdio>
#include "LeakFinder.h"
#endif
