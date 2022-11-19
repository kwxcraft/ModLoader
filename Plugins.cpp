#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <io.h>
#include <direct.h>
#include <boost/filesystem.hpp>

using namespace std;
#pragma warning(disable:4996)

int Pluginsshuliang = 0;
vector<HMODULE> Handlejb;
vector<string> fileNames;

typedef struct _UNICODE_STRING
{ // UNICODE_STRING structure
	USHORT Length;
	USHORT MaximumLength;
	PWSTR  Buffer;
} UNICODE_STRING, * PUNICODE_STRING;

typedef NTSTATUS(WINAPI* fLdrLoadDll) //LdrLoadDll function prototype 
(
	IN PWCHAR PathToFile OPTIONAL,
	IN ULONG Flags OPTIONAL,
	IN PUNICODE_STRING ModuleFileName,
	OUT PHANDLE ModuleHandle
	);

typedef VOID(WINAPI* fRtlInitUnicodeString) //RtlInitUnicodeString function prototype
(
	PUNICODE_STRING DestinationString,
	PCWSTR SourceString
	);

LPCWSTR stringToLPCWSTR(std::string orig)
{
	wchar_t* wcstring = 0;
	try {
		size_t origsize = orig.length() + 1;
		const size_t newsize = 100; size_t convertedChars = 0;
		if (orig == "") {
			wcstring = (wchar_t*)malloc(0);
			mbstowcs_s(&convertedChars, wcstring, origsize, orig.c_str(), _TRUNCATE);
		}
		else {
			wcstring = (wchar_t*)malloc(sizeof(wchar_t) * (orig.length() - 1));
			mbstowcs_s(&convertedChars, wcstring, origsize, orig.c_str(), _TRUNCATE);
		}
	}
	catch (std::exception e)
	{
	}
	return wcstring;
}

HMODULE LoadDll(LPCSTR lpFileName)
{
	HMODULE hntdll = NULL;
	fLdrLoadDll _LdrLoadDll = NULL;
	fRtlInitUnicodeString _RtlInitUnicodeString = NULL;
	if (hntdll == NULL) { hntdll = GetModuleHandleA("ntdll.dll"); }
	if (_LdrLoadDll == NULL) { _LdrLoadDll = (fLdrLoadDll)GetProcAddress(hntdll, "LdrLoadDll"); }
	if (_RtlInitUnicodeString == NULL)
	{
		_RtlInitUnicodeString = (fRtlInitUnicodeString)GetProcAddress(hntdll, "RtlInitUnicodeString");
	}
	int StrLen = lstrlenA(lpFileName);
	BSTR WideStr = SysAllocStringLen(NULL, StrLen);
	MultiByteToWideChar(CP_ACP, 0, lpFileName, StrLen, WideStr, StrLen);

	UNICODE_STRING usDllName;
	_RtlInitUnicodeString(&usDllName, WideStr);
	SysFreeString(WideStr);

	HANDLE DllHandle;
	_LdrLoadDll(0, 0, &usDllName, &DllHandle);

	return (HMODULE)DllHandle;
}

bool bathReadFileNamesInFolders(const string folderName, const string extension, vector<string>& vec_filenames)
{
	if (!boost::filesystem::exists(folderName))
	{
		return 0;
	}
	else
	{
		boost::filesystem::directory_iterator end_iter;
		for (boost::filesystem::directory_iterator iter(folderName); iter != end_iter; ++iter)
		{
			if (boost::filesystem::is_regular_file(iter->status()))
			{
				string file_name = iter->path().string();
				boost::filesystem::path dir(file_name);

				if (!dir.extension().string().empty())
				{
					if (!file_name.substr(file_name.rfind('.')).compare(extension))
					{
						vec_filenames.push_back(file_name);
					}
				}
			}

		}
	}
	return 1;
}

void Pluginsjc(int i)
{
	if (0 != access("mods", 0))
	{
		if (mkdir("mods") == -1)
		{
			cout << "插件" << ":" << "创建mods文件夹时发生错误" << endl;
		}
	}
	if (0 != access("config", 0))
	{
		if (mkdir("config") == -1)
		{
			cout << "插件" << ":" << "创建config文件夹时发生错误" << endl;
		}
	}
	bathReadFileNamesInFolders("mods", ".dll", fileNames);
	if (fileNames.size() == 0)
	{
		if (i == 0)
		{
			cout << "插件" << ":" << "已加载0个插件" << endl;
		}
		return;
	}
	Pluginsshuliang = 0;
	for (int i = 0; i <= fileNames.size() - 1; i++)
	{
		Handlejb.push_back(LoadDll(fileNames[i].c_str()));
		if (Handlejb[i] == NULL)
		{
			cout << "插件:" << "插件:\"" << fileNames[i] << "\"加载错误" << endl;
		}
		else
		{
			Pluginsshuliang++;
		}
	}
	if (i == 0)
	{
		cout << "插件" << ":" << "已加载" << Pluginsshuliang << "个插件" << endl;
	}
	return;
}