#pragma once
void MyCommand();
void CommandStart();
void CommandClose();
__declspec(dllexport) const struct version
{
	int a = 1;
	int b = 0;
	int c = 2;
	int d = 28;
}Version;
