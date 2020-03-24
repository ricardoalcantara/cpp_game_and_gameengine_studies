#include <iostream>
#include "Constants.h"
#include "Game.h"

#ifdef LUA_ENABLED
#include <lua.hpp>
#endif
int main()
{
#ifdef LUA_ENABLED
    lua_State *state = luaL_newstate();
    luaL_dostring(state, "a = 7 + 11");
    lua_getglobal(state, "a");
    LUA_NUMBER a = lua_tonumber(state, -1);
    std::cout << "a = " << a << std::endl;
    lua_close(state);
#endif

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
