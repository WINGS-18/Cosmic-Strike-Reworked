#pragma once

#include "gameui/Menu.h"
#include "engine/Utilities.h"
#include <stack>


namespace menu {

    class MenuRender {
    private :
        std::stack<Node*> m_navigStack;
    public:
        MenuRender();

        void menuLoop(std::unique_ptr<Node> root, Arrow& arrow);
    };

}