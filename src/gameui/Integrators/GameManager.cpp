#include "gameui/Integrators/ui_components.h"
#include "gameui/Integrators/Play.h"
#include "gameui/Integrators/GameManager.h"
#include "gameui/Menu_Handlers/MenuRender.h"

void gamr::GameManager::startGame(std::vector<std::vector<int>>& entity, bool changed) {
    auto root = components::makeMenu();
    auto arrow = components::getArrow();
    menu::MenuRender m;
    m.menuLoop(std::move(root), arrow);
    Integrator::Play p;
    p.startGame(entity, changed);
}