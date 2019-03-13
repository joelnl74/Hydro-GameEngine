#pragma once
#include <string>
class FileSystem
{
public:
	FileSystem();
	~FileSystem();
	bool WriteFile(std::string &data);
	bool ReadFile(std::string &data);
};

