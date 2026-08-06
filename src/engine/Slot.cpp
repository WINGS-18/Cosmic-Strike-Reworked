#include "engine/Slot.h"

namespace Eng {

    Slot::Slot(int v1, int v2)
        : m_first(v1), m_second(v2) {}

    Slot::Slot(int v)
        : m_first(v) {}

    int Slot::operator[] (int index) const{
        if(m_first != -1 && m_second != -1) {
            switch (index) {
                case 0:
                    return m_first;
                    break;

                case 1:
                    return m_second;
                    break;
                
                default:
                    break;
            }
        }

        return m_first;
    }


    bool Slot::single() const {
        if(m_first != -1 && m_second != -1)
            return false;
        
        return true;
    }
}