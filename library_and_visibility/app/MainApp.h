//
// Created by alcan on 17/04/2020.
//

#ifndef LIBRARY_AND_VISIBILITY_MAINAPP_H
#define LIBRARY_AND_VISIBILITY_MAINAPP_H

#include "library.h"

class MainApp: public Application
{
public:
    void Main() const override
    {
        say_hello();
        Logger logger;
        logger.SayHello();
    }
};

Application* CreateApplication()
{
    return new MainApp();
}

#endif //LIBRARY_AND_VISIBILITY_MAINAPP_H
