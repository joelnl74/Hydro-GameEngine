#include "FileSystemWindows.h"

namespace Hydro
{
	FileSystemWindows::FileSystemWindows()
	{
	}
	FileSystemWindows::~FileSystemWindows()
	{
		for (int i = 0; i < filenodes.size(); i++)
		{
			hdel filenodes[i];
		}

		filenodes.clear();
	}

	int FileSystemWindows::OpenFile(const char * filePath)
	{

		return 0;
	}

	int FileSystemWindows::DeleteFile(const char * path)
	{
		return 0;
	}

	int FileSystemWindows::GetFileDirectory(const char * path)
	{
		return 0;
	}

	int FileSystemWindows::ReadFileDirectory(const char * path)
	{
		return 0;
	}

	int FileSystemWindows::ReadAllFilesDirectories(const char *filePath)
	{
		DIR *dir;
		struct dirent *ent;
		if ((dir = opendir(filePath)) != NULL) {

			/* print all the files and directories within directory */
			while ((ent = readdir(dir)) != NULL) {

				char last_letter = ent->d_name[strlen(ent->d_name) - 1];
				if (last_letter != '.')
				{
					FileNode *node = hnew FileNode();
					node->path = std::string(filePath) + std::string("\\") + std::string(ent->d_name);
					node->id = ent->d_ino;

					if (ent->d_type == DT_DIR)
					{
							node->directory = true;
					}

					filenodes.push_back(node);

					puts(ent->d_name);
				}
			}
			closedir(dir);
		}
		else {
			/* could not open directory */
			perror("Could not open directory");
			return EXIT_FAILURE;
		}

		GetNextDirectory();
		return EXIT_SUCCESS;
	}

	int FileSystemWindows::GetNextDirectory()
	{
		for (int i = 0; i < filenodes.size(); i++)
		{
			if (filenodes[i]->directory == true && filenodes[i]->visited == false)
			{
				filenodes[i]->visited = true;
				const char *c = filenodes[i]->path.c_str();
				ReadAllFilesDirectories(c);
			}
		}

		return EXIT_SUCCESS;
	}
}

