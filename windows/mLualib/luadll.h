#pragma once
extern "C"
{
    #include "lua.h"
    #include "lualib.h"
    #include "lauxlib.h"
}

#ifdef LUA_EXPORTS
#define LUA_API __declspec(dllexport)
#else
#define LUA_API __declspec(dllimport)  

#endif // LUA_EXPORTS


extern "C" LUA_API int luaopen_mLualib(lua_State * L);