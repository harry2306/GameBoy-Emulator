#include "CPU.h"
#include <iostream> 

CPU::CPU(Memory& mem) : memory(mem){
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
  return (upperByte << 8) | lowerByte;
}

void CPU::Execute(uint8_t opcode){
  switch (opcode){
    case 0x00:
      break;
  }
}

void CPU::print(){
  void CPU::print(){
  std::cout << "\033[2J"; // clear screen
  std::cout << "\033[1;1H"; // set to (1,1)
  // ------ Print the Outer Box ------
  for (int i = 0; i < 20; i++){
    std::cout << "- ";
  }
  for (int i = 1; i < 30; i++){
    std::cout << "\033[" << i << ";1H" << "l";
    std::cout << "\033[" << i << ";40H" << "l";
  }
  std::cout << "\033[30;2H";
  for (int i = 0; i < 19; i++){
    std::cout << "- ";
  }
  // ------ Tabulate/Initialize ------
  std::cout << "\033[2;15H" << "REGISTER FILE";





  std:: cout << "\033[30;40H";
  std::cout << std::endl;
}

