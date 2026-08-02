#include "game/entities/Character.h"

namespace cs {

    //constructors

    Character::Character() {}

    Character::Character(std::vector<std::vector<int>> ed, bool isAl, Eng::Vector2C xny, const std::vector<Part>& parts)
        : m_entityData(std::move(ed)), m_isAlive(isAl), m_coord(xny) {fetchStats(parts);}

    const bool Character::getIsAlive() const {      //returns weather the character is alive or not
        return m_isAlive;
    }

    void Character::deathCondition() {
        if(m_statsMan.m_current.m_hp <= 0)  makeDead();
    }

    const std::vector<std::vector<int>>& Character::getEntityData() const{
        return m_entityData;
    }

    st::StatsPool& Character::getStatsManager() {
        return m_statsMan;
    }

    void Character::HPReduction(Character* obj) {
        if(m_statsMan.m_current.m_shield > 0) {
            m_statsMan.m_current.m_shield -= obj->m_statsMan.m_current.damageDealer(m_statsMan.m_current.m_defense);      //shield takes damage first.
        }

        if(m_statsMan.m_current.m_shield <= 0){        //after shield becomes 0 or less, damage is dealt to HP.
            m_statsMan.m_current.m_hp -= m_statsMan.m_current.damageDealer(m_statsMan.m_current.m_defense) + m_statsMan.m_current.m_shield;
            m_statsMan.m_current.m_shield = 0;
        }
    }

    void Character::fetchStats(const std::vector<Part>& parts) {
        m_statsMan.m_base.totalStats(m_entityData, parts);
        m_statsMan.m_current.totalStats(m_entityData, parts);
    }

    void Character::makeAlive() {
        m_isAlive = true;
    }

    void Character::makeDead() {
        m_isAlive = false;
    }
}