#pragma once
#ifndef GAME_SCREENS_GAMESCREEN_HPP
#define GAME_SCREENS_GAMESCREEN_HPP

#include "../../Engine/Window.hpp"
#include "../../Engine/InputManager.hpp"
#include "../../Engine/ScreenManager.hpp"
#include "../../Engine/ContentManager.hpp"
#include "../../Engine/Camera.hpp"
#include "../Objects/Obstacle.hpp"
#include "../Objects/Ground.hpp"
#include "../Objects/Player.hpp"

#include <vector>
#include <memory>

namespace game
{
	namespace screens
	{
		class GameScreen : public IScreen
		{
		public:
			static IScreenPtr Create(Window* window, InputManager* input, ScreenManager* screens, ContentManager* content) {
				return std::make_unique<GameScreen>(window, input, screens, content);
			}

			GameScreen(Window* window, InputManager* input, ScreenManager* screens, ContentManager* content);

			void Update(int elapsedTime) override;
			void Draw(int elapsedTime) override;

		private:
			Window* m_window;
			InputManager* m_input;
			ScreenManager* m_screens;
			ContentManager* m_content;

			FollowCamera m_camera;

			std::vector<Obstacle> m_obstacles;
			Ground m_ground;
			Player m_player;
		};
	}
}

using game::screens::GameScreen;

#endif
