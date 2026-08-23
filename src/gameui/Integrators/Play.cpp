#include "gameui/Integrators/Play.h"
#include "game/assets/GameData.h"

namespace Integrator {
    
    cs::Player Play::getPlayer(std::vector<std::vector<int>> entity, bool changed, const std::vector<cs::Part>& parts) {
        cs::Arsenal::Gun g;
        g.bulletLoading(cs::GameData::bulletLayout());
        if(changed) {
            return cs::Player(std::move(entity), true, {0, 24}, std::move(g), parts);
        }else {
            return cs::Player(std::move(cs::GameData::getUserLayout()), true, {0, 24}, std::move(g), parts);
        }
    }

    void Play::makeEnemies(std::vector<cs::Enemy>& deadEnemies, const std::vector<cs::Part>& parts) {
        cs::GameData::enemyMaker(deadEnemies, cs::GameData::getEnemyLayout(), cs::GameData::xCoordinateMaker(10), parts, 0);
    }

    void Play::startGame(std::vector<std::vector<int>>& entity, bool changed) {
        auto parts = cs::GameData::getParts();
        auto player = getPlayer(entity, changed, parts);
        std::vector<cs::Player> ships = {player};
        std::vector<cs::Enemy> aliveEnemies;
        std::vector<cs::Enemy> deadEnemies;
        makeEnemies(deadEnemies, parts);
        cs::Render::getRenderer().gameLoop(ships, parts, deadEnemies, aliveEnemies);
    }

}