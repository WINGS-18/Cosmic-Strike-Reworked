#include "game/systems/MessageRender.h"
#include "game/entities/Player.h"
#include <iostream>

namespace cs {

    void MessageRender::showMessage(const Player& p) {
        if(p.getPlayerGun().isReloading()) {
            std::cout << "Reloading...\n";
        }else {
            std::cout << "Score: " << p.getScore() << "\n";
        }

        std::cout << "\n" << p.getPlayerGun().getNumberOfBullets() << " / " 
            << p.getPlayerGun().getTotalNumberOfBullets() << "\n";
    }

}