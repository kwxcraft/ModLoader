#include <iostream>
#include <vector>
#include <stdlib.h>
#include "Plugins.h"
#include "Main.h"
#include "Command.h"
extern std::vector<std::string> GetCommand;

int main(int argc, char* argv[]) {
	SetConsoleTitleW(L"ModLoader v1.0.2");
	MyCommand();
	if (argc >= 2)
	{
        Pluginsjc(1);
        for (size_t i = 0; i < argc - 1; i++)
        {
            GetCommand.push_back(argv[i + 1]);
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
            std::cout << "´íÎó½Å±¾ÃüÁî:\"" << GetCommand[0] << "\"" << std::endl;
            return 1;
        }
        for (size_t j = 0; j < Command_class.size(); j++)
        {
            Command_class[j].StartCommand();
        }
        return 0;
	}
    Pluginsjc(0);
	while (1)
	{
		std::cout << "ÇëÊäÈëÃüÁî" << std::endl;
		std::cout << "> ";
		CommandStart();
		CommandClose();
	}
	return 0;
}