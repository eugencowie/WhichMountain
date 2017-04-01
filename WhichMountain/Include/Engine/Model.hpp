#pragma once
#ifndef ENGINE_MODEL_HPP
#define ENGINE_MODEL_HPP

#include "Texture.hpp"
#include "Mesh.hpp"

#include <assimp/scene.h>
#include <vector>
#include <memory>

namespace engine
{
	typedef std::shared_ptr<class Model> ModelPtr;

	class Model
	{
	public:
		static ModelPtr Create(ShaderPtr shader, std::string path);

		Model(ShaderPtr shader, std::string path);

		void BindShader(ShaderPtr shader);

		void Draw(glm::mat4 model={}, glm::mat4 view={}, glm::mat4 projection={});

	private:
		void ProcessNode(ShaderPtr shader, aiNode* aiNode, const aiScene* aiScene);
		MeshPtr ProcessMesh(ShaderPtr shader, aiMesh* aiMesh, aiMaterial* aiMaterial);
		std::vector<TexturePtr> ProcessMaterial(aiMaterial* aiMat, aiTextureType aiType, TextureType type);

		std::vector<TexturePtr> m_textures;
		std::vector<MeshPtr> m_meshes;
		std::string m_directory;
	};
}

using engine::ModelPtr;
using engine::Model;

#endif
