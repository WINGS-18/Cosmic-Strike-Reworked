/*
@file StatsPool.h :

* Uses two Stats instances(base, current) as'
  members to control the stats.
*/

#pragma once

#include "game/assets/Stats.h"

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