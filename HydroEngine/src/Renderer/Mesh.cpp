#include <iostream>

#include "Mesh.h"

#include "../Hydro.h"

#include "assimp/postprocess.h"
#include <assimp/scene.h>

#include "../../vendor/glm/glm.hpp"
#include "../../vendor/glm/gtc/matrix_transform.hpp"

namespace Hydro
{
	Mesh::Mesh(std::string &filePath)
	{
		m_Importer = new Assimp::Importer();

		const aiScene* scene = m_Importer->ReadFile(filePath, aiProcess_Triangulate);

		if (!scene || !scene->HasMeshes())
		{
			LOG_WARNING("Mesh could not be loaded: {0}", m_Importer->GetErrorString());
			return;
		}

		for (int m = 0; m < scene->mNumMeshes; m++)
		{
			aiMesh* mesh = scene->mMeshes[m];

			for (size_t i = 0; i < mesh->mNumVertices; i++)
			{
				Vertex vertex;

				vertex.Position = { mesh->mVertices[i].x, mesh->mVertices[i].y, mesh->mVertices[i].z };
				vertex.Normal = { mesh->mNormals[i].x, mesh->mNormals[i].y, mesh->mNormals[i].z };

				if (mesh->HasTangentsAndBitangents())
				{
					vertex.Tangent = { mesh->mTangents[i].x, mesh->mTangents[i].y, mesh->mTangents[i].z };
					vertex.Binormal = { mesh->mBitangents[i].x, mesh->mBitangents[i].y, mesh->mBitangents[i].z };
				}

				if (mesh->HasTextureCoords(0))
					vertex.TexCoords = { mesh->mTextureCoords[0][i].x, mesh->mTextureCoords[0][i].y };

				m_vertices.push_back(vertex);
			}

			// Indices
			for (size_t i = 0; i < mesh->mNumFaces; i++)
			{
				m_Indices.push_back(mesh->mFaces[i].mIndices[0]);
				m_Indices.push_back(mesh->mFaces[i].mIndices[1]);
				m_Indices.push_back(mesh->mFaces[i].mIndices[2]);
			}
		}
			m_Scene = scene;

			layout = new BufferLayout({
			{ ShaderDataType::Float3, "a_Position" },
			{ ShaderDataType::Float3, "a_Normal" },
			{ ShaderDataType::Float3, "a_Tangent" },
			{ ShaderDataType::Float3, "a_Binormal" },
			{ ShaderDataType::Float2, "a_TexCoord" }
			});

			vertexBuffer = VertexBuffer::Create(m_vertices.data(), m_vertices.size() * sizeof(Vertex));
			indexBuffer = IndexBuffer::Create(m_Indices.data(), m_Indices.size());
			vertexArray = VertexArray::Create(vertexBuffer, layout);
	}

	void Mesh::Draw(Shader &shader)
	{
		shader.Bind();

		glm::mat4 m_View = glm::mat4(1);
		glm::mat4 m_Projection = glm::mat4(1);

		m_View = glm::translate(m_View, glm::vec3(0.0f, 5.0f, -25.0f));
		m_Projection = glm::perspective(glm::radians(45.0f), float(1280) / float(720), 0.1f, 100.0f);

		glm::mat4 modelMatrix = glm::mat4(1.0f);
		float angle = 90.0;
		modelMatrix = glm::scale(modelMatrix, glm::vec3(0.1F, 0.1F, 0.1F));

		shader.SetMatrix4("projection", m_Projection); 
		shader.SetMatrix4("view", m_View);
		shader.SetMatrix4("model", modelMatrix);

		vertexArray->Bind();
		indexBuffer->Bind();

		glDrawElements(GL_TRIANGLES, m_Indices.size(), GL_UNSIGNED_INT, nullptr);

		indexBuffer->UnBind();
		vertexArray->UnBind();

		shader.UnBind();
	}
}

