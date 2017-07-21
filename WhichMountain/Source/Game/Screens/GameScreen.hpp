#pragma once
#ifndef GAME_SCREENS_GAMESCREEN_HPP
#define GAME_SCREENS_GAMESCREEN_HPP

#include "../../Engine/Window.hpp"
#include "../../Engine/InputManager.hpp"
#include "../../Engine/ScreenManager.hpp"
#include "../../Engine/ContentManager.hpp"
#include "../../Engine/AudioManager.hpp"
#include "../../Engine/Camera.hpp"
#include "../../Engine/Sprite.hpp"
#include "../../Engine/SpriteFont.hpp"
#include "../Objects/Obstacle.hpp"
#include "../Objects/Pickup.hpp"
#include "../Objects/Ground.hpp"
#include "../Objects/Player.hpp"

#include "Helper.hpp"
#include <vector>
#include <memory>
#include <random>

namespace game
{
	namespace screens
	{
		/**
		 * The game screen, where the gameplay happens.
		 */
		class GameScreen : public IScreen
		{
		public:
			GameScreen(Window& window, InputManager& input, ScreenManager& screens, ContentManager& content, AudioManager& audio);
			~GameScreen();

			void Update(int elapsedTime) override;
			void Draw(int elapsedTime) override;

		private:
			void SpawnObstacle();
			void SpawnPickup();

			Window& m_window;
			InputManager& m_input;
			ScreenManager& m_screens;
			ContentManager& m_content;
			AudioManager& m_audio;

			FollowCamera m_camera;

			std::vector<std::shared_ptr<Obstacle>> m_obstacles;
			std::vector<std::shared_ptr<Pickup>> m_pickups;

			Ground m_ground;
			Player m_player;

			Sprite m_gameOver;

			SpriteFont m_font;
			Sprite m_scoreText;
			Sprite m_speedText;

			irrklang::ISound* m_bgMusic;
			bool m_musicPlaying;

			std::mt19937 m_random;

			bool m_isGameOver;
			int m_highscore;
			int m_score;
		};
	}
}

using game::screens::GameScreen;

#endif
