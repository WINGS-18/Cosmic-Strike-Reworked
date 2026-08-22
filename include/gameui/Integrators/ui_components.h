#pragma once

#include "gameui/Menu_Handlers/Menu.h"

namespace components {

    std::unique_ptr<menu::Node> makeMenu();

    menu::Arrow getArrow();

    void beginGame();

}