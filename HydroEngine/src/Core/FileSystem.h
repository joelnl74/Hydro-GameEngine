#pragma once
#include <unordered_map>

namespace Hydro
{
	struct FileNode
	{
		int id;
		bool directory = false;
		bool visited = false;
		std::string type;
		std::string path;
	};

	class FileSystem
	{
	public:
		~FileSystem() = default;

		virtual int OpenFile(const char* path) = 0;
		virtual int DeleteFile(const char* path) = 0;
		virtual int GetFileDirectory(const char* path) = 0;
		virtual int ReadFileDirectory(const char* path) = 0;
		virtual int ReadAllFilesDirectories(const char* path) = 0;

		static const FileSystem *fileSystem;
		
	private:
		std::unordered_map<std::string, FileNode&> m_Files;
	};
}