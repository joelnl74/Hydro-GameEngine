#pragma once
#include <fbxsdk.h>
namespace Hydro
{
	class FBX
	{
	public:
		FBX();
		bool Setup();

	private:
		FbxManager* lSdkManager;
		FbxIOSettings *ios;
	};
}