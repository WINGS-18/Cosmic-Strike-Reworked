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

    std::vector<std::vector<int>>& Warehouse::Assembler::getEntity() noexcept {
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

    void PlayObject::display(const Arrow& arrow) {
        m_gm.startGame(Warehouse::m_asm.getEntity(), Warehouse::m_asm.changed());
    }

    void HelpObject::display(const Arrow& arrow) {
        std::cout << "==================================================\n";
        std::cout << "                game manual & controls            \n";
        std::cout << "==================================================\n\n";

        std::cout << "  [ gameplay movement ]\n";
        std::cout << "    a - move ship left\n";
        std::cout << "    d - move ship right\n\n";

        std::cout << "  [ combat systems ]\n";
        std::cout << "    - gun fires automatically at all times.\n";
        std::cout << "    - no reloading required.\n";
        std::cout << "    - just focus on moving to aim at enemies!\n\n";

        std::cout << "  [ menu navigation ]\n";
        std::cout << "    w     - move cursor up\n";
        std::cout << "    s     - move cursor down\n";
        std::cout << "    space - confirm / enter selection\n";
        std::cout << "    q     - go back / exit current menu\n\n";

        std::cout << "  [ warehouse & ship selection ]\n";
        std::cout << "    - navigate parts using 'w' and 's'.\n";
        std::cout << "    - do not press space to choose a part.\n";
        std::cout << "    - whichever part the cursor points to is\n";
        std::cout << "      instantly equipped to your ship!\n\n";

        std::cout << "  [ !! crucial notes & glitches !! ]\n";
        std::cout << "    - how to start match: when pointing on play,\n";
        std::cout << "      press space first, then press 'd'.\n";
        std::cout << "    - instant exit: pressing 'd' inside any menu\n";
        std::cout << "      will immediately close down the entire game.\n\n";

        std::cout << "==================================================\n";
        std::cout << "            press 'q' to return to main menu      \n";
        std::cout << "==================================================\n";
    }

}