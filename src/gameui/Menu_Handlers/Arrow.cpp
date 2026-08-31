#include "gameui/Menu_Handlers/Arrow.h"
#include <iostream>

namespace menu {

    Arrow::Arrow(std::vector<char> navigArrow)
        : m_navigArrow(std::move(navigArrow)) {}

    const std::vector<char>& Arrow::getArrow() const {
        return m_navigArrow;
    }

    char Arrow::printNavigArrow(int index) const {
        return m_navigArrow[index];
    }

    void Arrow::set_arrIndex(int idx) {m_arrIndex = idx;}

    void Arrow::setButtonPressed(char key) {
        switch (key) {
            case 32 :
                m_pressed = Buttons::ENTER;
                break;

            case 'w' :
                m_pressed = Buttons::PAGE_UP;
                break;

            case 's' :
                m_pressed = Buttons::PAGE_DOWN;
                break;
            
            default:
                m_pressed = Buttons::NONE;
                break;
        }
    }

    int Arrow::moveArrow(int start, int end) {
        int oldIndex = 0;
        switch (m_pressed) {
            case Buttons::ENTER :
                oldIndex = m_arrIndex;
                m_arrIndex = 0;
                swapArrow(oldIndex);
                return oldIndex;
                break;
                
            case Buttons::PAGE_UP :
                if(m_arrIndex != start) {
                    swapArrow(m_arrIndex--);
                }
                break;
            
            case Buttons::PAGE_DOWN :
                if(m_arrIndex != end) {
                    swapArrow(m_arrIndex++);
                }
                break;

            default:
                break;
        }
        return -1;
    } 

    void Arrow::swapArrow(int oldIndex) {
        std::swap(m_navigArrow[oldIndex], m_navigArrow[m_arrIndex]);
    }

    void Arrow::setArrow() {
        int oldIndex = m_arrIndex;
        m_arrIndex = 0;
        swapArrow(oldIndex);
    }

    int Arrow::getIndex() const {
        return m_arrIndex;
    }

}