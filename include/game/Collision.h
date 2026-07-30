/*
@file: Collision.h

* It handles entities iteractions such as collisions etc.,
* Uses m_activeEvents and m_inactiveEvents to reuse the
  Event objects.

* Working :
    - Whenever a event is detected, Event object from
      m_inactiveEvents is pushed into m_activeEvents.
    - Then the info about interaction is fed into that
      object.
    - All the objects inside the m_activeEvents are then
      processed individually also altering stats of the
      interacted enetities.
    - Later all events are cleared by making them default
      and pushed into m_inactiveEvents.
    - This way we use less objects without heap allocation.
  
*/



#pragma once

#include "game/Event.h"
#include "game/Player.h"
#include "game/Enemy.h"

namespace cs {

    namespace col {

        class Collision {
        private:
            std::vector<Event> m_inactiveEvents;
            std::vector<Event> m_activeEvents;
        public:

            Collision() = default;      //default constructor

            /*
            * It takes an rvalue reference of event vector.
            * This is moved into the m_inactiveEvents vector.
            * std::move() ensures that data is not copied but
              moved to it's destination.
            */

            /*
            * How does std::move() work?
                - It takes in a rvalue reference(a temporary object)
                  and points it to the destination variable.
                - Then it sets that move parameter to nullptr.
                - Effectively stealing the resources.
            */


            Collision(std::vector<Event>&& inactive);       //move constructor

            void addEvent(Enemy* ePtr, Player* uPtr, possibleAgents type);  //adds new event into the m_active events

            void clearEvents();     //clears m_active events and pools it to m_inactiveEvents after processing

            /*
            * Detects collision between different entities and
              builds adds the event.
            */
            void collisionDetector(std::vector<Enemy>& aliveEnemies, std::vector<Player>& user);

            void processAllEvents();    //processes all the current active events

            /*
            * Does all these collision detection, adding events and clearing events.
            * Mighty function that handles entire collision work under the hood.
            */
            void collisionHandler(std::vector<Enemy>& aliveEnemies, std::vector<Player>& user);

        };
    }
}