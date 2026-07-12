/*
* Utlities.h :
    - This header provides many functions that are used to
    manipulate the terminal.
    - Ex: color change, hide cursor, clear screen etc.,
    - It uses ANSI codes.
*/

#pragma once

namespace Utility {

    void reset();
    void green();
    void red();

    void clearScreen();
    void hideCursor();
    void showCursor();

    char keyGiver();
}