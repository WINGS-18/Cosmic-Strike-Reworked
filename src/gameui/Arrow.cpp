#include "gameui/Arrow.h"
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

    void Arrow::setButtonPressed(char key) {
        std::cout << key;
        switch (key) {
            case 13 :
                m_pressed = Buttons::ENTER;
                break;

            case 'a' :
                m_pressed = Buttons::PAGE_UP;
                break;

            case 'b' :
                m_pressed = Buttons::PAGE_DOWN;
                break;
            
            default:
                break;
        }
    }

    int Arrow::moveArrow(int start, int end) {
        int oldIndex = 0;
        switch (m_pressed) {
            case Buttons::ENTER :
                oldIndex = m_arrIndex;
                m_arrIndex = 0;
                return oldIndex;
                break;
            
            case Buttons::PAGE_UP :
                if(m_arrIndex != start) {
                    m_navigArrow[m_arrIndex--] = ' ';
                    m_navigArrow[m_arrIndex] = '>';
                }
                break;
            
            case Buttons::PAGE_DOWN :
                if(m_arrIndex != end) {
                    m_navigArrow[m_arrIndex++] = ' ';
                    m_navigArrow[m_arrIndex] = '>';
                }
                break;

        default:
            break;
        }
        return -1;
    } 

}