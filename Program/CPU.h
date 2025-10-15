#pragma once
#include <cstdint>
#include "Memory.h"

class CPU {

    public:
    CPU(Memory& mem); // constructor initialized by a memory object
    void Reset(); // resets registers and control lines to default
    void Step();

    private:
    // ---- Registers ----
    union{
        struct {uint8_t F; uint8_t A;};
        uint16_t AF;
    };

    union{
        struct {uint8_t C; uint8_t B;};
        uint16_t BC;
    };

    union{
        struct {uint8_t E uint8_t D;};
        uint16_t DE;
    };

    union{
        struct {uint8_t L; uint8_t H;};
        uint16_t HL;
    };

    uint16_t PC; // program counter
    uint16_t SP; // stack pointer

    bool Zflag() const {
        return F & 0x80;
    }

    bool Nflag() const{
        return F & 0x40;
    }

    bool Hflag() const{
        return F & 0x20;
    }

    bool CFlag() const{
        return F & 0x10;
    }

    void Zset(bool val){
        F = val ? (F | 0x80 ) : (F & ~0x80);
    }

    void Zset(bool val){
        F = val ? (F | 0x40 ) : (F & ~0x40);
    }

    void Zset(bool val){
        F = val ? (F | 0x20 ) : (F & ~0x10);
    }

    void print();
    uint8_t FetchByte();
    uint16_t FetchWord();
    void Execute(uint8_t opcode);

    Memory& memory;

};
