#include "Memory.h"

Memory::Memory(){
  mem.resize(0x10000,0x00); //64 KB
}

uint8_t Memory::Read(uint16_t addr) const{
  if (addr < mem.size())
      return mem[addr];
  return 0xFF;
}

void Memory::Write(uint16_t addr, uint8_t value) const{
  if (addr < mem.size())
      mem[addr] = value;
}
