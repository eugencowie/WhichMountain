#pragma once
#ifndef ENGINE_AUDIOMANAGER_HPP
#define ENGINE_AUDIOMANAGER_HPP

#include <irrKlang.h>

namespace engine
{
	class AudioManager
	{
	public:
		AudioManager();
		AudioManager(const AudioManager&) = delete;
		~AudioManager();

		irrklang::ISound* PlaySound(const char* soundFile, bool looping=false);
		void StopAll();

	private:
		irrklang::ISoundEngine* m_engine;
	};
}

using engine::AudioManager;

#endif
