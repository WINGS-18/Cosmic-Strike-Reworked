#pragma once

namespace cs {

    class Enemy;
    class Player;

    namespace col {

        enum class possibleAgents {Enemy_vs_Player, Enemy_vs_Bullet, None};
        
        class Event {
        private:
            
            struct Agent {

                Enemy* m_enemyPtr = nullptr;
                Player* m_userPtr = nullptr;
                possibleAgents m_interactionType = possibleAgents::None;

                Agent() = default;
                void agentSetter(Enemy* ePtr, Player* uPtr, possibleAgents type);

                void agentReset();

            };

            Agent a;

        public:

            Event() = default;
            
            const Agent& get_agent() const;

            void setAgent(Enemy* ePtr, Player* uPtr, possibleAgents type);

            void eventReset();

            void processEvent();
            
        };

    }

}