#include <iostream>
#include <vector>
#include <stdlib.h>
#include "Plugins.h"
#include "Command.h"
#include "Main.h"
#pragma warning(disable:4996)
using namespace std;
extern vector<string> GetCommand;
void Command_help()
{
    cout << endl;
    cout << "\":\"前为命令名 后面为命令说明" << endl;
    cout << endl;
    cout << "命令帮助:" << endl;
    for (size_t i = 0; i < CommandList.size(); i++)
    {
        cout << CommandList[i] << ":" << CommandHelp[i] << endl;
    }
}

void Command_exit()
{
    exit(0);
}

void Command_config()
{
    cout << "暂时没想到这里能加什么..." << endl;
}

void Command_about()
{
    cout << endl;
    cout << "作者信息" << endl;
    cout << "该程序作者为:[BIG SHOT]" << endl;
    cout << "作者QQ号:1613****64" << endl;
    cout << endl;
    cout << "程序信息" << endl;
    cout << "程序名称:ModLoader" << endl;
    cout << "程序版本号:v" << Version.a << "." << Version.b << "." << Version.c << endl;
    cout << "编译版本号:" << Version.d << endl;
    if (Pluginsshuliang == 0)
    {
        return;
    }
    cout << endl;
    cout << "插件信息:" << endl;
    for (size_t i = 0; i < PluginsMessage.size(); i++)
    {
        cout << i + 1 << ":" << endl;
        cout << "插件名:" << PluginsMessage[i] << endl;
        cout << "插件说明:" << PluginsMessage_1[i] << endl;
        cout << "插件版本:" << PluginsVersion[i] << endl;
        cout << endl;
    }
    return;
}

void Command_cls()
{
    system("cls");
}

void Command_Load()
{
    if (GetCommand.size() < 2)
    {
        cout << "Load:参数2错误" << endl;
        return;
    }
    if (GetCommand[1] == "")
    {
        cout << "Load:参数2错误" << endl;
        return;
    }
    if (LoadDll(GetCommand[0].c_str()) == NULL)
    {
        cout << "插件:\"" << GetCommand[1] << "\"加载失败" << endl;
    }
    else
    {
        cout << "插件加载成功" << endl;
        Pluginsshuliang++;
    }
}

void Command_Plugins()
{
    if (GetCommand.size() >= 2)
    {
        for (size_t i = 0; i < PluginsMessage.size(); i++)
        {
            if (GetCommand[1] == PluginsMessage[i])
            {
                cout << "插件名:" << PluginsMessage[i] << endl;
                cout << "插件说明:" << PluginsMessage_1[i] << endl;
                cout << "插件版本:" << PluginsVersion[i] << endl;
                return;
            }
        }
        cout << "未找到该插件信息" << endl;
        return;
    }
    Commandmods = true;
    cout << "已加载" << Pluginsshuliang << "个插件" << endl;
}