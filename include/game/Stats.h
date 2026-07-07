#pragma once

#include "Part.h"
#include <vector>

namespace cs {

    namespace st {

        struct Stats {
            int m_hp;
            int m_attack;
            int m_defense;
            int m_shield;

            Stats();    //constructor

            //gives the total stats by adding atk, def, hp from individual parts
            void totalStats(const std::vector<std::vector<int>>& entityData, const std::vector<Part>& parts);

        };

    }

}