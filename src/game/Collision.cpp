#include "game/Collision.h"


namespace cs::col {

    Collision::Collision(std::vector<Event>&& active)
        : m_activeEvents(std::move(active)) {}

    void Collision::addEvent(Enemy* ePtr, Player* uPtr, possibleAgents type) {
        m_inactiveEvents.back().setAgent(ePtr, uPtr, type);
        auto e = m_inactiveEvents.back();
        m_activeEvents.push_back(e);
        m_inactiveEvents.pop_back();
    }

    void Collision::clearEvents() {
        size_t size = m_activeEvents.size();
        for(size_t i = 0; i < size; i++) {
            m_activeEvents.back().eventReset();
            auto e = m_activeEvents.back();
            m_inactiveEvents.push_back(e);
            m_activeEvents.pop_back();
        }
    }

    void Collision::collisionDetector(std::vector<Enemy>& aliveEnemies, std::vector<Player>& user) {
        int height = 25;
        for(Enemy obj : aliveEnemies) { 
            if(obj.getIsAlive()) { 
                if(obj.m_coord.y == user[0].m_coord.x) {
                    addEvent(&obj, &user[0], col::possibleAgents::Enemy_vs_Player);
                } else if(!user[0].m_playerGun.m_active.empty()) { 
                    for(Arsenal::Bullet& b : user[0].m_playerGun.m_active) { 
                        if(obj.m_coord.x == b.m_bulCoord.x && obj.m_coord.y == b.m_bulCoord.y) { 
                            addEvent(&obj, &user[0], col::possibleAgents::Enemy_vs_Bullet);
                        }
                    }
                }
            }
        }
    }

    void Collision::processAllEvents() {
        for(Event& e : m_activeEvents) {
            e.processEvent();
        }
    }

    void Collision::collisionHandler(std::vector<Enemy>& aliveEnemies, std::vector<Player>& user) {
        collisionDetector(aliveEnemies, user);
        clearEvents();
    }
}