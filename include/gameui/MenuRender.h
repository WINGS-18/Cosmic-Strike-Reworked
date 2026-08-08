#pragma once

#include "gameui/Menu.h"
#include "engine/Utilities.h"


namespace menu {

    class MenuRender {
    public:
        MenuRender();

        void menuLoop(std::unique_ptr<Node> root, Arrow& arrow);
    };

}