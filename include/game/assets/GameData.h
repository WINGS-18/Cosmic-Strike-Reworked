/*

@File GameData.h :

    - Provides global functions that return
      entity layouts, bullets layouts etc.,
    - Wrapped in GameData namespace.

*/
#pragma once

#include "game/entities/Player.h"
#include "game/entities/Enemy.h"
#include "game/mechanics/Event.h"

namespace cs::GameData {

    std::vector<Part> getParts();     //returns all game parts
    std::vector<std::vector<int>> getUserLayout();        //returns user appearence map(vector)
    std::vector<std::vector<int>> getEnemyLayout();       //returns enemy appearence map(vector)
    std::vector<std::vector<int>> enemLay();        //returns enemy appearence map(vector)
    std::vector<col::Event> makeEventPool();        //returns default pool of Event instances(vector)

    std::vector<Arsenal::Bullet> bulletLayout();      //returns bullet map(vector)
    std::vector<int> xCoordinateMaker(int n);       //returns vector of 'n' random numbers

    /*
    Constructs enemy instances and pushes them into deadEnemies vector.
    */
    void enemyMaker(std::vector<Enemy>& deadEnemies, const std::vector<std::vector<int>>& enemyData, const std::vector<int>& randomPool, const std::vector<Part>& parts, int y);

    /*
    Pushes enemies from dead vector to aliveEnemies vector. Then make them alive.
    */
    void enemyBirth(std::vector<Enemy>& deadEnemies, std::vector<Enemy>& aliveEnemies);

    void enemyMove(std::vector<Enemy>& aliveEnemies);       //updates enemies coordinate to make them move.

}