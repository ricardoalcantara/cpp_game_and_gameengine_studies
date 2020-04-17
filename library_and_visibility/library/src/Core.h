//
// Created by alcan on 17/04/2020.
//

#ifndef LIBRARY_AND_VISIBILITY_CORE_H
#define LIBRARY_AND_VISIBILITY_CORE_H

#if defined(_MSC_VER)
    // #define DLLEXPORT
    #if COMPILING_DLL
    #define DLLEXPORT __declspec(dllexport)
    #else
    #define DLLEXPORT __declspec(dllimport)
    #endif
#elif defined(__GNUC__)
    //  GCC
    #if COMPILING_DLL
    #define DLLEXPORT  __attribute__((visibility("default")))
    #else
    #define DLLEXPORT
    #endif
#else
    //  do nothing and hope for the best?
    #define DLLEXPORT
    #pragma warning Unknown dynamic link import/export semantics.
#endif

#endif //LIBRARY_AND_VISIBILITY_CORE_H
