#include "gameui/Menu_Handlers/MenuRender.h"
#include <iostream>

namespace menu {

    MenuRender::MenuRender() {}

    void MenuRender::setCurrentState(Arrow& arrow) {
        if(!m_navigStack.empty()) {
            int frame = arrow.moveArrow(0, m_navigStack.top()->getOptionLen());
            const auto& topChildren = m_navigStack.top()->getChildren();
            if(frame != -1 && (!topChildren.empty())) {
                Node* topNext = topChildren[frame]; 
                m_navigStack.push(topNext);
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
            callShipMaker(arrow.getIndex());
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

    void MenuRender::callShipMaker(int index) const {
        auto& top = m_navigStack.top();
        top->shipMaker(index);
    }

}