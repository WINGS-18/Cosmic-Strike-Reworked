#include "game/Gun.h"


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
            return b;
        }
        return {0};
    }

    Bullet Gun::active_pop() {
        if(!m_active.empty()) {
            Bullet b = m_active.front();
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
}