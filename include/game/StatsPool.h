#pragma once

#include "Stats.h"

namespace cs {

    class Character;

    namespace st {

        struct StatsPool {
            Stats m_base;
            Stats m_current;

            StatsPool();    //constructor

            void HPReduction(Character* obj);   //reduces hp of the entity

        };
    }
}