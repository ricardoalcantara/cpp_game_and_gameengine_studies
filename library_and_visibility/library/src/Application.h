//
// Created by alcan on 17/04/2020.
//

#ifndef LIBRARY_AND_VISIBILITY_APPLICATION_H
#define LIBRARY_AND_VISIBILITY_APPLICATION_H

#include "Core.h"

class DLLEXPORT Application
{
public:
    void Run();
    virtual void Main() const {};
};

Application* CreateApplication();

#endif //LIBRARY_AND_VISIBILITY_APPLICATION_H
