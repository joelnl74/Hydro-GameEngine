#pragma once
#include <string>
class FileSystem
{
public:
	FileSystem();
	~FileSystem();
	void WriteFile(std::string &data);
	void ReadFile(std::string &data);
};

