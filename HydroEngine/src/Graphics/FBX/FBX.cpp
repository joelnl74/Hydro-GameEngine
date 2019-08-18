#include "FBX.h"

namespace Hydro
{
	FBX::FBX()
	{
	}

	bool FBX::Setup()
	{

		// Initialize the SDK manager. This object handles memory management.
		lSdkManager = FbxManager::Create();

		ios = FbxIOSettings::Create(lSdkManager, IOSROOT);
		lSdkManager->SetIOSettings(ios);

		return true;
	}
}

