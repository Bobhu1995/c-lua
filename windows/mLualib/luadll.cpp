#include <stdio.h>
#include "luadll.h"

static int averageFunc(lua_State* L)
{
    int n = lua_gettop(L);
    double sum = 0;
    int i;

    for (i = 1; i <= n; ++i)
    {
        sum += lua_tonumber(L, i);
    }

    lua_pushnumber(L, sum / n);
    lua_pushnumber(L, sum);

    return 2;
}

static int sayHelloFunc(lua_State* L)
{
    printf("hello lua!");
    return 0;
}

static const struct luaL_Reg myLib[] = 
{
    {"average", averageFunc},
    {"sayHello", sayHelloFunc},
    {NULL, NULL}       //���������һ�Ա�����{NULL, NULL}��������ʾ����      
};

int luaopen_mLualib(lua_State* L)
{
    // luaL_requiref(L, "dll", luaopen_mLualib, 0);
    luaL_newlib(L, myLib);
    return 1;       // ��myLib��ѹ����ջ�У����Ծ���Ҫ����1  
}