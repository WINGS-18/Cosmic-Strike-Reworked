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
        
        void setCurrentState(Arrow& arrow);
        void removeCurrentState(Arrow& arrow);
        
        void menuLoop(std::unique_ptr<Node> root, Arrow& arrow);

        void showScreen(const Arrow& arrow) const;
        
    };

}