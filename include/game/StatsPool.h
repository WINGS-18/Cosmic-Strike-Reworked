#pragma once

#include "game/Stats.h"

namespace cs {


    namespace st {

        struct StatsPool {
            Stats m_base;
            Stats m_current;

            StatsPool();    //constructor
            StatsPool(const std::vector<std::vector<int>>& entityData, const std::vector<Part>& parts);
        };

    }
    
}