/*
* Utlities.h :
    - This header provides many functions that are used to
    manipulate the terminal.
    - Ex: color change, hide cursor, clear screen etc.,
    - It uses ANSI codes.
*/

#pragma once

namespace Utility {

    void reset();       //reset the color of the texts to default
    void green();       //changes the color of texts to green
    void red();         //changes the color of texts to red

    void clearScreen();     //clears the terminal
    void hideCursor();      //hide the cursor
    void showCursor();      //unhide the cursor

    char keyGiver();        //returns the key that is pressed
    char pressKey();
}