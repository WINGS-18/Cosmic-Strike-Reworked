#pragma once


#include <vector>
#include <string>


namespace menu {

    class Node {
    private:
        std::string m_menuName;
        std::vector<Node*> m_children;

    public:
        Node() = default;       //default constructor
        Node(std::string name);     //move constructor

        virtual ~Node() = default;      //destructor

        virtual void display();
    };

}