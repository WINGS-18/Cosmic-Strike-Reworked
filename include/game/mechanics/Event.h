/*
@file Event.h :

* Event class consist of a inner class defined in private.
* Event class has a Agent member that is used to store the interaction
  of a single Event.
* Many such Event instances are processed by accessing the members of
  Agent member.
* Specifically designed to reuse objects to make object pool.
*/

#pragma once

namespace cs {

    class Enemy;
    class Player;

    namespace col {

        /*
        enum class holds all possible events in the game.
        */
        enum class possibleAgents {Enemy_vs_Player, Enemy_vs_Bullet, None};
        
        class Event {
        private:

            /*
            * Agent is nested struct within a class.
            * Specifically done to keep resources under the outer class
              scope.
            * Also these types of design are implemented when the inner struct
              has no significance or use apart from being member of the outer
              class.
            */
            
            struct Agent {

                Enemy* m_enemyPtr = nullptr;
                Player* m_userPtr = nullptr;
                possibleAgents m_interactionType = possibleAgents::None;

                Agent() = default;      //default constructor

                void agentSetter(Enemy* ePtr, Player* uPtr, possibleAgents type);   //sets the agent wrt to the event

                void agentReset();      //reset to default

            };

            Agent a;

            //inner class defination ends...

        public:

            Event() = default;      //default constructor.
            
            const Agent& get_agent() const;     //returns const reference of agent member.

            void setAgent(Enemy* ePtr, Player* uPtr, possibleAgents type);  //calls Agent::agentSetter().

            void eventReset();      //calls Agent::agentReset().

            void processEvent();    //process the event to alter the interacted entities
            
        };

    }

}