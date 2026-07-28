#pragma once

#include "game/Event.h"
#include "game/Player.h"
#include "game/Enemy.h"

namespace cs {

    namespace col {

        class Collision {
        private:
            std::vector<Event> m_activeEvents;
            std::vector<Event> m_inactiveEvents;
        public:

            Collision() = default;

            Collision(std::vector<Event>&& active);

            void addEvent(void* ptr1, possibleAgents type1, void* ptr2, possibleAgents type2);

            void clearEvents();

            bool collisionDetector(std::vector<Enemy>& aliveEnemies, std::vector<Player>& user);

        };
    }
}