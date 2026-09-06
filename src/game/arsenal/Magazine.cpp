#include "game/arsenal/Magazine.h"

namespace cs {

    namespace Arsenal {

        Magazine::Magazine(int maxAmmo, int reloadTime)
            : m_currAmmo(maxAmmo), m_maxAmmo(maxAmmo),
              m_reloadTimeInFrames(reloadTime), m_currReloadTimeInFrames(0) {}

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

        void Magazine::reload() noexcept {
            if(m_currState == Magazine::State::reloading) {
                m_currReloadTimeInFrames++;
            }

            if(m_currReloadTimeInFrames == m_reloadTimeInFrames) {
                m_currReloadTimeInFrames = 0;
                m_currAmmo = m_maxAmmo;
            }
        }

        bool Magazine::isReloading() const noexcept {
            if(m_currState == State::reloading) {
                return true;
            }

            return false;
        }

    }

}