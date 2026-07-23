/* 
 * @file Render.h
 * class Render:
 *  - Render is a singleton class.
 *  - Acts as the central graphics controller for drawing the game state to the console.
 *  - Uses a 2D char array (`frame`) as a back-buffer that is reset and redrawn every frame.
 *  - Features advanced coordinate mapping:
 *    - Vector overload: Draws large, multi-part entities (like players) using raw row-by-row data.
 *    - Deque overload: Optimized for small, single-character entities (like bullets) centered in the scale block.
 */


#pragma once

#include "game/Player.h"
#include "game/Enemy.h"
#include <array>

//Axes multipliers : 
const static int csg_xScale = 5;
const static int csg_yScale = 1;

namespace cs {

    /*
        SINGLETON :
    */

    class Render {
    private:    
        Render();
        /*
        * Constructor in private access specifier
          ensures that it can be only accessed by
          class.
        */

    public:
        std::array<std::array<char, 25>, 25> frame;
        
        static Render& getRenderer();

        /*
        * The getRenderer() function returns instance of
          the Render class.
        * As it returns a static instance meaning that it
          creates only 1 instance.
        * It is a global instance.
        * This way only getRenderer() can provide you a 
          render instance.
        * As the constructor is in private so only accessible
          inside the class. Hence, no one can create the instance
          outside this class.
        */

        //inserts the entities into the m_frame.
        template <typename Entity>
        void insertEntity(const std::vector<Entity>& e, const std::vector<Part>& parts);
        template <typename Entity>
        void insertEntity(const std::deque<Entity>& e, const std::vector<Part>& parts);

        void frameReset();      //reset the grid to blank spaces
        void drawFrame();       //draws the frame on the terminal
        void gameLoop(std::vector<Player>& ships, const std::vector<Part>& parts);        //main loop that runs the game
    };

    template <typename Entity>
    void Render::insertEntity(const std::vector<Entity>& entities, const std::vector<Part>& parts) {
        for(const auto& e : entities) {
            int filler = e.m_coord.x * csg_xScale;   //tells where to start
            for(const auto& row : e.getEntityData()) {
                for(int i = 0; i < row.size(); i++) {
                    frame[e.m_coord.y][filler + i] = parts[row[i]].m_symbol;
                }
            }
        }
    }

    template <typename Entity>
    void Render::insertEntity(const std::deque<Entity>& entities, const std::vector<Part>& parts) {
        for(const auto& b : entities) {
            frame[b.m_bulCoord.y][(b.m_bulCoord.x * csg_xScale) + 2] = parts[b.m_val].m_symbol;
        }
    }
}