#include "Stats.h"

namespace cs {

    namespace st {

        Stats::Stats()      //constructor
            : m_hp(0), m_attack(0), m_defense(0), m_shield(0) {}

        void Stats::totalStats(const std::vector<std::vector<int>>& entityData, const std::vector<Part>& parts) {
            for(const auto& row : entityData){
                for(const auto& cell : row){
                    m_hp += parts[cell].m_healthPoints;     //adds individual stats
                    m_attack += parts[cell].m_attack;       //of all parts into the members
                    m_defense += parts[cell].m_defense;
                    m_shield += parts[cell].m_shield;
                }
            }
        }
    }
}