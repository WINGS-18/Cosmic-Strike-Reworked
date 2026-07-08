#include "engine/Vector2C.h"

namespace Eng {

    Vector2C::Vector2C()        //defualt constructor
        : x(0), y(0) {}

    Vector2C::Vector2C(int con_x, int con_y)        //parameterised constructor
        : x(con_x), y(con_y) {}
    
    bool Vector2C::operator ==(const Vector2C& other) const {       //overloaded '==' operator
        return (x == other.x && y == other.y);
    }

    bool Vector2C::operator <(const Vector2C& other) const {        //overloaded '<' operator
        return (x < other.x && y < other.y);
    }

    bool Vector2C::operator >(const Vector2C& other) const {        //overloaded '>' operator
        return (x > other.x && y > other.y);
    }

    bool Vector2C::operator <=(const Vector2C& other) const {       //overloaded '<=' operator
        return (x <= other.x && y <= other.y);
    }

    bool Vector2C::operator >=(const Vector2C& other) const {       //overloaded '>=' operator
        return (x >= other.x && y >= other.y);
    }

    Vector2C Vector2C::operator +(const Vector2C& other) const {        //overloaded '+' operator
        return {x + other.x, y + other.y};
    }

    Vector2C Vector2C::operator -(const Vector2C& other) const {        //overloaded '-' operator
        return {x - other.x, y - other.y};
    }

}