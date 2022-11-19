#include "LoadMods.h"
#include "Command.h"
#include "����.h"
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
    AddCommand("help","�鿴����",Command_help);
    AddCommand("about", "���ڸó�������ߺͲ����Ϣ", Command_about);
    AddCommand("plugins", "�鿴�����������Ϣ", Command_Plugins);
    AddCommand("clear", "��տ���̨", Command_cls);
    AddCommand("config", "�����ļ�", Command_config);
    AddCommand("quit", "�˳�����", Command_exit);
}