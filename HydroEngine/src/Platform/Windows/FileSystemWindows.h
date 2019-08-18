#pragma once
#include <Windows.h>
#include <string>
#include <vector>

#include "../../System/FileSystem.h"
#include "../../Hydro.h"
#include "vendor/dirent.h"
namespace Hydro
{
	class FileSystemWindows : public FileSystem
	{
	public:
		FileSystemWindows();
		~FileSystemWindows();

		virtual int OpenFile(const char* path) override;
		virtual int DeleteFile(const char* path) override;
		virtual int GetFileDirectory(const char* path) override;
		virtual int ReadFileDirectory(const char* path) override;
		virtual int ReadAllFilesDirectories(const char* path) override;

		// Get all the directories within an directory
		int GetNextDirectory();
	private:
		std::vector<FileNode*> filenodes;
	};
}
