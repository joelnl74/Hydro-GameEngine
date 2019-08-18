#include <GUSICommandLine.h>
#include <stdlib.h>

#include <fbxfilesdk/fbxfilesdk_nsbegin.h>

#undef main

DECLARE_MAIN(test)

REGISTER_MAIN_START
REGISTER_MAIN(test)
REGISTER_MAIN_END

int main()
{
	(void) exec_commands();
	
	return 0;
}
#include <fbxfilesdk/fbxfilesdk_nsend.h>
