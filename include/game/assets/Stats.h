/*
@file Stats.h :

* Handles stats of the entities.
*/

#pragma once

#include "game/assets/Part.h"
#include <vector>

namespace cs {

    namespace st {

        struct Stats {
            int m_hp = 0;
            int m_attack = 0;
            int m_defense = 0;
            int m_shield = 0;

            Stats() = default;    //constructor
            Stats(const std::vector<std::vector<int>>& entityData, const std::vector<Part>& parts);

            //gives the total stats by adding atk, def, hp from individual parts
            void totalStats(const std::vector<std::vector<int>>& entityData, const std::vector<Part>& parts);

            int damageDealer(int def);      //calculates the total damage dealt

            void displayStats() const noexcept;

        };

    }

}