#pragma once
#include <vector>

namespace gamr {

    class GameManager {
    public:
        GameManager() = default;
        void startGame(std::vector<std::vector<int>>& entity, bool changed);
    };

}