#include "game/Render.h"
#include "game/GameData.h"
#include <iostream>

int main() {
    cs::Arsenal::Gun g;
    auto bulLay = cs::GameData::bulletLayout();
    g.bulletLoading(bulLay);
    auto parts = cs::GameData::getParts();
    cs::Player user(cs::GameData::getUserLayout(), true, {0, 24}, g);
    std::vector<std::vector<int>> enemLay = {{14, 1, 10, 5, 14}};
    std::vector<cs::Player> ships = {user};
    auto randomPool = cs::GameData::xCoordinateMaker(10);
    std::vector<cs::Enemy> aliveEnemies;
    std::vector<cs::Enemy> deadEnemies;
    cs::GameData::enemyMaker(deadEnemies, enemLay, randomPool, parts, 0);
    for(int i = 0; i < 10; i++){
        cs::GameData::enemyBirth(deadEnemies, aliveEnemies);
    }
    std::cout << deadEnemies.size() << std::endl;
    std::cout << aliveEnemies.size() << std::endl;
    //cs::Render::getRenderer().gameLoop(ships, parts);
    return 0;
}