
// Author: bob
// Created Time: Thu 03 Dec 2020 08:18:58 PM CST

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstdlib>
extern "C"
{
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"
}

// c/c++ ����lua
int c_call_lua()
{
    lua_State* L = luaL_newstate();

    if (L == NULL) return -1;

    int bRet = luaL_loadfile(L, "c-call-lua.lua"); //�޴��󣬷���0
    if (bRet)
    {
        std::cout << "load lua file fail" << std::endl;
        return -2;
    }

    bRet = lua_pcall(L, 0, 0, 0);
    if (bRet)
    {
        std::cout << "pcall lua fail" << std::endl;
        return -3;
    }

    lua_getglobal(L, "str");
    std::string str = lua_tostring(L, -1);
    std::cout << str << std::endl;

    lua_getglobal(L, "tb");
    lua_getfield(L, -1, "name");
    std::string name = lua_tostring(L, -1);
    std::cout << "tb:name = " << name.c_str() << std::endl;
    lua_getfield(L, -2, "id");
    double id = lua_tonumber(L, -1);
    std::cout << "tb:id = " << id << std::endl;

    //���ˣ�ջ�е�����ǣ�  
    //=================== ջ�� ===================   
    //  ����  ����      ֵ       ����
    //   4   double��   2222     -1
    //   3   string��   ssss     -2
    //   2   table:     tb       -3
    //   1   string:   i am bob  -4
    //=================== ջ�� =================== 


    lua_getglobal(L, "add");
    lua_pushnumber(L, 10);
    lua_pushnumber(L, 20);

    //���ˣ�ջ�е�����ǣ�  
    //=================== ջ�� ===================   
    //  ����  ����      ֵ       ����
    //   6   double:    20       -1
    //   5   double:    10       -2
    //   4   double��   2222     -3
    //   3   string��   ssss     -4
    //   2   table:     tb       -5
    //   1   string:   i am bob  -6
    //=================== ջ�� =================== 

    int iRet = lua_pcall(L, 2, 1, 0);
    if (iRet)
    {
        const char* pErr = lua_tostring(L, -1);
        std::cout << pErr << std::endl;
        lua_close(L);
        return -4;
    }

    if (lua_isnumber(L, -1))
    {
        double f = lua_tonumber(L, -1);
        std::cout << "result is " << f << std::endl;
    }

    //���ˣ�ջ�е�����ǣ�  
    //=================== ջ�� ===================   
    //  ����  ����      ֵ           ����
    //   5   double:    30           -1
    //   4   double��   2222         -2
    //   3   string��   ssss         -3
    //   2   table:     tb           -4
    //   1   string:   i am bob      -5
    //=================== ջ�� =================== 

    //�޸�table��Ԫ�ص�ֵ
    lua_pushstring(L, "i am cool");
    lua_setfield(L, 2, "name");         //��ջ��Ԫ�ظ�ֵ�� ջ�е�2λ�õ�table��name�����ƺ󵯳�ջ��

    lua_newtable(L);
    lua_pushstring(L, "table2222");
    lua_setfield(L, -2, "str");
    //���ˣ�ջ�е�����ǣ�  
    //=================== ջ�� ===================   
    //  ����  ����      ֵ           ����
    //   6   table:    {str = "table2222"}           -1
    //   5   double:    30           -2
    //   4   double��   2222         -3
    //   3   string��   ssss         -4
    //   2   table:     tb           -5
    //   1   string:   i am bob      -6
    //=================== ջ�� =================== 

    lua_close(L);
    return 0;
}

static int average(lua_State* L)
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

// lua����c/c++������ ��c++����ִ��lua�ļ�

int lua_call_c()
{
    lua_State* L = luaL_newstate();
    luaL_openlibs(L);
    lua_register(L, "average", average);

    luaL_dofile(L, "lua-call-c.lua");

    lua_close(L);
    return 0;
}

//

int main()
{
    c_call_lua();
    lua_call_c();
    return 0;
}
