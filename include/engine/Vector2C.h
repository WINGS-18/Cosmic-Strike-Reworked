/*
* Eng is the common namespace
  for the utilities even helpfull
  to make other games.
  */



/*
* @Vector2C.h.
    - A struct instance capable of holding
      two coordinates namely x and y. 
    - It also provides many overloaded operators that
      will help in easy comparions and also in arithematic
      operations.
*/



#pragma once


/*
$ 50 shades of const:

* const datatype* var:
    - The var pointer is strictly read only.
    - Values or members cannot be atlered.

* datatype* const var:
    - The var pointer is read and write.
    - The pointer var is locked and cannot be reassigned.

* returntype function(datatype& para) const:
    - This const at the end of the declaration gurrenttes the function will not change the members.
    - Due to this complier can optimise by keeping the members in the registers.
    - It reduces continous loading and unloading from RAM to registers.
*/


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
        void yCoordinateUpdate();       //updates the y coordinate

    };
    
}