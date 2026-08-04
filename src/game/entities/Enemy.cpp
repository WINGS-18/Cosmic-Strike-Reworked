/*
*@file Enemy.cpp.

* This file is currently empty because
  the base class Character and Enemy both
  have same members and it even uses same
  constructor. Not even new methods currently..
*/



#include "game/entities/Enemy.h"

void cs::Enemy::survivalCheck(Character* obj) {
    HPReduction(obj);
    deathCondition();
}

int cs::Enemy::getSpeed() const noexcept {
    return m_speed;
}