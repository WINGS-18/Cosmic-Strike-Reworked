/*
@file Character.h

* class Character:
    - Every playble entities have some things in common like i'd,
      alive or dead, stats(attack, defense etc.,), and x, y coordinates.
    - Hence this class is a absract class not wrt c++ rules, but based on
      it's behaviour.
*/



#pragma once

#include "StatsPool.h"
#include "engine/Vector2C.h"

namespace cs {
    
    class Character {
    protected:
        std::vector<std::vector<int>> entityData;     //holds the character layout info
        bool isAlive;
        st::StatsPool m_statsMan;         //stats manager
    
    public:
        Eng::Vector2C m_coord;      //x and y coordinates

        //constructors
        Character();
        Character(std::vector<std::vector<int>> ed, bool isAl, Eng::Vector2C xny);

        virtual ~Character() = default;

        const bool getIsAlive() const;      //returns weather character is alive or not

        const void deathCondition();        //changes the m_isAlive flag
    };
}