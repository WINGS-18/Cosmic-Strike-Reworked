// =======================================================================================
// @file Menu.h
// 
// This header contains 3 major classes that handle the game's user interface.
// =======================================================================================

// 1) class Node :
//    * It is a base class that only contains its name and its children nodes.
//    * It acts as a menu item/section that highlights to let the user navigate 
//      into other nested sections.

// 2) class Warehouse :
//    * This class contains the specific UI elements that let the user actually 
//      make modifications or get tasks done.
//    * It inherits from the Node class.
//    * To understand the role of Eng::Slot, please read the comments provided 
//      in the file: include/engine/Slot.h.

// 3) class Assembler (Private nested class inside Warehouse) :
//    * It is a nested class that contains a single 2D vector member: m_entity.
//    * The m_entity vector acts as the physical ship layout that the user is 
//      currently trying to build.
//    * Whenever the user selects new spaceship parts, this vector is completely 
//      overwritten to resemble the updated blueprint layout.

// =======================================================================================
// OVERALL ARCHITECTURE IDEA :
// =======================================================================================

// * Core UI Flow:
//   - Whenever the user starts the game, the names of the current Node (or its 
//     derived child classes) are displayed on-screen.
//   - The user can safely navigate through these sections, and the UI will 
//     render the children of the currently active node.

// * The Ship Building System:
//   - When the user enters the specific warehouse menu to build their spaceship, 
//     they select parts from the m_allParts database.
//   - We use m_placement to determine exactly where the selected part should 
//     be positioned, and then we overwrite the data inside the m_entity grid.
//   - Using a raw 2D vector (m_entity) for editing is a deliberate design choice: 
//     it prevents us from constantly modifying or corrupting the live, active 
//     player object while the user is still experimenting in the menu.
//   - This decouples the visual preview from the backend state, ensuring the 
//     user only sees how the ship *looks* during assembly without prematurely 
//     affecting the internal mechanics of the live player object.

// * Zero-Allocation Optimization via Move Semantics:
//   - Once the user finalizes their design and finishes building, we use 
//     move semantics (std::move) to efficiently transfer the compiled m_entity 
//     data directly into the real, live player object.
//   - We apply this exact same strict turn-taking strategy to the m_parts vector. 
//     Instead of creating heavy, redundant memory copies, we maintain a single 
//     instance and move it back and forth between the UI and the Renderer.
//   - This is perfectly optimized because the two systems run exclusively: 
//     when the Game UI is processing input, the Renderer is asleep; and when the 
//     Renderer is drawing frames, the Game UI logic is completely frozen.


#pragma once

#include <vector>
#include <string>
#include <memory>
#include "game/assets/GameData.h"
#include "engine/Slot.h"
#include "gameui/Menu_Handlers/Arrow.h"

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
        Eng::Slot m_placement;
        std::vector<Eng::Slot> m_allParts;
        
        
        //static member coz only one assembler must exist for different Warehouse instances.
        
    public:
        class Assembler {
        private:
            std::vector<std::vector<int>> m_entity = {{15, 15, 15, 15, 15}};
        public:
            std::vector<cs::Part> m_parts = cs::GameData::getParts();
            Assembler() = default;
            
            void printEntity() const;
            void insertParts(int index, const Eng::Slot& m_placement, const std::vector<Eng::Slot>& m_allParts);
            const std::vector<std::vector<int>>& getEntity() const noexcept;
            bool changed() const noexcept;
        };

        static Assembler m_asm;
        
        Warehouse(std::string name, Eng::Slot place, std::vector<Eng::Slot> allParts);

        int sizeOfAllParts() const;

        void display(const Arrow& arrow) override;
        
        int getOptionLen() override;
        
        void shipMaker(int index) override;

    };
      
    class Loadout : public Node {
    private:
        cs::st::Stats s;
    
    public:
        using Node::Node;
        
        void display(const Arrow& arrow) override;

        void shipMaker(int index) override;
    };

}