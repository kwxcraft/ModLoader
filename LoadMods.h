#pragma once
#include <iostream>
#include <vector>
using namespace std;
#define DLL __declspec(dllexport)
DLL void RunCommand(const char Command[]);
DLL void AddCommand(const char Command_Name[], const char Command_Help[], void(*func)());
DLL void Plugins_Message(const char Plugins_Message[], const char Plugins_Message1[], const char Version[]);
DLL vector<string> GetCommand;