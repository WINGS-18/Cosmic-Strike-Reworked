#include "game/Event.h"
#include "game/Enemy.h"
#include "game/Player.h"

namespace cs::col {

    void Event::eventReset() {
        a.agentReset();
    }

    void Event::setAgent(Enemy* ePtr, Player* uPtr, possibleAgents type) {
        a.agentSetter(ePtr, uPtr, type);
    }

    void Event::processEvent() {
        switch(a.m_interactionType) {
            case possibleAgents::Enemy_vs_Player :
                a.m_enemyPtr->makeDead();
                a.m_userPtr->survivalCheck(a.m_enemyPtr);
                break;

            case possibleAgents::Enemy_vs_Bullet :
                a.m_enemyPtr->survivalCheck(a.m_userPtr);
                break;

            default :
                break;
        }
    }

    void Event::Agent::agentSetter(Enemy* ePtr, Player* uPtr, possibleAgents type) {
        m_enemyPtr = ePtr;
        m_userPtr = uPtr;
        m_interactionType = type;
    }

    const Event::Agent& Event::get_agent () const {return a;}

    void Event::Agent::agentReset() {
        m_enemyPtr = nullptr;
        m_userPtr = nullptr;
        m_interactionType = possibleAgents::None;
    }

}