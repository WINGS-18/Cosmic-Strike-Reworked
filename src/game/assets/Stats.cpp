#include "game/assets/Stats.h"
#include <iostream>

namespace cs {

    namespace st {

        //fix : parameterised constructor works successfully

        Stats::Stats(const std::vector<std::vector<int>>& entityData, const std::vector<Part>& parts) {
            totalStats(entityData, parts);
        }

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

        int Stats::damageDealer(int def) {
            if(def < m_attack) {
                return m_attack * ((100.0f) / (100 + def));     //damage formula scales with defense
            }else{
                return 5;
            }
        }
    }
}