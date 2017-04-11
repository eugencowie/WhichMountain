#include "GameScreen.hpp"

#include <glm/gtc/matrix_transform.hpp>

namespace game
{
	GameScreen::GameScreen(Window* window, InputManager* input) :
		m_window(window),
		m_input(input)
	{
		m_shader = Shader::Create("../../../../Content/Shaders/Textured.vert", "../../../../Content/Shaders/Textured.frag");
		m_model = Model::Create(m_shader, "../../../../Content/Models/RetroRacer/RetroRacer.obj");
	}

	void GameScreen::Update(int elapsedTime)
	{
		if (m_input->IsJustReleased(SDLK_ESCAPE))
		{
			m_window->Close();
		}
	}

	void GameScreen::Draw(int elapsedTime)
	{
		glm::mat4 proj = glm::perspective(glm::radians(45.f), 1280 / 720.f, 0.1f, 100.f);
		glm::mat4 view = glm::lookAt(glm::vec3(3, 1.5f, 3), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));

		m_rotation += glm::radians(elapsedTime / 25.f);
		glm::mat4 model = glm::rotate(glm::mat4(), m_rotation, glm::vec3(0, 1, 0));

		m_model->Draw(model, view, proj);
	}
}
