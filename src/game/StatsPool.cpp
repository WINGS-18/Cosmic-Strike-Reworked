#include "game/StatsPool.h"

namespace cs::st {

    StatsPool::StatsPool() {}

    void StatsPool::HPReduction() {
        if(m_current.m_shield > 0) {
            m_current.m_shield -= m_current.damageDealer(m_current.m_defense);
        }

        if(m_current.m_shield <= 0){
            m_current.m_hp -= m_current.damageDealer(m_current.m_defense) + m_current.m_shield;
            m_current.m_shield = 0;
        }
    }

}