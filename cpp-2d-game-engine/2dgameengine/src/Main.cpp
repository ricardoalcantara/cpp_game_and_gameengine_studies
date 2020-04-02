#include <iostream>
#include "Constants.h"
#include "Game.h"

#define SOL_ALL_SAFETIES_ON 1
// #include <lua.hpp>

#include <sol/sol.hpp>

int main()
{
    // LUA https://www.lua.org/
    // lua_State *state = luaL_newstate();
    // luaL_dostring(state, "a = 7 + 11");
    // lua_getglobal(state, "a");
    // LUA_NUMBER a = lua_tonumber(state, -1);
    // std::cout << "a = " << a << std::endl;
    // lua_close(state);

    // SOL https://sol2.readthedocs.io/en/latest/
    sol::state lua;
    int x = 0;
    lua.set_function("beep", [&x] { ++x; });
    lua.script("beep()");
    std::cout << "x = " << x << std::endl;

    sol::function beep = lua["beep"];
    beep();
    std::cout << "x = " << x << std::endl;

    // Game
    Game *game = new Game();

    game->Initialize(WINDOW_WIDTH, WINDOW_HEIGHT);

    while (game->IsRunning())
    {
        game->ProcessInput();
        game->Update();
        game->Render();
    }

    game->Destroy();

    return 0;
}
