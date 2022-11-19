#include "LoadMods.h"
#include "Command.h"
#include "命令.h"
using namespace std;
void AddCommand_a::Addcommand(const char Command_Name[], const char Command_Help[], void(*func)())
{
    Command_Name_c = Command_Name;
    CommandList.push_back(Command_Name);
    CommandHelp.push_back(Command_Help);
    func_c = func;
}

void AddCommand_a::StartCommand()
{
    if (GetCommand[0] != Command_Name_c)
    {
        return;
    }
    (*func_c)();
}

void AddCommand_a::RunCommand(vector<string>& GetCommand_a)
{
    if (GetCommand_a[0] != Command_Name_c)
    {
        return;
    }
    (*func_c)();
}

void Plugins_Message(const char Plugins_Message[], const char Plugins_Message1[], const char Version[]) {
    PluginsMessage.push_back(Plugins_Message);
    PluginsMessage_1.push_back(Plugins_Message1);
    PluginsVersion.push_back(Version);
}

void AddCommand(const char Command_Name[], const char Command_Help[], void(*func)())
{
    AddCommand_a temp;
    temp.Addcommand(Command_Name, Command_Help, (*func));
    Command_class.push_back(temp);
}

void MyCommand() {
    AddCommand("help","查看帮助",Command_help);
    AddCommand("about", "关于该程序的作者和插件信息", Command_about);
    AddCommand("plugins", "查看插件数量和信息", Command_Plugins);
    AddCommand("clear", "清空控制台", Command_cls);
    AddCommand("config", "配置文件", Command_config);
    AddCommand("quit", "退出程序", Command_exit);
}