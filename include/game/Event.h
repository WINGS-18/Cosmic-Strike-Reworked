#pragma once

namespace cs {

    namespace col {

        enum class possibleAgents {enemy, player, bullet, none};
        
        class Event {
        private:
            
            struct Agent {

                void* m_entityPtr = nullptr;
                possibleAgents m_entityType = possibleAgents::none;

                Agent() = default;
                void agentSetter(void* ptr, possibleAgents type);

                void agentReset();
            };

            Agent a1;
            Agent a2;

        public:

            Event() = default;
            
            const Agent& get_a1() const;
            const Agent& get_a2() const;

            void setAgent(void* ptr1, possibleAgents type1, void* ptr2, possibleAgents type2);

            void eventReset();
            
        };

    }

}