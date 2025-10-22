# 🎮 GameBoy Emulator Project

A work-in-progress Game Boy emulator written in C++ 17 (focusing on accurate CPU emulation and modular architecture). This initiative is taken upon by students in
the Mathematical Computer Science and Computer Science departments at the University of Illinois at Chicago.

Supervisors:
- **Harry Alvarado**

  Major: Mathematics and Computer Science

  Contact: halva3@uic.edu

- **Marcos Araque**

  Master's Student in MSCS
  
  Contact: maraqu2@uic.edu

---

## 🧑‍💻 Coding Practices

To keep this project consistent, maintainable, and portable across different operating systems, all contributors must follow these coding guidelines.
### 🗒️ 1. Documentation and Readability

- **Over-document your code.** Every class, function, and complex block should have clear comments explaining what it does and why.  
- Comments should help others understand your thought process, not just repeat the code.
- Do not use the 'using namespace std' always specify namespace prior to using an object (std::).
- Use revalent names, but make them unique to avoid redeclaration error.
- Use consistent naming:
  - **Classes:** CamelCase  
  - **Functions:** PascalCase or snake_case (pick one and use it everywhere)  
  - **Variables:** snake_case  
- Avoid single-letter variable names unless they’re loop counters (`i`, `j`, `k`).


### Example

```cpp
// Executes the next instruction from memory
void ExecuteNextInstruction(int cycles) {
    // Update registers and advance the program counter
}
```

### 🚫 2. External Libraries and File-Specific Code
- Do not include external dependencies (e.g., SDL, SFML, Boost, etc.). Only use the C++ Standard Library.
- Avoid OS-specific code, no Windows-only or macOS-only system calls, paths, or headers. Your code must compile and run the same way on Linux, macOS, and Windows.
- Do not hardcode file paths. Use relative paths or configuration constants if file access is required.
- No external asset loaders or libraries should be used without prior approval from supervisors.





## 📘 Resources
 - General Information: https://gbdev.io/pandocs/Specifications.html
 - CPU Hardware: https://gekkio.fi/files/gb-docs/gbctr.pdf
 - List of Opcodes: https://rgbds.gbdev.io/docs/v0.9.4/gbz80.7 or https://meganesu.github.io/generate-gb-opcodes
 - Harry's Lectures (READ): [Emulator Notes (PDF)](docs/Emulator_Lecs.pdf)


## 🚧 Current Task
  Nothing to do yet until Lecture 1 is finalized where we'll set a clear coding objective to every collaborator. 

## 🧩 General Implementation:

 ### **CPU LR35902**: _(In Progress)_
     - [ ] Implement CPU registers (A,B,C,D,E,H,L,F;PC,SP)
     - [ ] Implement flag handling (Z,N,H,C)
     - [ ] Build instruction decoder
     - [ ] Implement instruction timing
     - [ ] Implement data transfer instructions (LD r,r ,LD r,(HL), etc.)
     - [ ] Implement arithmetic & logic instructions (ADD, SUB, AND, OR, etc.)
     - [ ] Implement control flow (JP, JR, CALL, RET, RST)
     - [ ] Implement bit operations (BIT, SET, RES, shifts, rotates)
     - [ ] Miscellaneous operations
     - [ ] Implement interrupt handling
     - [ ] Verify correctness with CPU test ROMs
 ### Memory:  _(Not Begun)_
     - To be added
 ### Graphics:  _(Not Begun)_
     - To be added
 ### Input:  _(Not Begun)_
     - To be added
 ### Sound: _(Not Begun)_
     - To be added


    
