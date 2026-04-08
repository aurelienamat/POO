#pragma once
#include <iostream>
#include <string>
#include <windows.h>

// === Couleurs ANSI ===
#define RESET    "\033[0m"
#define BOLD     "\033[1m"
#define RED      "\033[31m"
#define GREEN    "\033[32m"
#define YELLOW   "\033[33m"
#define BLUE     "\033[34m"
#define MAGENTA  "\033[35m"
#define CYAN     "\033[36m"
#define WHITE    "\033[37m"

// Active le support ANSI sur Windows 10+
inline void enableANSI() {
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);
    SetConsoleMode(hOut, dwMode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
}

inline void printSeparator(char c = '=', int len = 52) {
    std::cout << CYAN;
    for (int i = 0; i < len; i++) std::cout << c;
    std::cout << RESET << "\n";
}

inline void printTitle(const std::string& titre) {
    std::cout << "\n";
    printSeparator();
    std::cout << CYAN << "  " <
        < BOLD << WHITE << titre << RESET << "\n";
    printSeparator();
}

inline void printBanner() {
    std::cout << YELLOW << BOLD;
    std::cout << "\n";
    std::cout << "  ______ _        _   _  ____   ____  ____          _____  \n";
    std::cout << " |  ____| |      | \\ | |/ __ \\ / __ \\|  _ \\   /\\   |  __ \\ \n";
    std::cout << " | |__  | |      |  \\| | |  | | |  | | |_) | /  \\  | |__) |\n";
    std::cout << " |  __| | |      | . ` | |  | | |  | |  _ < / /\\ \\ |  _  / \n";
    std::cout << " | |____| |____  | |\\  | |__| | |__| | |_) / ____ \\| | \\ \\ \n";
    std::cout << " |______|______| |_| \\_|\\____/ \\____/|____/_/    \\_\\_|  \\_\\\n";
    std::cout << RESET;
    std::cout << CYAN << "            -- Jeu de combat en arene --\n" << RESET;
    std::cout << "\n";
}

inline void printHealthBar(int vie, int maxVie = 100, int width = 20) {
    int filled = (vie > 0) ? (vie * width) / maxVie : 0;
    if (filled > width) filled = width;

    const char* color;
    if (vie > maxVie / 2)      color = GREEN;
    else if (vie > maxVie / 4) color = YELLOW;
    else                        color = RED;

    std::cout << "[" << color;
    for (int i = 0; i < filled; i++) std::cout << "#";
    std::cout << RESET;
    for (int i = filled; i < width; i++) std::cout << ".";
    std::cout << "] " << color << BOLD << vie << "/" << maxVie << RESET;
}
