#include <cstdint> // bit-specific integer data type
#include <vector> 
#include <iostream>
#include <fstream>


// GAME BOY EMULATION RESOURCE: https://gbdev.io/pandocs/

// TASK 1 HARDWARE:


/* 1.0
    LR35902 CPU's (GAME BOY) Registers
    1. 8-bit general registers - are like scratch paper used for
    holding numbers temporarily while doing calculations or moving 
    data around.
        - The CPU has a total of eight 8-bit registers named
        A,B,C,D,E,H,L,F

            A (accumulator): main register used to store the result of
            arithmetic and logic operations or store high priority 
            information.

            B,C,D,E,H,L: these are general registers which are not fixed
            on specific operations but largely depends on how the
            instruction set utlize them. Specific pairs of registers can
            used as 16-bit registers.

                Pairs:  Hi Lo -> (upper 8 bits, lower 8 bits)
                AF
                BC      B  C
                DE      D  E
                HL      H  L
                SP     
                PC

            F: stores an integer but it's not interpreted as so. Instead 
            it's interpreted bit-wise. Most of the bits stored here
            tells the CPU something about the result of the last operation. Only 
            bits 7-4 are used the lower 4 bits are always 0 and ignored.

                Bit     Name    Meaning (otherwise 0)
                7       Z       Zero flag, set to 1 if the result of the last op. is 0
                6       N       Subtract flag, set to 1 if the last op. was (-)
                5       H       Half-carry flag, set to 1 if there was a carry from bit 3 to 4
                4       C       Carry flag, set if there was a carry out of the 8 bit operation
            
            note: a carry out happens when an arithmetic op. results in an output to large to fit
            in the register. half-carry is a carry from the 3rd bit to 4th.



    2. Lastly, there are two special 16-bit registers: PC (Program Counter)
       and SP (Stack Pointer)

            - PC: 16-bit pointer to the next instruction in memory

            - SP: 16-bit pointer to the stack in memory. Used for storing 
            temporary data and returing addresses.
*/
struct CPU {
    uint8_t A,B,C,D,E,H,L,F // Each variable stores an integer 0-255
    uint16_t = PC; // PC and SP stores integers 0-65535
    uint16_t = SP;
}

/* 1.1
    Memory Space: essential, there should be memory locations where the 
    CPU can "point to" or use directly for reading instructions or data.
    The Game Boy has 64 KB of addressable memory (0x0000-0xFFFF = 65536).
*/

std::vector<uint8_t> memory(65536); // 64 KB

/* 1.2
   ROM file: is a digit version of a Game Boy cartridge. Essentially, all
   those bytes dumped into a single file. The size is usually between 32 KB
   - 8MB. We should be able to load ROM bytes into memory and read the bytes
   as instructions.
*/
