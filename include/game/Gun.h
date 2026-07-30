/*
@file Gun.h:

* All entities in the game might use guns, hence a dedicated class for gun.
* Gun class basically has it's members that store bullets(Bullet.h).

* What's new? :
    - This completely eliminates the heap allocations every frame.
    - Used 2 containers that are m_active and m_inactive.
    - m_ctive stores the bullets that are appearing on the screen and
      the ones which haven't got hit by obstacles.
    - m_inactive contains the bullets which aren't on the screen, which
      got hit by some obstacles.
    - we transfer these bullets between m_active to m_inactive which allows no
      heap allocations for Bullet.

* Data Structures(DS) choice :
    - Used 2 different DS std::vector for m_inactive and std::deque for m_active.
    - Used std::deque for m_active, because we need pop_front() operation, which
      is necessary to maintain the order of the bullets.
    - Used std::vector for m_inactive because, here all bullets are same now hence,
      no need of maintaining order and pop_back() can be used.
    - As we know std::vector elements are in a contigous block all elements are side
      by side, it helps in efficient chaching.
*/



#pragma once
#include <vector>
#include <deque>
#include "engine/Vector2C.h"
#include "game/Bullet.h"

namespace cs {

    namespace Arsenal {

        class Gun {
          public:
            std::deque<Bullet> m_active;
            std::vector<Bullet> m_inactive;

            Gun() {}

            void bulletLoading(std::vector<Bullet>&& bul);      //loads the bullets acts as an init method

            Bullet inactive_pop(const Eng::Vector2C& host);     //pops the bullet from inactive container

            Bullet active_pop();        //pops the bullet from active container and rerturns it

            void inactive_push();       //pushes the bullet into the inactive container

            void active_push(const Eng::Vector2C& host);        //pushes the bullets into active container

            void bulletAdder(const Eng::Vector2C& host);        //performs rotation

            void bulletMove();    //increments the bullets position making it move

        };
    }
}