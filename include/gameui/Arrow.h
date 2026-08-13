// file @ Arrow.h :
// 
// * This Arrow class provides instance that
//   stores arrow inside a vector.
// * It is rendered as each element of m_navigArrow
//   in new line.
// * The index of arrow in that vector is actually
//   the option which it is pointing.
// * If 
// 
// 
// ---> How it looks :
// 
// > Core
//   Body
//   Wings
// 
// * So here currently the arrow is at Core which means
//   m_avigArrow looks like {'>', ' ', ' ',.....}.
// * When user clicks down key : m_pressed Buttons instance
//   is set to PAGE_DOWN.
// * Now a special functin increments the m_arrIndex(it keeps
//   track of arrow inside the m_navigArrow) and swaps old 
//   m_arrIndex element with new m_arrIndex.
// * Hence it'll look like this...
// 
//   Core
// > Body
//   Wings
// 
// * Pressing enter resets m_arrIndex to 0 and the arrow to
//   index m_arrIndex. Also returns old m_arrIndex.
// * Using that return value we can perfectly put child node
//   of that vector index of tree on the stack.


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
        void set_arrIndex(int idx);
        void setButtonPressed(char key);
        int moveArrow(int start, int end);
        void swapArrow(int oldIndex);
        void setArrow();
    };
}