#pragma once

#include "StatsPool.h"
#include "engine/Vector2C.h"

namespace cs {
    
    class Character {
    protected:
        std::vector<std::vector<int>> entityData;     //holds the character layout info
        bool isAlive;
        Eng::Vector2C m_coord;      //x and y coordinates
        st::StatsPool m_base;         //stats manager
    
    public:

        Character();
        
        Character(std::vector<std::vector<int>> ed, bool isAl, Eng::Vector2C xny);

    };
}