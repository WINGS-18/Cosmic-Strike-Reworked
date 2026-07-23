/*

@File GameData.h :

    - Provides global functions that return
      entity layouts, bullets layouts etc.,
    - Wrapped in GameData namespace.

*/
#pragma once

#include "game/Player.h"
#include "game/Enemy.h"

namespace cs::GameData {

    const std::vector<Part> getParts();     //returns all game parts
    const std::vector<std::vector<int>> getUserLayout();        //returns user appearence map(vector)
    const std::vector<std::vector<int>> getEnemyLayout();       //returns enemy appearence map(vector)

    const std::vector<Arsenal::Bullet> bulletLayout();      //returns bullet map(vector)

}