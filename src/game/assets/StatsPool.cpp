#include "game/assets/StatsPool.h"

namespace cs::st {

    StatsPool::StatsPool(const std::vector<std::vector<int>>& entityData, const std::vector<Part>& parts)
        : m_base(entityData, parts)
        {
            m_current = m_base;
        }

    void StatsPool::reset() {
        m_current.m_hp = m_base.m_hp;
        m_current.m_attack = m_base.m_attack;
        m_current.m_defense = m_base.m_defense;
        m_current.m_shield = m_base.m_shield;
    }

}