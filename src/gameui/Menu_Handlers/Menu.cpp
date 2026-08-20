#include "gameui/Menu_Handlers/Menu.h"
#include <iostream>


namespace menu {

    Warehouse::Assembler Warehouse::m_asm;

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

    void Node::shipMaker(int index) {
        std::cout << "";
    }

    Warehouse::Warehouse(std::string name, Eng::Slot place, std::vector<Eng::Slot> allParts)
        : Node(std::move(name)), m_placement(std::move(place)), m_allParts(std::move(allParts)) {}

    int Warehouse::sizeOfAllParts() const {
        return m_allParts.size();
    }

    void Warehouse::display(const Arrow& arrow) {
        for(int i = 0; const auto& part : m_allParts) {
            std::cout << arrow.printNavigArrow(i) << " ";
            if(part.single()) {
                std::cout << m_asm.m_parts[part[0]].m_symbol;
            }else {
                std::cout << m_asm.m_parts[part[0]].m_symbol << " " << m_asm.m_parts[part[1]].m_symbol;
            }
            std::cout << "\n";
            i++;
        }
    }

    int Warehouse::getOptionLen() {
        return sizeOfAllParts() - 1;
    }

    void Warehouse::shipMaker(int index) {
        m_asm.insertParts(index, m_placement, m_allParts);
        m_asm.printEntity();
    }
    
    void Warehouse::Assembler::printEntity() const {
        for(const auto& row : m_entity) {
            std::cout << "  ";
            for(const auto& cell : row) {
                std::cout << m_asm.m_parts[cell].m_symbol;
            }
            std::cout << "\n\n\n";
        }
    }

    void Warehouse::Assembler::insertParts(int index, const Eng::Slot& m_placement, const std::vector<Eng::Slot>& m_allParts) {
        for(size_t i = 0; i < m_placement.size(); i++) {
            m_entity[0][m_placement[i]] = m_allParts[index][i];
        }
    }

    const std::vector<std::vector<int>>& Warehouse::Assembler::getEntity() const noexcept {
        return m_entity;
    }

    bool Warehouse::Assembler::changed() const noexcept {
        for(int cell : m_entity[0]) {
            if(cell == 15) {
                return false;
            }
        }
        return true;
    }

    void Loadout::display(const Arrow& arrow) {
        s.totalStats(Warehouse::m_asm.getEntity(), Warehouse::m_asm.m_parts);
        s.displayStats();
    }

    void Loadout::shipMaker(int index) {
        Warehouse::m_asm.printEntity();
    }

}