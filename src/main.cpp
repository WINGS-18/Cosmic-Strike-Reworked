#include "game/systems/Render.h"
#include "game/assets/GameData.h"
#include "gameui/Menu.h"
#include "gameui/MenuRender.h"
#include <iostream>


int main() {
//     cs::Arsenal::Gun g;
//     g.bulletLoading(cs::GameData::bulletLayout());
//     auto parts = cs::GameData::getParts();
//     cs::Player user(cs::GameData::getUserLayout(), true, {0, 24}, g, parts);
//     std::vector<cs::Player> ships = {user};
//     auto randomPool = cs::GameData::xCoordinateMaker(10);
//     std::vector<cs::Enemy> aliveEnemies;
//     std::vector<cs::Enemy> deadEnemies;
//     cs::GameData::enemyMaker(deadEnemies, cs::GameData::enemLay(), randomPool, parts, 0);
//     std::cout << deadEnemies.size() << std::endl;
//     std::cout << aliveEnemies.size() << std::endl;
//     cs::Render::getRenderer().gameLoop(ships, parts, deadEnemies, aliveEnemies);
    auto root = std::make_unique<menu::Node> ("Menu");
    auto play = std::make_unique<menu::Node> ("Play");
    auto workshop = std::make_unique<menu::Node> ("Workshop");
    auto shipyard = std::make_unique<menu::Node> ("Shipyard");
    auto loadout = std::make_unique<menu::Loadout> ("Loadout");
    auto core = std::make_unique<menu::Warehouse> ("Core", Eng::Slot{2}, std::vector<Eng::Slot>{Eng::Slot{3}, Eng::Slot{7}, Eng::Slot{10}, Eng::Slot{12}});
    auto body = std::make_unique<menu::Warehouse> ("Body", Eng::Slot{1, 3}, std::vector<Eng::Slot>{Eng::Slot{2, 4}, Eng::Slot{6, 8}, Eng::Slot{9, 11}});
    auto wing = std::make_unique<menu::Warehouse> ("Wing", Eng::Slot{0, 4}, std::vector<Eng::Slot>{Eng::Slot{1, 5}, Eng::Slot{12, 12}});
    menu::Arrow a(std::vector<char> {'>', ' ', ' ', ' ', ' '});
    shipyard->addChild(std::move(core));
    shipyard->addChild(std::move(body));
    shipyard->addChild(std::move(wing));
    workshop->addChild(std::move(shipyard));
    workshop->addChild(std::move(loadout));
    root->addChild(std::move(play));
    root->addChild(std::move(workshop));
    //root->display(a);
    menu::MenuRender m;
    m.menuLoop(std::move(root), a);
    return 0;
}