#pragma once
#include <Windows.h>
#include <iostream>

#define COLOR_RED           (FOREGROUND_RED | FOREGROUND_INTENSITY)
#define COLOR_GREEN         (FOREGROUND_GREEN | FOREGROUND_INTENSITY)
#define COLOR_ORANGE        (FOREGROUND_RED | FOREGROUND_GREEN)
#define COLOR_BLUE          (FOREGROUND_BLUE | FOREGROUND_INTENSITY)
#define COLOR_MAGENTA       (FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY)
#define COLOR_CYAN          (FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY)
#define COLOR_WHITE         (FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY)
#define COLOR_GRAY          (FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE)


namespace Logging
{
    inline bool g_DebugEnabled = false;

    enum class LogType {
        INFO,
        WARNING,
        ERR,
        DEBUG
    };
    inline void SetConsoleColor(WORD color) {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, color);
    }

    inline void ResetConsoleColor() {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, COLOR_GRAY);
    }
    inline void Log(Logging::LogType Type, const char* format, ...)
    {
        if (Type == Logging::LogType::DEBUG && !g_DebugEnabled)
            return;

        va_list args;
        va_start(args, format);

        int size = vsnprintf(nullptr, 0, format, args);
        va_end(args);

        if (size <= 0) return;

        std::unique_ptr<char[]> buffer(new char[size + 1]);
        va_start(args, format);
        vsnprintf(buffer.get(), size + 1, format, args);
        va_end(args);

        const char* type_str = "";
        WORD color = COLOR_WHITE;

        switch (Type) {
        case Logging::LogType::INFO:
            type_str = "INFO";
            color = COLOR_BLUE;
            break;
        case Logging::LogType::WARNING:
            type_str = "WARN";
            color = COLOR_ORANGE;
            break;
        case Logging::LogType::ERR:
            type_str = "ERROR";
            color = COLOR_RED;
            break;
        case Logging::LogType::DEBUG:
            type_str = "DEBUG";
            color = COLOR_CYAN;
            break;
        }

        SetConsoleColor(color);
        std::cout << "[" << type_str << "] ";
        ResetConsoleColor();
        std::cout << buffer.get() << std::endl;
    }
}