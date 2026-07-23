#pragma once

#include "game/Stats.h"

namespace cs {

    namespace st {

        struct StatsPool {
            Stats m_base;
            Stats m_current;

            StatsPool();    //constructor

            void HPReduction();   //reduces hp of the entity
        };

    }
    
}