# c-lua

# linux

cd lua-cmake

cmake .

make

cd ../c-lua/

cmake .

make


#windows

直接打开c-lua.sln直接运行

如果要改变目录结构，三个需要改动的点

1.选择C/C+±-常规–附加包含目录–选择lua源码目录的src文件夹。	$(SolutionDir)..\src\

2.选择链接器–常规–附加库目录–选择Lua库文件目录，这个目录为我们下载Lua源码后解压的那个目录。	$(SolutionDir)..\

3.选择链接器–输入–附加依赖项–输入我们所编译的lua-5.4.2.lib库文件名称。	lua-5.4.2.lib