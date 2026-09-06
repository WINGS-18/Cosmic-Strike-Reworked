/*
@file Character.h

* class Character:
    - Every playble entities have some things in common like i'd,
      alive or dead, stats(attack, defense etc.,), and x, y coordinates.
    - Hence this class is a absract class not wrt c++ rules, but based on
      it's behaviour.
*/



#pragma once

#include "game/assets/StatsPool.h"
#include "engine/Vector2C.h"
#include <vector>

namespace cs {
    
    class Character {
    protected:
        std::vector<std::vector<int>> m_entityData;     //holds the character layout info
        bool m_isAlive;
        st::StatsPool m_statsMan;         //stats manager
    
    public:
        Eng::Vector2C m_coord;      //x and y coordinates

        //constructors
        Character();
        Character(std::vector<std::vector<int>> ed, bool isAl, Eng::Vector2C xny, const std::vector<Part>& parts);

        virtual ~Character() = default;

        const bool getIsAlive() const;      //returns weather character is alive or not

        void deathCondition();        //changes the m_isAlive flag

        const std::vector<std::vector<int>>& getEntityData() const;      //returns entity data
        
        st::StatsPool& getStatsManager();   //returns a reference to m_statsMan

        void HPReduction(Character* obj);   //reduces character hp

        void fetchStats(const std::vector<Part>& parts);    //fetches the stats from total parts sum

        void makeAlive();       //makes entities alive

        void makeDead();        //makes entities dead

        void resetStats() noexcept;

    };
}