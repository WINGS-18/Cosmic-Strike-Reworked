#include "game/Render.h"
#include "engine/Utilities.h"
#include "game/GameData.h"
#include <windows.h>
#include <iostream>

namespace cs {

    Render::Render() {}     //constructor

    Render& Render::getRenderer() {     //returns reference of it's own object
        static Render r;
        return r;
    }

    void Render::gameLoop(std::vector<Player>& ships, const std::vector<Part>& parts, std::vector<Enemy>& deadEnemies, std::vector<Enemy>& aliveEnemies) {
        char key = '\0';
        int count = 0;
        Utility::hideCursor();
        while(true) {
            ships[0].gunFire();
            frameReset();
            if(count == 10) {
                if(!deadEnemies.empty())
                    GameData::enemyBirth(deadEnemies, aliveEnemies);
                GameData::enemyMove(aliveEnemies);
                count = 0;
            }
            key = Utility::keyGiver();
            if(key == 'e')  break;
            ships[0].userMovement(key);
            insertEntity(ships, parts);
            insertEntity(ships[0].m_playerGun.m_active, parts);
            insertEntity(aliveEnemies, parts);
            drawFrame();
            Sleep(80);
            Utility::clearScreen();
            count++;
        }
        Utility::showCursor();
    }

    void Render::drawFrame() {      //draws the frame/grid
        for(const auto& row : frame) {
            for(const auto& cell : row) {
                std::cout << cell;
            }
            std::cout << "\n";
        }
    }

    void Render::frameReset() {     //resets the frame with blank space chars
        for(auto& row : frame) {
            std::fill(row.begin(), row.end(), ' ');
        }
    }
}