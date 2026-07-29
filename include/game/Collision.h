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

            void addEvent(Enemy* ePtr, Player* uPtr, possibleAgents type);

            void clearEvents();

            void collisionDetector(std::vector<Enemy>& aliveEnemies, std::vector<Player>& user);

            void processAllEvents();

            void collisionHandler(std::vector<Enemy>& aliveEnemies, std::vector<Player>& user);

        };
    }
}