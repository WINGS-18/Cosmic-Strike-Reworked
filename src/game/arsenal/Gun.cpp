#include "game/arsenal/Gun.h"

namespace cs {

    namespace Arsenal {

        Gun::Gun(int maxAmmo)
            : m_magazine(maxAmmo) {}

        void Gun::fire(const Eng::Vector2C& host) {
            m_magazine.setState();
            m_magazine.decrementMagazineAmmo();
            m_pool.bulletMove();
            if(m_magazine.m_currState == Magazine::State::ready) {
                m_pool.bulletAdder(host);
            }else {
                m_pool.inactive_push();
            }
        }

        BulletPool& Gun::getPool() noexcept {return m_pool;}

    }

}