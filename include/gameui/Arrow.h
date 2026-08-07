#pragma once

#include <vector>

namespace menu {

    enum class Buttons {
        ENTER = 13,
        PAGE_UP = 33,
        PAGE_DOWN = 34
    };


    class Arrow {
    private:
        std::vector<char> m_navigArrow;
        int m_arrIndex = 0;

    public:
        Arrow() = default;
        Arrow(std::vector<char> navigArrow);

        Arrow& getArrow() const;
        void moveArrow(int key) {
            switch(key) {
                case Buttons::ENTER :
            }
        }
    };
}