#pragma once
#ifndef GAME_SCREENS_GAMESCREEN_HPP
#define GAME_SCREENS_GAMESCREEN_HPP

#include "../../Engine/Window.hpp"
#include "../../Engine/InputManager.hpp"
#include "../../Engine/ScreenManager.hpp"
#include "../../Engine/ContentManager.hpp"
#include "../../Engine/AudioManager.hpp"
#include "../../Engine/Camera.hpp"
#include "../Objects/Obstacle.hpp"
#include "../Objects/Ground.hpp"
#include "../Objects/Player.hpp"

#include <vector>
#include <memory>
#include <random>

namespace game
{
	namespace screens
	{
		class GameScreen : public IScreen
		{
		public:
			static IScreenPtr Create(Window* window, InputManager* input, ScreenManager* screens, ContentManager* content, AudioManager* audio) {
				return std::make_unique<GameScreen>(window, input, screens, content, audio);
			}

			GameScreen(Window* window, InputManager* input, ScreenManager* screens, ContentManager* content, AudioManager* audio);

			void Update(int elapsedTime) override;
			void Draw(int elapsedTime) override;

		private:
			void SpawnObstacle();

			Window* m_window;
			InputManager* m_input;
			ScreenManager* m_screens;
			ContentManager* m_content;
			AudioManager* m_audio;

			FollowCamera m_camera;

			std::vector<std::shared_ptr<Obstacle>> m_obstacles;
			Ground m_ground;
			Player m_player;

			std::mt19937 m_random;
		};
	}
}

using game::screens::GameScreen;

#endif
