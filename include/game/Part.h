/*
A struct instance that represents
parts/compoments/atoms.
Using this we can build Player,
Enemies etc.,
Each Part has it's own attack,
defense, hp etc.,
*/

#pragma once

namespace cs {
    
    struct Part {
        char m_symbol;
        int m_healthPoints;
        int m_attack;
        int m_defense;
        int m_shield;

        //constructors:
        Part();
        Part(char s, int hp, int atk, int def, int sh);

    };
}