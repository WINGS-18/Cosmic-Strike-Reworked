#include "Character.h"

namespace cs {

    //constructors

    Character::Character() {}

    Character::Character(std::vector<std::vector<int>> ed, bool isAl, Eng::Vector2C xny)
        : entityData(ed), isAlive(isAl), m_coord(xny) {}

    Character::~Character() {}

    const bool Character::getIsAlive() const {      //returns weather the character is alive or not
        return isAlive;
    }

    const void Character::deathCondition() {
        if(m_statsMan.m_current.m_hp <= 0)  isAlive = false;
    }
}