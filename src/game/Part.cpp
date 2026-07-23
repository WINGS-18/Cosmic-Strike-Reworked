#include "game/Part.h"

namespace cs {

  //constructor definations
    Part::Part()
        : m_symbol(' '), m_healthPoints(0), m_attack(0),
          m_defense(0), m_shield(0) {}

    Part::Part(char s, int hp, int atk, int def, int sh)
        : m_symbol(s), m_healthPoints(hp), m_attack(atk),
          m_defense(def), m_shield(sh) {}
}