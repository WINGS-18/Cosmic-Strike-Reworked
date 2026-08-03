#include "gameui/Menu.h"
#include <iostream>


namespace menu {

    Node::Node(std::string name)
        : m_menuName(std::move(name)) {}

    void Node::display() {
        for(int i = 0; const auto& child : m_children) {
            std::cout << static_cast<char>('a' + i) << ")" << child->m_menuName << std::endl;
            i++;
        }
    }

}