// @file MenuRender.h : 

// * This renders the Menu.
// * We always call display functions of what is there on the top of m_navigStack.
// * m_navigStack is a stack on which the Node, Warehouse classes objects are pushed.
// * Whenever user clicks 'e' to get back, the top is popped from the stack.
// * Hence, we get previous section.
// * This model essentially makes a undo redo system.
// * We use a tree based navigation where branch where it should move that tree node is pushed into the stack.
// * The member functions here warp multiple functions of the Node, Warehouse instances.

#pragma once

#include "gameui/Menu_Handlers/Menu.h"
#include "engine/Utilities.h"
#include <stack>


namespace menu {

    class MenuRender {
    private:
        std::stack<Node*> m_navigStack;
    public:
        MenuRender();
        
        void setCurrentState(Arrow& arrow);
        void removeCurrentState(Arrow& arrow);
        
        void menuLoop(std::unique_ptr<Node> root, Arrow& arrow);

        void showScreen(const Arrow& arrow) const;
        
        void callShipMaker(int index) const;

    };

}