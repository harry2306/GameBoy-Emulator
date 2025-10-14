#include "CPU.h"

CPU::CPU(Memor& mem) : memory(mem){
  Reset();
}

void CPU::Reset(){
  return;
}

void CPU::Step(){
  uint8_t opcode = FetchByte();
  Execute(opcode);

}
uint8_t CPU::FetchByte(){
  uint8_t byte = memory.Read(PC);
  PC++;
  return byte;
}

uint16_t CPU::FetchWord(){
  uint8_t lowerByte = FetchByte();
  uint8_t upperByte = FetchByte();
  return (high << 8) | low;
}

void CPU::Execute(uint8_t opcode){
  switch (opcode){
    case 0x00:
      break;
  }
}

void CPU::printCPU(){
  \033[s;
  for (int i = 0; i < 15; i++){
    cout << "-";
  }
  for (int i = 0; i < 15; i++){
    \033[B;
    cout << "|";
  }
}
