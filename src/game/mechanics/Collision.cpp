#include "game/mechanics/Collision.h"

namespace cs::col {

    Collision::Collision(std::vector<Event>&& inactive)
        : m_inactiveEvents(std::move(inactive)) {}

    void Collision::addEvent(Enemy* ePtr, Player* uPtr, possibleAgents type) {
        m_activeEvents.push_back(m_inactiveEvents.back());
        m_activeEvents.back().setAgent(ePtr, uPtr, type);
        m_inactiveEvents.pop_back();
    }

    void Collision::clearEvents() {
        size_t size = m_activeEvents.size();
        for(size_t i = 0; i < size; i++) {
            m_inactiveEvents.push_back(m_activeEvents.back());
            m_inactiveEvents.back().eventReset();
            m_activeEvents.pop_back();
        }
    }

    void Collision::collisionDetector(std::vector<Enemy>& aliveEnemies, std::vector<Player>& user) {
        for(Enemy& obj : aliveEnemies) {
            if(obj.getIsAlive()) {
                if(obj.m_coord.y == user[0].m_coord.y) {
                    addEvent(&obj, &user[0], col::possibleAgents::Enemy_vs_Player);
                } else if(!user[0].m_playerGun.m_active.empty()) { 
                    for(Arsenal::Bullet& b : user[0].m_playerGun.m_active) { 
                        if(obj.m_coord == b.m_bulCoord) { 
                            addEvent(&obj, &user[0], col::possibleAgents::Enemy_vs_Bullet);
                        }
                    }
                }
            }
        }
    }

    void Collision::processAllEvents() {
        for(size_t i = 0; i < m_activeEvents.size(); i++) {
            m_activeEvents[i].processEvent();
        }
    }

    void Collision::collisionHandler(std::vector<Enemy>& aliveEnemies, std::vector<Player>& user) {
        collisionDetector(aliveEnemies, user);
        processAllEvents();
        clearEvents();
    }
}