#pragma once

#include "game/Player.h"
#include "game/Enemy.h"
#include <array>

namespace cs{

    class Render {
    private:    
        Render();

    public:
        std::array<std::array<char, 25>, 25> frame;
        
        static Render& getRenderer();

        template <typename Entity>
        void insertEntity(const std::vector<Entity>& e, const std::vector<Part>& parts);
        template <typename Entity>
        void insertEntity(const std::deque<Entity>& e, const std::vector<Part>& parts);
        void frameReset();
        void drawFrame();
    };

    template <typename Entity>
    void Render::insertEntity(const std::vector<Entity>& e, const std::vector<Part>& parts) {
        
    }
}