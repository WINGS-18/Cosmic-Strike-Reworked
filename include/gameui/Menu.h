#pragma once


#include <vector>
#include <string>
#include <memory>
#include "game/assets/GameData.h"
#include "engine/Slot.h"

namespace menu {

    enum class navigation {};

    class Node {
    protected:
        std::string m_menuName;
        std::vector<std::unique_ptr<Node>> m_children;

    public:
        Node() = default;       //default constructor
        Node(std::string name);     //move constructor

        virtual ~Node() = default;      //destructor

        virtual void display();

        std::vector<Node*> getChildren();

        void addChild(std::unique_ptr<Node> child);
    };


    class Warehouse : public Node {
    private:
        std::vector<cs::Part> m_parts;
        Eng::Slot m_placement;
        std::vector<Eng::Slot> m_allParts;
    public:
        Warehouse(std::string name, std::vector<cs::Part> parts, Eng::Slot place, std::vector<Eng::Slot> allParts);

        void display() override;
    };

}