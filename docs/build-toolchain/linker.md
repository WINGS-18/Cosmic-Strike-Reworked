## Linker

## What is a linker ?

* `Linker` is a program that links multiple object files and external libraries to generate the final executable file or binary file which your processor can run.

## Key Terminologies

* **Symbols:** These are names given to your functions, global variables, or classes. The compiler marks these as placeholders when they are defined or called across your files.
* **Symbol Resolution:** This is the process where the linker scans through all object files to match a function call in one file to its actual definition in another file.
* **Static Linking:** In this process, the linker copies all the library code directly into your final `.exe file`. This makes your executable file larger, but it runs without needing external `.dll files`.
* **Dynamic Linking:** In this process, the linker leaves references to external code. The final `.exe file` remains small, but it requires dynamic link libraries (`.dll` on Windows) to be present in the folder when the game runs.

## How does linker work?

* **Verification Stage:** The linker gathers all the `.obj files` created during the object file generation stage. It scans each file's symbol table to map out what functions are available and what functions are missing.
* **Resolution Stage:** When compiling `main.cpp`, if you call a function defined in `player.cpp`, the compiler doesn't know its location in memory yet and leaves a blank address. The linker steps in, finds the physical location of that function inside `player.obj`, and updates that blank address with the true memory destination.
* **Section Merging:** The linker merges similar sections from all individual object files together. For example, it takes all code instructions and merges them into one block, and takes all global data and merges them into another.
* **Executable Generation:** It packages everything cleanly into a machine-ready file (`game.exe`), ensuring your operating system knows exactly which instruction to run first (the entry point, which is your `main` function).

## ⚠️ Problems during Linking (Linker Errors)

Linker errors only pop up *after* your code successfully compiles. They usually start with words like `LNK` or `undefined reference`.

* **Unresolved External Symbol:** This means you declared a function or variable (often in a header file) and called it somewhere, but the linker cannot find its actual definition in any of your `.cpp files`. This happens if you forgot to implement the body of a function or didn't include the `.cpp file` in your build.
* **Multiply Defined Symbol:** The linker found two or more identical definitions for the exact same function or variable symbol and doesn't know which one to choose. This happens if you define a global variable or function body entirely inside a header file without using the `inline` keyword.