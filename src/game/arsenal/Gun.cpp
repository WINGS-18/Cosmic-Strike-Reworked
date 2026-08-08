#include "game/arsenal/Gun.h"
#include <iostream>


namespace cs::Arsenal {

    //fix : parameter lvalue -> rvaule
    void Gun::bulletLoading(std::vector <Bullet>&& bul) {
        m_inactive = std::move(bul);
    }

    Bullet Gun::inactive_pop(const Eng::Vector2C& host) {
        if(!m_inactive.empty()) {
            Bullet b = m_inactive.back();
            m_inactive.pop_back();
            b.coordinateModifier(host);
            b.m_bul_isAlive = true;
            return b;
        }
        return {0};
    }

    Bullet Gun::active_pop() {
        if(!m_active.empty()) {
            Bullet b = m_active.front();
            b.m_bul_isAlive = false;
            m_active.pop_front();
            return b;
        }
        return {0};
    }

    void Gun::inactive_push() {
        Bullet b = active_pop();
        if(b.m_val != 0) {
            m_inactive.push_back(b);
        }
    }

    void Gun::active_push(const Eng::Vector2C& host) {
        Bullet b = inactive_pop(host);
        if(b.m_val != 0) {
            m_active.push_back(b);
        }
    }

    void Gun::bulletAdder(const Eng::Vector2C& host) {
        if(!m_inactive.empty()) {
            active_push(host);
        }else {
            inactive_push();
            active_push(host);
        }
    }

    void Gun::bulletMove() {
        if(!m_active.empty()){
            for(Bullet& b : m_active) {
                if(b.m_bulCoord.y > 0)   b.bulletMovement();
            }
        }
    }

    /*
    * This loop ensures that bullets won't tunnel and also
      not avoids single tunneling when enemy switched it's
      position.
    */

    /*
    problem and fix ?

    Problem :
        * Whevener enemy got closer to user the yCoordinate
        + i sum would go to 24 which is not a valid index
        for m_active deque.

        * Hence getting out of bound access error.

    Fix :
        * Now added extra check to see if sum of
        ycoordinate and i reaches size of m_active.
        * If it reaches it we decrease it by one so
        stays in valid index range.
        * We won't get problem because enemy is closer
        to user hence the bullets are not much visible
        to the user.
    */

    void Gun::hitBullet(int yCoordinate, int speed) {
        int idx;
        for(size_t i = 0; i <= speed; i++) {
            idx = yCoordinate + i;
            if(idx == m_active.size())   --idx;
            m_active[idx].m_bul_isAlive = false;
        }
    }
}