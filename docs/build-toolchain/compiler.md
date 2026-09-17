## Compiler

## What is a compiler ?

* `Compiler` is a program that translates our high level c++ code into actual machine code or binary code which the processor can directly execute.

## Key Terminologies

* **Translation unit:** `Translation unit` is nothing but your c++ file after pre-processor stage. If your project contains ten c++ files then there are ten `Translation units`. Note that if you have two cpp files and one is included into another then you still get only one `translation unit`.
* **.obj file:** These are known as object files that contain binary code which cannot be executed just yet.
* **.exe file:** This is known as executable file which will have final instruction or machine code for your processor to execute the program.

## How does compiler work?

* **Pre-Processor Stage:** In this stage all the `Pre-Processors` are replaced with their definations. The `#include<....>` the library content is just copy pasted into your cpp file. Thus, it generates an intermediate files or `Translation units`.
* **Syntax checking Stage:** In this stage the `Translation units` are broken into small tokens and is checked with the c++ tokens and immediately reports if any syntax error is present.
* **Conversion:** The compiler scans and translates entire source code into low level `Assembly` or machine code instruction at once.
* **Object file generation:** Once when the code is properly compiled `.obj file` is created. If there are ten `Translation units` then corresponding ten `.obj files` are created.
* **Linker's Job:** Then it's the job of the linker to link these multiple object files and generate an `.exe file`.