# Cosmic-Strike-Reworked 🚀

A terminal-based 2D space shooter game built in C++. 

This project is a complete architectural refactor of a simple single-file game into a highly optimized, component-based game engine. It serves as an exploration of advanced C++ concepts, memory management, and systems architecture.

## 🌟 Key Features

* **Zero Runtime Allocation:** Implements **Object Pooling** for all game entities (bullets, enemies, and collision events) to completely eliminate memory fragmentation and the overhead of dynamic allocation (`new`/`delete`) during gameplay.
* **Component-Based Entity System:** Characters are not monolithic objects. They are dynamically constructed using a `Part` system, where each part contributes specific stats (HP, Attack, Defense, Shield) to the entity's total `StatsPool`.
* **Decoupled Architecture:** Strict separation of concerns between game logic, collision detection, and rendering.
* **Modern C++:** Utilizes Move Semantics (`std::move`), range-based for loops, `auto` type deduction, and const-correctness for aggressive compiler optimization.
* **Flicker-Mitigated Rendering:** Uses ANSI escape codes for terminal manipulation and screen clearing, avoiding the heavy process overhead of `system("cls")`.

## 🏗️ Technical Architecture

* **Object Pools:** 
  * `Gun.cpp`: Pre-loads an inactive pool of bullets. Firing simply moves a bullet from the inactive pool to the active pool, and collisions return them.
  * `Collision.cpp`: Pre-allocates `Event` objects. When collisions are detected, events are dispatched from the pool, processed, and recycled.
* **Custom Math Struct:** Implements a custom `Vector2C` struct with overloaded operators (`==`, `<`, `>`, `+`, `-`) for clean and readable coordinate tracking and collision math.
* **Damage Scaling Engine:** Features a mathematical damage formula where defensive stats mitigate incoming attack values before reducing shields and health points.

## 📂 Project Structure

```text
├── include/
│   ├── engine/   # Low-level utilities (Terminal ANSI codes, Vector2C math)
│   ├── game/     # Core game logic (Characters, Bullets, Collision, Stats)
│   └── gameui/   # UI elements
├── src/
│   ├── engine/   # Implementations of engine utilities
│   ├── game/     # Implementations of game logic and rendering
│   ├── gameui/   
│   └── main.cpp  # Entry point and game initialization
└── README.md
```

## 🎮 How to Play

**Platform Compatibility:** Windows only (Utilizes `<windows.h>` and `<conio.h>` for asynchronous input).

**Controls:**
* `a` - Move Left
* `d` - Move Right
* `e` - Exit Game
* *Note: Firing is automatic!*

## 🛠️ Compilation

To compile the game, use any modern C++ compiler (like MinGW/GCC or MSVC). Make sure to link the `include` directory.

Example using `g++`:
```bash
g++ -I include src/main.cpp src/engine/*.cpp src/game/*.cpp -o game.exe
```