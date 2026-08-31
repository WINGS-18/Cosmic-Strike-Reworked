#include "engine/Utilities.h"
#include <iostream>
#include <conio.h>

void Utility::reset() {
    std::cout << "\033[0m";
}

void Utility::red() {
    std::cout << "\033[31m";
}

void Utility::green() {
    std::cout << "\033[92m";
}

void Utility::clearScreen() {
    std::cout << "\033[2J\033[H";
}

void Utility::hideCursor() {
    std::cout << "\033[?25l";
}

void Utility::showCursor() {
    std::cout << "\033[?25h";
}

char Utility::keyGiver() {
    if(_kbhit())
        return _getch();
    else
        return '\0';
}

char Utility::pressKey() {
    return _getch();
}

void Utility::displayFinalScore(int score) {

    Utility::clearScreen();
    std::cout << "========================================\n";
    std::cout << "||          <--GAME OVER-->           ||\n";
    std::cout << "========================================\n\n";
    
    std::cout << "       Final Score: [ " << score << " ] \n\n";
    
    std::cout << "========================================\n";
    std::cout << "||   Press 'e' to return to menu...   ||\n";
    std::cout << "========================================\n";

}