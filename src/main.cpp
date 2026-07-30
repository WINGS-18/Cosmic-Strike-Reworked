#include "game/Render.h"
#include "game/GameData.h"
#include <iostream>

int main() {
    cs::Arsenal::Gun g;
    g.bulletLoading(cs::GameData::bulletLayout());
    auto parts = cs::GameData::getParts();
    cs::Player user(cs::GameData::getUserLayout(), true, {0, 24}, g, parts);
    std::vector<cs::Player> ships = {user};
    auto randomPool = cs::GameData::xCoordinateMaker(10);
    std::vector<cs::Enemy> aliveEnemies;
    std::vector<cs::Enemy> deadEnemies;
    cs::GameData::enemyMaker(deadEnemies, cs::GameData::enemLay(), randomPool, parts, 0);
    std::cout << deadEnemies.size() << std::endl;
    std::cout << aliveEnemies.size() << std::endl;
    cs::Render::getRenderer().gameLoop(ships, parts, deadEnemies, aliveEnemies);
    return 0;
}