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

		FbxImporter* lImporter = FbxImporter::Create(lSdkManager, "");
		
		// Use the first argument as the filename for the importer.
		if (!lImporter->Initialize("Resources/fbx/test.fbx", -1, lSdkManager->GetIOSettings())) {
			printf("Call to FbxImporter::Initialize() failed.\n");
			printf("Error returned: %s\n\n", lImporter->GetStatus().GetErrorString());
			
			return false;
		}
		lScene = FbxScene::Create(lSdkManager, "myScene");

		// Import the contents of the file into the scene.
		lImporter->Import(lScene);

		// The file is imported, so get rid of the importer.
		lImporter->Destroy();

		FbxNode* lRootNode = lScene->GetRootNode();
		if (lRootNode) {
			for (int i = 0; i < lRootNode->GetChildCount(); i++)
				PrintNode(lRootNode->GetChild(i));
		}

		return true;
	}
	void FBX::PrintNode(FbxNode* pNode)
	{
			PrintTabs();
			const char* nodeName = pNode->GetName();
			FbxDouble3 translation = pNode->LclTranslation.Get();
			FbxDouble3 rotation = pNode->LclRotation.Get();
			FbxDouble3 scaling = pNode->LclScaling.Get();

			// Print the contents of the node.
			printf("<node name='%s' translation='(%f, %f, %f)' rotation='(%f, %f, %f)' scaling='(%f, %f, %f)'>\n",
				nodeName,
				translation[0], translation[1], translation[2],
				rotation[0], rotation[1], rotation[2],
				scaling[0], scaling[1], scaling[2]
			);
			numTabs++;

			// Print the node's attributes.
			for (int i = 0; i < pNode->GetNodeAttributeCount(); i++)
				PrintAttribute(pNode->GetNodeAttributeByIndex(i));

			// Recursively print the children.
			for (int j = 0; j < pNode->GetChildCount(); j++)
				PrintNode(pNode->GetChild(j));

			numTabs--;
			PrintTabs();
			printf("</node>\n");
	}
}

