#pragma once
#ifndef ENGINE_SCREEN_MANAGER_HPP
#define ENGINE_SCREEN_MANAGER_HPP

#include <memory>
#include <vector>

namespace engine
{
	typedef std::shared_ptr<class IScreen> IScreenPtr;

	class IScreen
	{
	public:
		virtual void Update(int elapsedTime) = 0;
		virtual void Draw(int elapsedTime) = 0;
	};

	typedef std::shared_ptr<class ScreenManager> ScreenManagerPtr;

	class ScreenManager
	{
	public:
		static ScreenManagerPtr Create();

		void Switch(IScreenPtr screen);
		void Push(IScreenPtr screen);
		void Pop();
		void Clear();

		void Update(int elapsedTime);
		void Draw(int elapsedTime);

	private:
		std::vector<IScreenPtr> m_screens;
	};
}

using engine::IScreenPtr;
using engine::IScreen;

using engine::ScreenManagerPtr;
using engine::ScreenManager;

#endif
