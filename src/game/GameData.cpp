#include "game/GameData.h"
#include <random>

namespace cs::GameData {

    std::vector<Part> getParts() { 
        return {
            Part('^', 25, 30, 0, 0), 
            Part('<', 25, 5, 5, 0), 
            Part('{', 25, 5, 5, 1), 
            Part('T', 40, 0, 10, 10), 
            Part('}', 25, 5, 5, 1), 
            Part('>', 25, 5, 5, 0), 
            Part('(', 30, 0, 20, 3), 
            Part('@', 30, 10, 0, 20), 
            Part(')', 30, 0, 20, 3), 
            Part('[', 30, 0, 10, 3), 
            Part('*', 20, 5, 5, 10), 
            Part(']', 30, 0, 10, 5), 
            Part('-', 40, 20, 15, 10), 
            Part('!', 0, 0, 0, 0), 
            Part(' ', 0, 0, 0, 0) 
        }; 
    } 

    std::vector<std::vector<int>> getUserLayout() { 
        return {{1, 2, 0, 4, 5}}; 
    } 

    std::vector<std::vector<int>> getEnemyLayout() { 
        return {{14, 1, 12, 5, 14}}; 
    }
    
    /*
    Constructor overload resolution failure :

        Error message : "no instance of constructor [...] matches the argument list".

        If such a errror arrives it means that the complier cannot determine the type
        and is getting confused with the nested braces.

        example :

            const std::vector<Arsenal::Bullet> bulletLayout() { 
                return { 
                    {13, {0, 1}}, {14, {0, 1}}, {13, {0, 1}}, {14, {0, 1}}, {13, {0, 1}}, 
                    {14, {0, 1}}, {13, {0, 1}}, {14, {0, 1}}, {13, {0, 1}}, {14, {0, 1}}, 
                    {13, {0, 1}}, {14, {0, 1}}, {13, {0, 1}}, {14, {0, 1}}, {13, {0, 1}}, 
                    {14, {0, 1}}, {13, {0, 1}}, {14, {0, 1}}, {13, {0, 1}}, {14, {0, 1}} 
                }; 
            }

    Fix : Given below.
    

    std::vector<Arsenal::Bullet> bulletLayout() { 
        return { 
            Arsenal::Bullet{13, {0, 1}}, Arsenal::Bullet{14, {0, 1}}, Arsenal::Bullet{13, {0, 1}}, Arsenal::Bullet{14, {0, 1}}, Arsenal::Bullet{13, {0, 1}}, 
            Arsenal::Bullet{14, {0, 1}}, Arsenal::Bullet{13, {0, 1}}, Arsenal::Bullet{14, {0, 1}}, Arsenal::Bullet{13, {0, 1}}, Arsenal::Bullet{14, {0, 1}}, 
            Arsenal::Bullet{13, {0, 1}}, Arsenal::Bullet{14, {0, 1}}, Arsenal::Bullet{13, {0, 1}}, Arsenal::Bullet{14, {0, 1}}, Arsenal::Bullet{13, {0, 1}}, 
            Arsenal::Bullet{14, {0, 1}}, Arsenal::Bullet{13, {0, 1}}, Arsenal::Bullet{14, {0, 1}}, Arsenal::Bullet{13, {0, 1}}, Arsenal::Bullet{14, {0, 1}} 
        }; 
    }
    */

    std::vector<Arsenal::Bullet> bulletLayout() { 
        return { 
            {13}, {14}, {13}, {14}, {13}, 
            {14}, {13}, {14}, {13}, {14}, 
            {13}, {14}, {13}, {14}, {13}, 
            {14}, {13}, {14}, {13}, {14},
            {13}, {14}, {13}, {14}
        }; 
    }

    std::vector<std::vector<int>> enemLay() {return {{14, 1, 10, 5, 14}};}

    std::vector<col::Event> makeEventPool() {
        std::vector<col::Event> eventPool(10);
        return eventPool;
    }

    std::vector<int> xCoordinateMaker(int n) {
        std::vector <int> randomPool;
        std::random_device rd;
        std::uniform_int_distribution<int> dist(0,4);
        for(int i = 0; i < n; i++){
            randomPool.push_back(dist(rd));
        }
        return randomPool;
    }

    void enemyMaker(std::vector<Enemy>& deadEnemies, const std::vector<std::vector<int>>& enemyData, const std::vector<int>& randomPool, const std::vector<Part>& parts, int y) {
        st::StatsPool stats(enemyData, parts);
        for(const auto randNum : randomPool){
            Enemy e(enemyData, false, {randNum, y});
            deadEnemies.push_back(e);
        }
    }

    void enemyBirth(std::vector<Enemy>& deadEnemies, std::vector<Enemy>& aliveEnemies) {
        auto obj = deadEnemies.back();
        obj.makeAlive();
        aliveEnemies.push_back(obj);
        deadEnemies.pop_back();
    }

    void enemyMove(std::vector<Enemy>& aliveEnemies) {
        for(auto& enemy : aliveEnemies) {
            if(enemy.m_coord.y < 24)
                enemy.m_coord.yCoordinateUpdate();
        }
    }
}