#include <iostream>
#include <vector>
#include <fstream>
#include <windows.h>
#include <conio.h>
#include <wincon.h>
#include "Main.h"
#include "AddCommand.h"
#pragma warning(disable:4996)
using namespace std;
char Commandmain[1024] = "";
bool Commandmods = false;
vector<AddCommand_a> Command_class;
extern vector<string> GetCommand;
vector<string> CommandList;
vector<string> CommandHelp;
vector<string> PluginsMessage;
vector<string> PluginsMessage_1;
vector<string> PluginsVersion;
char* s_gets(char* st, int n) {
    char* ret_val;
    char* find;
    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n');
        if (find)
            *find = '\0';
        else
            while (getchar() != '\n')
                continue;
    }
    return ret_val;
}

void ������(char Commandmain_a[], vector<string>& GetCommand_a)
{
    GetCommand_a.push_back(Commandmain_a);
    if (GetCommand_a[0] == "")
    {
        return;
    }
    char* p = strtok(Commandmain_a, " ");
    if (p == NULL)
    {
        GetCommand_a[0] = "";
        return;
    }
    GetCommand_a[0] = p;
    while (p != NULL)
    {
        p = strtok(NULL, " ");
        if (p == NULL)
        {
            return;
        }
        GetCommand_a.push_back(p);
    }
    return;
}

void CommandStart() {
    s_gets(Commandmain, 1023);
    ������(Commandmain,GetCommand);
    if (GetCommand.size() == 0)
    {
        cout << "δ֪������:NULL(������),ʹ��help��ð���" << endl;
        return;
    }
    if (GetCommand[0] == "")
    {
        cout << "δ֪������:NULL(������),ʹ��help��ð���" << endl;
        return;
    }
    for (size_t i = 0; i < CommandList.size(); i++)
    {
        if (GetCommand[0] == CommandList[i])
        {
            Commandmods = true;
            break;
        }
    }
    if (Commandmods == false)
    {
        cout << "δ֪������:\"" << GetCommand[0] << "\",ʹ��help��ð���" << endl;
        return;
    }
    for (size_t j = 0; j < Command_class.size(); j++)
    {
        Command_class[j].StartCommand();
    }
    return;
}

__declspec(dllexport) void RunCommand(const char Command[])
{
    bool mode = false;
    vector<string> temp;
    ������((char*)Command, temp);
    if (temp.size() == 0)
    {
        cout << "δ֪������:���ִ���˿�����" << endl;
        return;
    }
    if (temp[0] == "")
    {
        cout << "δ֪������:���ִ���˿�����" << endl;
        return;
    }
    for (size_t i = 0; i < CommandList.size(); i++)
    {
        if (temp[0] == CommandList[i])
        {
            mode = true;
            break;
        }
    }
    if (mode == false)
    {
        cout << "δ֪������:���ִ����δ֪������\"" + temp[0] + "\",����ò�����õ����������Ĳ���Ƿ����" << endl;
        return;
    }
    for (size_t j = 0; j < Command_class.size(); j++)
    {
        Command_class[j].RunCommand(temp);
    }
    return;
}

void CommandClose() {
    Commandmods = false;
    if (GetCommand.size() == 0)
    {
        return;
    }
    GetCommand.clear();
    memset(Commandmain, ' ', 1021);
    return;
}