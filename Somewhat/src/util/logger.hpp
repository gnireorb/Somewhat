#pragma once
#include "common.hpp"
#include "spdlog/sinks/basic_file_sink.h"

template <typename TP>
std::time_t to_time_t(TP tp)
{
	using namespace std::chrono;
	auto sctp = time_point_cast<system_clock::duration>(tp - TP::clock::now()
		+ system_clock::now());
	return system_clock::to_time_t(sctp);
}

class logger;
inline logger* g_logger{};

class logger
{
public:
	explicit logger()
	{
		m_file_path /= "Somewhat";
		std::filesystem::path m_backup_path = m_file_path;
		m_backup_path /= "Backup";
		if (!std::filesystem::exists(m_file_path))
		{
			std::filesystem::create_directory(m_file_path);
		}
		else if (!std::filesystem::is_directory(m_file_path))
		{
			std::filesystem::remove(m_file_path);
			std::filesystem::create_directory(m_file_path);
		}
		if (!std::filesystem::exists(m_backup_path))
		{
			std::filesystem::create_directory(m_backup_path);
		}
		else if (!std::filesystem::is_directory(m_backup_path))
		{
			std::filesystem::remove(m_backup_path);
			std::filesystem::create_directory(m_backup_path);
		}

		m_file_path /= "Somewhat.log";

		if (std::filesystem::exists(m_file_path))
		{
			auto file_time = std::filesystem::last_write_time(m_file_path);
			auto timet = to_time_t(file_time);
			auto local_time = std::localtime(&timet);

			auto timestamp = fmt::format("{:0>2}-{:0>2}-{}-{:0>2}-{:0>2}-{:0>2} Somewhat.log", local_time->tm_mon + 1, local_time->tm_mday, local_time->tm_year + 1900, local_time->tm_hour, local_time->tm_min, local_time->tm_sec);

			std::filesystem::copy_file(m_file_path, m_backup_path / timestamp);
			std::filesystem::remove(m_file_path);
		}

		auto logger = spdlog::basic_logger_mt("logs", "Somewhat/Somewhat.log");
		spdlog::set_default_logger(logger);
		spdlog::set_pattern("%v");
		spdlog::flush_on(spdlog::level::info);

		g_logger = this;
	}

	~logger()
	{
		g_logger = nullptr;
	}

private:
	std::filesystem::path m_file_path;
};