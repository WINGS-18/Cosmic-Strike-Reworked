#include "gameui/Menu.h"
#include <iostream>


namespace menu {

    Node::Node(std::string name)
        : m_menuName(std::move(name)) {}

    void Node::display(const Arrow& arrow) {
        for(int i = 0; const auto& child : m_children) {
            std::cout << arrow.printNavigArrow(i) << " " << child->m_menuName << std::endl;
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

    int Node::getOptionLen() {
        return m_children.size() - 1;
    }

    Warehouse::Warehouse(std::string name, std::vector<cs::Part> parts, Eng::Slot place, std::vector<Eng::Slot> allParts)
        : Node(std::move(name)), m_parts(std::move(parts)), m_placement(std::move(place)), m_allParts(std::move(allParts)) {}

    int Warehouse::sizeOfAllParts() const {
        return m_allParts.size();
    }

    void Warehouse::display(const Arrow& arrow) {
        for(int i = 0; const auto& part : m_allParts) {
            std::cout << arrow.printNavigArrow(i) << " ";
            if(part.single()) {
                std::cout << m_parts[part[0]].m_symbol;
            }else {
                std::cout << m_parts[part[0]].m_symbol << " " << m_parts[part[1]].m_symbol;
            }
            std::cout << "\n";
            i++;
        }
    }

    int Warehouse::getOptionLen() {
        return sizeOfAllParts() - 1;
    }
}