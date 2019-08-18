#pragma once
#include <Windows.h>
#include <string>
#include <vector>

#include "vendor/dirent.h"
namespace Hydro
{
	struct FileNode
	{
		int id;
		std::string path;
	};

	class WindowsFileExplorer
	{
	public:
		WindowsFileExplorer();
		~WindowsFileExplorer();
		int GetFilesInDirectory(const char *filePath);
		int GetNextDirectory();
		void RetrieveDirectory();
	private:
		std::vector<FileNode*> filenodes;
	};
}
