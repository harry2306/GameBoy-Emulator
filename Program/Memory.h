#pragma once
#include <cstdint>
#include <vector>

class Memory{
    public:
    Memory();
    uint8_t Read(uint16_t addr) const;
    void Write(uint16_t addr, uint8_t value);

    private:
        std::vector<uint8_t> mem;
};
