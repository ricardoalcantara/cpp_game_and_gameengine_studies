//
// Created by alcan on 17/04/2020.
//

#include "Application.h"

extern Application* CreateApplication();

int main(int, char**) {
    auto app = CreateApplication();
    app->Run();
    delete app;
}
