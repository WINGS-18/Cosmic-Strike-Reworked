#pragma once

namespace cs {

    namespace Arsenal {

        class Magazine {
        private:
            int m_maxAmmo;
            int m_currAmmo;
            int m_reloadTimeInFrames;
            int m_currReloadTimeInFrames;
        
        public:
            enum class State {
                reloading,
                ready,
                firing
            };

            State m_currState = State::ready;
            Magazine() = default;
            Magazine(int maxAmmo, int reloadTime);

            void setState(char key);

            void decrementMagazineAmmo() noexcept;

            void reload() noexcept;

            bool isReloading() const noexcept;

            int getCurrAmmo() const noexcept;

            int getMaxAmmo() const noexcept;
        };

    }

}