#include "Character.h"

namespace cs {

    Character::Character() {}

    Character::Character(std::vector<std::vector<int>> ed, bool isAl, Eng::Vector2C xny)
        : entityData(ed), isAlive(isAl), m_coord(xny) {}
}