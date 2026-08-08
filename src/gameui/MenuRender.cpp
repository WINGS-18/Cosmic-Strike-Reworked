#include "gameui/MenuRender.h"

namespace menu {

    MenuRender::MenuRender() {}

    void MenuRender::menuLoop(std::unique_ptr<Node> root, Arrow& arrow) {
        while(true) {
            root->display(arrow);
            char control = Utility::pressKey();
            if(control == 'e')  break;
            arrow.setButtonPressed(control);
            arrow.moveArrow(0, root->getChildren().size() - 1);
            Utility::clearScreen();
        }
    }

}