#include <Engine/Model.hpp>

#include <assimp/Importer.hpp>
#include <assimp/postprocess.h>

namespace engine
{
	ModelPtr Model::Create(ShaderPtr shader, std::string path)
	{
		return std::make_shared<Model>(shader, path);
	}

	Model::Model(ShaderPtr shader, std::string path)
	{
		m_directory = path.substr(0, path.find_last_of('/'));

		Assimp::Importer importer;
		const aiScene* scene = importer.ReadFile(path, aiProcess_Triangulate | aiProcess_GenNormals | aiProcess_FlipUVs);

		if (!scene || scene->mFlags == AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode)
		{
			assert(0 && "Failed to load model");
			std::exit(EXIT_FAILURE);
		}

		ProcessNode(shader, scene->mRootNode, scene);
	}

	void Model::BindShader(ShaderPtr shader)
	{
		for (auto mesh : m_meshes)
		{
			mesh->BindShader(shader);
		}
	}

	void Model::Draw(glm::mat4 model, glm::mat4 view, glm::mat4 projection)
	{
		for (auto mesh : m_meshes)
		{
			mesh->Draw(model, view, projection);
		}
	}

	void Model::ProcessNode(ShaderPtr shader, aiNode* aiNode, const aiScene* aiScene)
	{
		for (unsigned int i = 0; i < aiNode->mNumMeshes; i++)
		{
			aiMesh* aiMesh = aiScene->mMeshes[aiNode->mMeshes[i]];
			aiMaterial* aiMaterial = nullptr;

			if (aiMesh->mMaterialIndex >= 0)
			{
				aiMaterial = aiScene->mMaterials[aiMesh->mMaterialIndex];
			}

			MeshPtr mesh = ProcessMesh(shader, aiMesh, aiMaterial);
			m_meshes.push_back(mesh);
		}

		// Recursively processes all child nodes in this aiNode, until there are
		// no child nodes left to process.

		for (unsigned int i = 0; i < aiNode->mNumChildren; i++)
		{
			ProcessNode(shader, aiNode->mChildren[i], aiScene);
		}
	}

	MeshPtr Model::ProcessMesh(ShaderPtr shader, aiMesh* aiMesh, aiMaterial* aiMaterial)
	{
		std::vector<Vertex> vertices;
		std::vector<GLuint> indices;
		std::vector<TexturePtr> textures;

		for (unsigned int i = 0; i < aiMesh->mNumVertices; i++)
		{
			Vertex vertex;

			if (aiMesh->mVertices)
			{
				vertex.position = { aiMesh->mVertices[i].x, aiMesh->mVertices[i].y, aiMesh->mVertices[i].z };
			}

			if (aiMesh->mNormals)
			{
				vertex.normal = { aiMesh->mNormals[i].x, aiMesh->mNormals[i].y, aiMesh->mNormals[i].z };
			}

			if (aiMesh->mTextureCoords[0])
			{
				vertex.texCoord = { aiMesh->mTextureCoords[0][i].x, aiMesh->mTextureCoords[0][i].y };
			}

			vertices.push_back(vertex);
		}

		for (unsigned int i = 0; i < aiMesh->mNumFaces; i++)
		{
			aiFace face = aiMesh->mFaces[i];

			for (unsigned int j = 0; j < face.mNumIndices; j++)
			{
				indices.push_back(face.mIndices[j]);
			}
		}

		if (aiMesh->mMaterialIndex >= 0 && aiMaterial != nullptr)
		{
			std::vector<TexturePtr> diffuseMaps = ProcessMaterial(aiMaterial, aiTextureType_DIFFUSE, TextureType::DIFFUSE);
			std::vector<TexturePtr> specularMaps = ProcessMaterial(aiMaterial, aiTextureType_SPECULAR, TextureType::SPECULAR);

			textures.insert(textures.end(), diffuseMaps.begin(), diffuseMaps.end());
			textures.insert(textures.end(), specularMaps.begin(), specularMaps.end());
		}

		return Mesh::Create(shader, vertices, indices, textures);
	}

	std::vector<TexturePtr> Model::ProcessMaterial(aiMaterial* aiMat, aiTextureType aiType, TextureType type)
	{
		std::vector<TexturePtr> textures;

		for (unsigned int i = 0; i < aiMat->GetTextureCount(aiType); i++)
		{
			aiString aiFilename;
			aiMat->GetTexture(aiType, i, &aiFilename);

			std::string filename = m_directory + '/' + std::string(aiFilename.C_Str());

			bool skip = false;

			// If we have already loaded a texture matching the filename then use
			// the existing texture and skip loading it again.

			for (unsigned int j = 0; j < m_textures.size(); j++)
			{
				if (m_textures[j]->GetPath() == filename)
				{
					textures.push_back(m_textures[j]);
					skip = true;
					break;
				}
			}

			if (!skip)
			{
				TexturePtr texture = Texture::Create(filename.c_str(), type);
				m_textures.push_back(texture);
				textures.push_back(m_textures.back());
			}
		}

		return textures;
	}
}
