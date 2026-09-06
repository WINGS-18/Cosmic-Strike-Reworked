#pragma once
#include <string_view>

namespace cs {

    class Player;

    class MessageRender {
    public:
        MessageRender() = default;

        void showMessage(const Player& p);
    };

}