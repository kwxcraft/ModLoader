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
    cout << "\":\"ǰΪ������ ����Ϊ����˵��" << endl;
    cout << endl;
    cout << "�������:" << endl;
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
    cout << "��ʱû�뵽�����ܼ�ʲô..." << endl;
}

void Command_about()
{
    cout << endl;
    cout << "������Ϣ" << endl;
    cout << "�ó�������Ϊ:[BIG SHOT]" << endl;
    cout << "����QQ��:1613****64" << endl;
    cout << endl;
    cout << "������Ϣ" << endl;
    cout << "��������:ModLoader" << endl;
    cout << "����汾��:v" << Version.a << "." << Version.b << "." << Version.c << endl;
    cout << "����汾��:" << Version.d << endl;
    if (Pluginsshuliang == 0)
    {
        return;
    }
    cout << endl;
    cout << "�����Ϣ:" << endl;
    for (size_t i = 0; i < PluginsMessage.size(); i++)
    {
        cout << i + 1 << ":" << endl;
        cout << "�����:" << PluginsMessage[i] << endl;
        cout << "���˵��:" << PluginsMessage_1[i] << endl;
        cout << "����汾:" << PluginsVersion[i] << endl;
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
        cout << "Load:����2����" << endl;
        return;
    }
    if (GetCommand[1] == "")
    {
        cout << "Load:����2����" << endl;
        return;
    }
    if (LoadDll(GetCommand[0].c_str()) == NULL)
    {
        cout << "���:\"" << GetCommand[1] << "\"����ʧ��" << endl;
    }
    else
    {
        cout << "������سɹ�" << endl;
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
                cout << "�����:" << PluginsMessage[i] << endl;
                cout << "���˵��:" << PluginsMessage_1[i] << endl;
                cout << "����汾:" << PluginsVersion[i] << endl;
                return;
            }
        }
        cout << "δ�ҵ��ò����Ϣ" << endl;
        return;
    }
    Commandmods = true;
    cout << "�Ѽ���" << Pluginsshuliang << "�����" << endl;
}