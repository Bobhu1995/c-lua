
// Author: bob
// Created Time: Thu 03 Dec 2020 08:18:58 PM CST

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstdlib>
using namespace std;
extern "C"
{
    #include "lua.h"
    #include "lauxlib.h"
    #include "lualib.h"

}

int main(){
    lua_State* L = luaL_newstate();

    lua_pushstring(L, "I am bob.");
    lua_pushnumber(L, 20);
    if (lua_isstring(L, 1))
    {
        std::cout << lua_tostring(L, 1) << std::endl;
    }

    if (lua_isnumber(L, 2))
    {
        std::cout << lua_tonumber(L, 2) << std::endl;                                
    }

    lua_close(L);
    return 0;
}
