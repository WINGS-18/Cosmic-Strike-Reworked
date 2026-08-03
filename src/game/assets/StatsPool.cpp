#include "game/assets/StatsPool.h"

namespace cs::st {

    StatsPool::StatsPool(const std::vector<std::vector<int>>& entityData, const std::vector<Part>& parts) {
        m_base.totalStats(entityData, parts);
        m_current.totalStats(entityData, parts);
    }

}