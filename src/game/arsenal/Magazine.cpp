#include "game/arsenal/Magazine.h"

namespace cs {

    namespace Arsenal {

        Magazine::Magazine(int maxAmmo)
            : m_currAmmo(maxAmmo), m_maxAmmo(maxAmmo) {}

        void Magazine::setState() {
            if(m_currAmmo > 0) {
                m_currState = State::ready;
            }else {
                m_currState = State::reloading;
            }
        }

        void Magazine::decrementMagazineAmmo() noexcept{
            if(m_currState == State::ready)  m_currAmmo--;
        }

    }

}