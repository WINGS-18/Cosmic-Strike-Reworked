#include "game/systems/Render.h"
#include "engine/Utilities.h"
#include "game/assets/GameData.h"
#include "game/mechanics/Collision.h"
#include <windows.h>


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
            ships[0].m_playerGun.fire(ships[0].m_coord);
            frameReset();
            if(count == 20) {
                if(!deadEnemies.empty())
                    GameData::enemyBirth(deadEnemies, aliveEnemies);
                GameData::enemyMove(aliveEnemies);

                GameData::transferDeadEnemies(aliveEnemies,deadEnemies);
                
                count = 0;
            }
            key = Utility::keyGiver();
            if(key == 'q')  break;
            ships[0].userMovement(key);
            collisionCheck.collisionHandler(aliveEnemies, ships);
            insertEntity(ships, parts);
            insertEntity(ships[0].m_playerGun.getPool().m_active, parts);
            insertEntity(aliveEnemies, parts);
            m_messages.showMessage(ships[0]);
            drawFrame();
            Sleep(60);
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


}