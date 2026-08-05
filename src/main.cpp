#include "game/systems/Render.h"
#include "game/assets/GameData.h"
#include "gameui/Menu.h"
#include <iostream>
#include <memory>

int main() {
    // cs::Arsenal::Gun g;
    // g.bulletLoading(cs::GameData::bulletLayout());
    // auto parts = cs::GameData::getParts();
    // cs::Player user(cs::GameData::getUserLayout(), true, {0, 24}, g, parts);
    // std::vector<cs::Player> ships = {user};
    // auto randomPool = cs::GameData::xCoordinateMaker(10);
    // std::vector<cs::Enemy> aliveEnemies;
    // std::vector<cs::Enemy> deadEnemies;
    // cs::GameData::enemyMaker(deadEnemies, cs::GameData::enemLay(), randomPool, parts, 0);
    // std::cout << deadEnemies.size() << std::endl;
    // std::cout << aliveEnemies.size() << std::endl;
    // cs::Render::getRenderer().gameLoop(ships, parts, deadEnemies, aliveEnemies);
    auto root = std::make_unique<menu::Node> ("Menu");
    auto play = std::make_unique<menu::Node> ("Play");
    auto workshop = std::make_unique<menu::Node> ("Workshop");
    menu::addNode(root.get(), play.get());
    menu::addNode(root.get(), workshop.get());
    root->display();
    return 0;
}