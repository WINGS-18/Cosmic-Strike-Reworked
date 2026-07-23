#include "game/GameData.h"

namespace cs::GameData {

    const std::vector<Part> getParts() { 
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

    const std::vector<std::vector<int>> getUserLayout() { 
        return {{1, 2, 0, 4, 5}}; 
    } 

    const std::vector<std::vector<int>> getEnemyLayout() { 
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

    const std::vector<Arsenal::Bullet> bulletLayout() { 
        return { 
            {13}, {14}, {13}, {14}, {13}, 
            {14}, {13}, {14}, {13}, {14}, 
            {13}, {14}, {13}, {14}, {13}, 
            {14}, {13}, {14}, {13}, {14} 
        }; 
    }

}