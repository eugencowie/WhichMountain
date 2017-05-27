#include "AudioManager.hpp"

#include <iostream>

namespace engine
{
	AudioManager::AudioManager() :
		m_engine(irrklang::createIrrKlangDevice())
	{
		if (!m_engine)
		{

		}
	}

	AudioManager::~AudioManager()
	{
		m_engine->drop();
	}

	irrklang::ISound* AudioManager::PlaySound(const char* soundFile, bool looping)
	{
		return m_engine->play2D(soundFile, looping);
	}

	void AudioManager::StopAll()
	{
		if (m_engine)
		{
			m_engine->stopAllSounds();
		}
	}
}
