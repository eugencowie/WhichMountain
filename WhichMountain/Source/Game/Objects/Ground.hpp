#pragma once
#ifndef GAME_OBJECTS_GROUND_HPP
#define GAME_OBJECTS_GROUND_HPP

#include "../../Engine/ContentManager.hpp"
#include "../../Engine/Shader.hpp"
#include "../../Engine/Mesh.hpp"

namespace game
{
	namespace objects
	{
		class Ground
		{
		public:
			explicit Ground(ContentManager* content);

			void Draw(glm::mat4 view, glm::mat4 proj);

		private:
			ShaderPtr m_shader;
			MeshPtr m_mesh;
		};
	}
}

using game::objects::Ground;

#endif
