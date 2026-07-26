#pragma once

#include "game/Player.h"
#include "game/Enemy.h"

namespace cs {

    namespace col {
        
        class Collision {
        public:
            bool didCollide = false;

            Collision();

            bool collisionDetector(std::vector<Player>& user, std::vector<Enemy>& enemies);
            
        };
    }
}