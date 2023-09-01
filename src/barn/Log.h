#pragma once
#include <memory>
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"
#include "spdlog/sinks/stdout_color_sinks.h"
namespace barn
{
    class Log
    {
        private:
            static std::shared_ptr<spdlog::logger> s_coreLogger;
            static std::shared_ptr<spdlog::logger> s_clientLogger;
        public:
            static void init();
            inline static std::shared_ptr<spdlog::logger>& getCoreLogger() {return s_coreLogger;}
            inline static std::shared_ptr<spdlog::logger>& getClientLogger() {return s_clientLogger;}

    };

}

//core macros
#define _CORE_ERROR(...)        ::barn::Log::getCoreLogger()->error(__VA_ARGS__) 
#define _CORE_WARN(...)         ::barn::Log::getCoreLogger()->warn(__VA_ARGS__) 
#define _CORE_INFO(...)         ::barn::Log::getCoreLogger()->info(__VA_ARGS__) 
#define _CORE_TRACE(...)        ::barn::Log::getCoreLogger()->trace(__VA_ARGS__) 
// client macro
#define _CLIENT_ERROR(...)      ::barn::Log::getClientLogger()->error(__VA_ARGS__) 
#define _CLIENT_WARN(...)       ::barn::Log::getClientLogger()->warn(__VA_ARGS__) 
#define _CLIENT_INFO(...)       ::barn::Log::getClientLogger()->info(__VA_ARGS__) 
#define _CLIENT_TRACE(...)      ::barn::Log::getClientLogger()->trace(__VA_ARGS__) 



