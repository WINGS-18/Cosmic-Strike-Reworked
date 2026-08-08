#include "gameui/MenuRender.h"
#include <iostream>

namespace menu {

    MenuRender::MenuRender() {
        //std::cout << "created";
    }

    void MenuRender::menuLoop(std::unique_ptr<Node> root, Arrow& arrow) {
        //std::cout << "Entered";
        while(true) {
            root->display(arrow);
            char control = Utility::pressKey();
            if(control == 'e')  break;
            arrow.setButtonPressed(control);
            arrow.moveArrow(0, root->getChildren().size());
            Utility::clearScreen();
        }
    }

}