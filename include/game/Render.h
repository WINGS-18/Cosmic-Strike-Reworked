#pragma once

#include "game/Player.h"
#include "game/Enemy.h"
#include <array>

const static int csg_xScale = 5;
const static int csg_yScale = 1;

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
    void Render::insertEntity(const std::vector<Entity>& entities, const std::vector<Part>& parts) {
        for(const auto& e : entities) {
            int filler = e.m_coord.x * xScale;   //tells where to start
            // for(int i = 0; i < e.entityData[0].size(); i++) {
            //     grid[e.m_coord.y][filler + i] = entity[0][i];
            // }
            for(const auto& row : e.entityData) {
                for(for int i = 0; i < row.size(); i++) {
                    frame[e.m_coord.y][filler + i] = parts[row[i]].m_symbol;
                }
            }
        }
    }
}