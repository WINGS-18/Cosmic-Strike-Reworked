#include "gameui/MenuRender.h"
#include <iostream>

namespace menu {

    MenuRender::MenuRender() {}

    void MenuRender::setCurrentState(Arrow& arrow) {
        if(!m_navigStack.empty()) {
            int frame = arrow.moveArrow(0, m_navigStack.top()->getOptionLen());
            if(frame != -1) {
                m_navigStack.push(m_navigStack.top()->getChildren()[frame]);
            }
        }
    }

    void MenuRender::removeCurrentState(Arrow& arrow) {
        if(!m_navigStack.empty()) {
            m_navigStack.pop();
            arrow.setArrow();
        }
    }

    void MenuRender::menuLoop(std::unique_ptr<Node> root, Arrow& arrow) {
        m_navigStack.push(root.get());
        char control;
        while(true) {
            showScreen(arrow);
            control = Utility::pressKey();
            arrow.setButtonPressed(control);
            if(control == 'e')  removeCurrentState(arrow);
            if(control == 'd')  break;
            setCurrentState(arrow);
            Utility::clearScreen();
        }
    }

    void MenuRender::showScreen(const Arrow& arrow) const {
        if(!m_navigStack.empty()) {
            auto& top = m_navigStack.top();
            top->display(arrow);
        }
    }

}