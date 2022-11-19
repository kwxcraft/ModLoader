#pragma once
class AddCommand_a
{
public:
    std::string Command_Name_c;
    std::string Command_Help_c;
    void(*func_c)();
    void Addcommand(const char Command_Name[], const char Command_Help[], void(*func)());
    void StartCommand();
    void RunCommand(std::vector<std::string>& GetCommand_a);
};