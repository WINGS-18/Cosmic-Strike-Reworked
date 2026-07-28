#include "game/Event.h"

namespace cs::col {

    void Event::eventReset() {
        a1.agentReset();
        a2.agentReset();
    }

    void Event::setAgent(void* ptr1, possibleAgents type1, void* ptr2, possibleAgents type2) {
        a1.agentSetter(ptr1, type1);
        a2.agentSetter(ptr2, type2);
    }

    void Event::Agent::agentSetter(void* ptr, possibleAgents type) {
        m_entityPtr = ptr;
        m_entityType = type;
    }

    const Event::Agent& Event::get_a1() const {return a1;}
    const Event::Agent& Event::get_a2() const {return a2;}

    void Event::Agent::agentReset() {
        m_entityPtr = nullptr;
        m_entityType = possibleAgents::none;
    }

}