#include "gameui/Integrators/Play.h"
#include "game/assets/GameData.h"

namespace Integrator {
    
    cs::Player Play::getPlayer(std::vector<std::vector<int>> entity, bool changed, const std::vector<cs::Part>& parts) {
        cs::Arsenal::Gun g;
        g.bulletLoading(cs::GameData::bulletLayout());
        if(changed) {
            return cs::Player(std::move(entity), true, {0, 24}, std::move(g), parts);
        }else {
            return cs::Player(std::move(cs::GameData::getUserLayout()), true, {0, 24}, std::move(g), parts);
        }
    } 
}