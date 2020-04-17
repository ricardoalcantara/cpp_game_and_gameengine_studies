//
// Created by alcan on 17/04/2020.
//

#ifndef LIBRARY_AND_VISIBILITY_CORE_H
#define LIBRARY_AND_VISIBILITY_CORE_H

// #define DLLEXPORT
#if COMPILING_DLL
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT __declspec(dllimport)
#endif

#endif //LIBRARY_AND_VISIBILITY_CORE_H
