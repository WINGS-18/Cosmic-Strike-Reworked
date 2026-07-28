#include "game/Collision.h"


namespace cs::col {

    Collision::Collision(std::vector<Event>&& active)
        : m_activeEvents(std::move(active)) {}

    void Collision::addEvent(void* ptr1, possibleAgents type1, void* ptr2, possibleAgents type2) {
        m_inactiveEvents.back().setAgent(ptr1, type1, ptr2, type2);
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

    bool Collision::collisionDetector(std::vector<Enemy>& aliveEnemies, std::vector<Player>& user) {
        int height = 25;
        for(Enemy obj : aliveEnemies) { 
            if(obj.getIsAlive()) { 
                if(obj.m_coord.y == user[0].m_coord.x) {
                    addEvent(&obj, col::possibleAgents::enemy, &user[0], col::possibleAgents::player);
                } else if(!user[0].m_playerGun.m_active.empty()) { 
                    for(Arsenal::Bullet& b : user[0].m_playerGun.m_active) { 
                        if(obj.m_coord.x == b.m_bulCoord.x && obj.m_coord.y == b.m_bulCoord.y) { 
                            addEvent(&obj, col::possibleAgents::enemy, &b, col::possibleAgents::bullet);
                        }
                    }
                }
            }
        }
        //return collision;
    }
}