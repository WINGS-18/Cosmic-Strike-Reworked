#include "gameui/Integrators/ui_components.h"
#include "gameui/Integrators/Play.h"
#include "gameui/Menu_Handlers/MenuRender.h"


std::unique_ptr<menu::Node> components::makeMenu() {
    auto root = std::make_unique<menu::Node> ("Menu");
    auto play = std::make_unique<menu::PlayObject> ("Play");
    auto workshop = std::make_unique<menu::Node> ("Workshop");
    auto shipyard = std::make_unique<menu::Node> ("Shipyard");
    auto loadout = std::make_unique<menu::Loadout> ("Loadout");
    auto core = std::make_unique<menu::Warehouse> ("Core", Eng::Slot{2}, std::vector<Eng::Slot>{Eng::Slot{3}, Eng::Slot{7}, Eng::Slot{10}, Eng::Slot{12}});
    auto body = std::make_unique<menu::Warehouse> ("Body", Eng::Slot{1, 3}, std::vector<Eng::Slot>{Eng::Slot{2, 4}, Eng::Slot{6, 8}, Eng::Slot{9, 11}});
    auto wing = std::make_unique<menu::Warehouse> ("Wing", Eng::Slot{0, 4}, std::vector<Eng::Slot>{Eng::Slot{1, 5}, Eng::Slot{12, 12}});
    shipyard->addChild(std::move(core));
    shipyard->addChild(std::move(body));
    shipyard->addChild(std::move(wing));
    workshop->addChild(std::move(shipyard));
    workshop->addChild(std::move(loadout));
    root->addChild(std::move(play));
    root->addChild(std::move(workshop));

    return root;
}

menu::Arrow components::getArrow() {
    return  menu::Arrow(std::vector<char> {'>', ' ', ' ', ' ', ' '});
}

void components::beginGame() {
    auto root = makeMenu();
    auto arrow = getArrow();
    menu::MenuRender mr;
    
    root = std::move(mr.menuLoop(std::move(root), arrow));
}