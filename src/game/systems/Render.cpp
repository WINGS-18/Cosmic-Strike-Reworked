#include "game/systems/Render.h"
#include "engine/Utilities.h"
#include "game/assets/GameData.h"
#include "game/mechanics/Collision.h"
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
        col::Collision collisionCheck(GameData::makeEventPool());
        Utility::hideCursor();
        while(true) {
            ships[0].gunFire();
            frameReset();
            if(count == 10) {
                if(!deadEnemies.empty())
                    GameData::enemyBirth(deadEnemies, aliveEnemies);
                GameData::enemyMove(aliveEnemies);

                for(int i = 0; i < aliveEnemies.size();) {
                    if(!aliveEnemies[i].getIsAlive()) {
                        std::swap(aliveEnemies[i], aliveEnemies.back());

                        aliveEnemies.back().m_coord.y = 0;
                        aliveEnemies.back().getStatsManager().m_current.m_hp = aliveEnemies.back().getStatsManager().m_base.m_hp;
                        deadEnemies.push_back(std::move(aliveEnemies.back()));

                        aliveEnemies.pop_back();
                    }else {
                        i++;
                    }
                }
                count = 0;
            }
            key = Utility::keyGiver();
            if(key == 'q')  break;
            ships[0].userMovement(key);
            collisionCheck.collisionHandler(aliveEnemies, ships);
            insertEntity(ships, parts);
            insertEntity(ships[0].m_playerGun.m_active, parts);
            insertEntity(aliveEnemies, parts);
            insertMessage(ships[0]);
            drawMessage();
            drawFrame();
            Sleep(80);
            Utility::clearScreen();
            count++;
        }
        Utility::displayFinalScore(ships[0].score);
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

    void Render::insertMessage(const Player& p) {
        message[0] = 'S';
        message[1] = 'c';
        message[2] = 'o';
        message[3] = 'r';
        message[4] = 'e';
        message[5] = ' ';
        message[6] = ':';
        message[7] = ' ';
        int temp = p.score;
        message[8] = (temp / 10) + '0';
        message[9] = (temp % 10) + '0';
    }

    void Render::drawMessage() {
        for(char cell : message) {
            std::cout << cell;
        }

        std::cout << "\n\n\n";
    }
}