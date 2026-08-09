#include "gameui/MenuRender.h"

namespace menu {

    MenuRender::MenuRender() {}

    void MenuRender::menuLoop(std::unique_ptr<Node> root, Arrow& arrow) {
        m_navigStack.push(root.get());
        while(true) {
            if(!m_navigStack.empty()) {
                auto& top = m_navigStack.top();
                top->display(arrow);
            }
            char control = Utility::pressKey();
            if(control == 'e')  break;
            arrow.setButtonPressed(control);
            int frame = arrow.moveArrow(0, m_navigStack.top()->getChildren().size() - 1);
            if(frame != -1) {
                m_navigStack.push(root->getChildren()[frame]);
            }
            Utility::clearScreen();
        }
    }

}