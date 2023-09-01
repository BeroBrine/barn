#include "Log.h"

namespace barn
{
    std::shared_ptr<spdlog::logger> Log::s_coreLogger;
    std::shared_ptr<spdlog::logger> Log::s_clientLogger;

    void Log::init()
    {
        spdlog::set_pattern("%^[%T] %n: %v%s"); // pattern
        //core logger
        s_coreLogger = spdlog::stdout_color_mt("Barn");
        // setting the level (enums for severity)
        s_coreLogger->set_level(spdlog::level::trace);
        //client loggerW
        s_clientLogger = spdlog::stdout_color_mt("App");
        s_clientLogger->set_level(spdlog::level::trace);
    }
}
