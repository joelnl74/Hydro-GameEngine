#include "WindowsFileExplorer.h"

namespace Hydro
{
	WindowsFileExplorer::WindowsFileExplorer()
	{
	}
	WindowsFileExplorer::~WindowsFileExplorer()
	{
		for (int i = 0; i < filenodes.size(); i++)
		{
			delete filenodes[i];
		}

		filenodes.clear();
	}
	int WindowsFileExplorer::GetFilesInDirectory(const char *filePath)
	{
		DIR *dir;
		struct dirent *ent;
		if ((dir = opendir(filePath)) != NULL) {

			/* print all the files and directories within directory */
			while ((ent = readdir(dir)) != NULL) {

				char last_letter = ent->d_name[strlen(ent->d_name) - 1];
				if (last_letter != '.')
				{
					FileNode *node = new FileNode();
						node->path = std::string(filePath) + std::string("\\") + std::string(ent->d_name);
						node->id = ent->d_ino;

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

		return EXIT_SUCCESS;
	}
	int WindowsFileExplorer::GetNextDirectory()
	{
		for (int i = 0; i < filenodes.size(); i++)
		{
			const char *c = filenodes[i]->path.c_str();

			GetFilesInDirectory(c);
		}

		return EXIT_SUCCESS;
	}
	void WindowsFileExplorer::RetrieveDirectory()
	{
	}
}

