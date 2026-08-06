#pragma once

namespace Eng {

    class Slot {
    private:
        int m_first = -1;
        int m_second = -1;
    public:
        Slot() = default;
        Slot(int v1, int v2);
        Slot(int v1);

        int operator[] (int index) const;

        bool single() const;
    };

}