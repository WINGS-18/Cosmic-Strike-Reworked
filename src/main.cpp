#include "game/Render.h"
#include "game/GameData.h"

int main() {
    cs::Arsenal::Gun g;
    auto bulLay = cs::GameData::bulletLayout();
    g.bulletLoading(bulLay);
    auto parts = cs::GameData::getParts();
    cs::Player user(cs::GameData::getUserLayout(), true, {0, 24}, g);
    std::vector<cs::Player> ships = {user};


    cs::Render::getRenderer().gameLoop(ships, parts);
    return 0;
}