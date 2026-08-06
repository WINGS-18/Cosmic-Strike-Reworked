#include "gameui/Menu.h"
#include <iostream>


namespace menu {

    Node::Node(std::string name)
        : m_menuName(std::move(name)) {}

    void Node::display() {
        for(int i = 0; const auto& child : m_children) {
            std::cout << static_cast<char> ('a' + i) << ")" << child->m_menuName << std::endl;
            ++i;
        }
    }

    std::vector<Node*> Node::getChildren() {
        std::vector<Node*> rawNodes;
        for(const auto& node : m_children) {
            rawNodes.push_back(node.get());
        }
        return rawNodes;
    }

    void Node::addChild(std::unique_ptr<Node> child) {
        m_children.push_back(std::move(child));
    }

    Warehouse::Warehouse(std::string name, std::vector<cs::Part> parts, Eng::Slot place, std::vector<Eng::Slot> allParts)
        : Node(std::move(name)), m_parts(std::move(parts)), m_placement(std::move(place)), m_allParts(std::move(allParts)) {}

    void Warehouse::display() {
        for(int i = 0; const auto& part : m_allParts) {
            std::cout << static_cast<char> ('a' + i) << ")";
            if(part.single()) {
                std::cout << m_parts[part[0]].m_symbol;
            }else {
                std::cout << m_parts[part[0]].m_symbol << " " << m_parts[part[1]].m_symbol;
            }
            std::cout << "\n";
            i++;
        }
    }
}