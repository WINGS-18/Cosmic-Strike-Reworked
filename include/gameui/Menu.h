/*
@file Menu.h :

    * Menu.h header contains 3 major classes that handles
      the game's user interface.
    1) class Node :
        * It is a default class that only has it's name and
          childrens.
        * It highlights to some sections that make you navigate
          into other such sections.

    2) class Warehouse :
        * This class contains elements that let user actually make
          changes or work done.
        * Understand role of Eng::Slot by reading comments provided
          in the @file include/engine/Slot.h.
        * It is also inherited from Node.
    
    3) class Assembler(Private nested class into Warehouse) :
        * It is a nested class that contains one 2-d vector.
        * It's vector member m_entity acts ship layout which user
          is trying to build.
        * Hence whatever parts user selects this vector is re-written
          to resemble it.

OVERALL IDEA :

    * Whenever user starts the game the Node or it's child class
      names are displayed and user can safely navigate through it's
      intrested section.
    * The childrens of the current node are displayed.
    * For building own ship when user enters into specific menu of
      of Warehouse class and chooses the part, we use m_placement that
      tells where this part should be positioned, and using m_allParts to
      overwrite the data of m_entity.
    * I specifically choosed having it only m_entity which is a 2-d vector
      becuase we no need of editing the main player object.
    * Using this m_entity data all other members of set properly and also
      user should only see how ship looks, and not how the internal player
      object looks.
    * So we transfer ie., we use move semantics to transfer this m_entity
      into actual player object.
    * Also we use the m_parts vector here, so instead of making copies i've
      decided to use only one such instance, and moving it from gameui to the
      renderer. Beacuse when gameui is running the renderer won't run and when
      renderer is running gameui won't run.
*/

#pragma once

#include <vector>
#include <string>
#include <memory>
#include "game/assets/GameData.h"
#include "engine/Slot.h"
#include "gameui/Arrow.h"

namespace menu {

    class Node {
    protected:
        std::string m_menuName;
        std::vector<std::unique_ptr<Node>> m_children;

    public:
        Node() = default;       //default constructor
        Node(std::string name);     //move constructor

        virtual ~Node() = default;      //destructor

        virtual void display(const Arrow& arrow);

        std::vector<Node*> getChildren();

        void addChild(std::unique_ptr<Node> child);

        virtual int getOptionLen();

        virtual void shipMaker(int index);
    };


    class Warehouse : public Node {
    private:
        std::vector<cs::Part> m_parts;
        Eng::Slot m_placement;
        std::vector<Eng::Slot> m_allParts;

        class Assembler {
        private:
            std::vector<std::vector<int>> m_entity = {{0, 0, 0, 0, 0}};
        public:
            Assembler() = default;

            void printEntity(const std::vector<cs::Part>& parts) const;
            void insertParts(int index, const Eng::Slot& m_placement, const std::vector<Eng::Slot>& m_allParts);
        };

        //static member coz only one assembler must exist for different Warehouse instances.
        static Assembler m_asm;

    public:

        Warehouse(std::string name, std::vector<cs::Part> parts, Eng::Slot place, std::vector<Eng::Slot> allParts);

        int sizeOfAllParts() const;

        void display(const Arrow& arrow) override;

        int getOptionLen() override;

        void shipMaker(int index) override;
    };

}