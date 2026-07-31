/*

@file Part.h:

* A struct instance that represents
  parts/compoments/atoms.
* Using this we can build Player,
  Enemies etc.,
* Each Part has it's own attack,
  defense, hp etc.,

* Idea for utilising this struct :
    * Storing the struct variables in a vector.
    * This vector is a never changing fixed block(array).
    * Increasing it's size only if new parts are to be added.
    * Each entity will have a enitityData which is a 2d vector.
    * The elements in entityData represents the indices of the
      part vector.
    * EX: entityData = {{2, 3, 1}} && PartVector = {Part1, Part2, Part3, ...., Partn}.
      Here entityData tells [Part2 Part3 Part1] is the how that entity will look.
      
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