#include "game/arsenal/BulletPool.h"

namespace cs::Arsenal {

    // Fix: Parameter lvalue -> rvalue
    void BulletPool::bulletLoading(std::vector<Bullet>&& bul) {
        m_inactive = std::move(bul);
    }

    Bullet BulletPool::inactive_pop(const Eng::Vector2C& host) {
        if (!m_inactive.empty()) {
            Bullet b = m_inactive.back();
            m_inactive.pop_back();
            b.coordinateModifier(host);
            b.m_bul_isAlive = true;
            return b;
        }
        return {0};
    }

    Bullet BulletPool::active_pop() {
        if (!m_active.empty()) {
            Bullet b = m_active.front();
            b.m_bul_isAlive = false;
            m_active.pop_front();
            return b;
        }
        return {0};
    }

    void BulletPool::inactive_push() {
        Bullet b = active_pop();
        if (b.m_val != 0) {
            m_inactive.push_back(b);
        }
    }

    void BulletPool::active_push(const Eng::Vector2C& host) {
        Bullet b = inactive_pop(host);
        if (b.m_val != 0) {
            m_active.push_back(b);
        }
    }

    void BulletPool::bulletAdder(const Eng::Vector2C& host) {
        if (!m_inactive.empty()) {
            active_push(host);
        } else {
            inactive_push();
            active_push(host);
        }
    }

    void BulletPool::bulletMove() {
        if (!m_active.empty()) {
            for (Bullet& b : m_active) {
                if (b.m_bulCoord.y > 0) b.bulletMovement();
            }
        }
    }

    /*
    * This loop ensures that bullets won't tunnel and also
      avoids single tunneling when enemy switches its position.
    */

    /*
    Problem and Fix:
        * Whenever the enemy gets closer to the user, the yCoordinate
          + i sum goes to 24, which is not a valid index for the
          m_active deque.
        * Hence, getting an out-of-bounds access error.

    Fix:
        * Added an extra check to see if the sum of yCoordinate
          and i reaches the size of m_active.
        * If it reaches it, we decrease it by one so it stays in a 
          valid index range.
        * We won't get a problem because the enemy is close to the 
          user, so the bullets are not highly visible to the user.
    */
    void BulletPool::hitBullet(int yCoordinate, int speed) {
        int idx;
        for (size_t i = 0; i <= speed; i++) {
            idx = yCoordinate + i;
            if (idx >= m_active.size()) idx = m_active.size() - 1;
            m_active[idx].m_bul_isAlive = false;
        }
    }
}
