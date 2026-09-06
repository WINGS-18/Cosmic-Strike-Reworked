#include "game/systems/MessageRender.h"
#include "game/entities/Player.h"
#include <iostream>

namespace cs {

    void MessageRender::showMessage(const Player& p) {
        if(p.m_playerGun.isReloading()) {
            std::cout << "Reloading..." << "\n";
        }else {
            std::cout << "Score: " << p.score << "\n";
        }
    }

}