#pragma once

#include <vector>
#include <deque>
#include "engine/Vector2C.h"
#include "game/arsenal/Bullet.h"

namespace cs {

    namespace Arsenal {

        class BulletPool {
        public:
            std::deque<Bullet> m_active;
            std::vector<Bullet> m_inactive;

            void bulletLoading(std::vector<Bullet>&& bul);      //loads the bullets acts as an init method

            Bullet inactive_pop(const Eng::Vector2C& host);     //pops the bullet from inactive container

            Bullet active_pop();        //pops the bullet from active container and rerturns it

            void inactive_push();       //pushes the bullet into the inactive container

            void active_push(const Eng::Vector2C& host);        //pushes the bullets into active container

            void bulletAdder(const Eng::Vector2C& host);        //performs rotation

            void bulletMove();    //increments the bullets position making it move

            void hitBullet(int yCoordinate, int speed);
        };

    }

}