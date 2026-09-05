#pragma once

namespace cs {

    namespace Arsenal {

        class Magazine {
        private:
            int m_maxAmmo;
            int m_currAmmo;
        
        public:
            enum class State {
                reloading,
                ready
            };

            State m_currState = State::ready;
            Magazine() = default;
            Magazine(int maxAmmo);

            void setState();

            void decrementMagazineAmmo() noexcept;
        };

    }

}