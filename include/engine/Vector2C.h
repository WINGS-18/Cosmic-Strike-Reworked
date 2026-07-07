/*
A coustom structure instance capable of holding
two coordinates namely x and y. 
It also provides many overloaded operators that
will help in easy comparions and also in making
coordinate math easy
*/

#pragma once


namespace Eng {

    struct Vector2C {
        int x;
        int y;

        //constructors
        Vector2C();
        Vector2C(int x, int y);

        bool operator ==(const Vector2C& other) const;      //overloaded '==' operator
        bool operator <(const Vector2C& other) const;       //overloaded '<' operator
        bool operator >(const Vector2C& other) const;       //overloaded '>' operator
        bool operator <=(const Vector2C& other) const;      //overloaded '<=' operator
        bool operator >=(const Vector2C& other) const;      //overloaded '>=' operator
        Vector2C operator -(const Vector2C& other) const;       //overloaded '-' operator
        Vector2C operator +(const Vector2C& other)const;        //overloaded '+' operator

    };
    
}