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
        Buttons m_pressed;

    public:
        Arrow() = default;
        Arrow(std::vector<char> navigArrow);

        const std::vector<char>& getArrow() const;
        char printNavigArrow(int index) const;

        void setButtonPressed(char key);
        int moveArrow(int start, int end);
    };
}