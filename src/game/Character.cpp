#include "game/Character.h"

namespace cs {

    //constructors

    Character::Character() {}

    Character::Character(std::vector<std::vector<int>> ed, bool isAl, Eng::Vector2C xny)
        : m_entityData(ed), m_isAlive(isAl), m_coord(xny) {}

    const bool Character::getIsAlive() const {      //returns weather the character is alive or not
        return m_isAlive;
    }

    const void Character::deathCondition() {
        if(m_statsMan.m_current.m_hp <= 0)  m_isAlive = false;
    }

    const std::vector<std::vector<int>> Character::getEntityData() const{
        return m_entityData;
    }

    void Character::makeAlive() {
        m_isAlive = true;
    }
}