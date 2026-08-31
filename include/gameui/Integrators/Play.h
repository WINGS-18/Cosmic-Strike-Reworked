#pragma once

#include "game/systems/Render.h"

namespace Integrator {

    class Play {
    public:
        Play() = default;

        cs::Player getPlayer(std::vector<std::vector<int>> entity, bool changed, const std::vector<cs::Part>& parts);
        void makeEnemies(std::vector<cs::Enemy>& deadEnemies, const std::vector<cs::Part>& parts);
        void startGame(std::vector<std::vector<int>>& entity, bool changed);
    };

}