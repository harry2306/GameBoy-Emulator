#include "CPU.h"
#include <iostream> 

CPU::CPU(Memory& mem) : memory(mem){
  reset();
}

void CPU::reset(){
  A = 0x0011;
  F = 0x0010;
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
  std::cout << "\033[2J"; // clear screen
  std::cout << "\033[1;1H"; // set to (1,1)
  // ------ Print the Outer Box ------
  for (int i = 0; i < 20; i++){
    std::cout << "- ";
  }
  for (int i = 1; i < 29; i++){
    std::cout << "\033[" << i << ";1H" << "l";
    std::cout << "\033[" << i << ";40H" << "l";
  }
  // ------ Tabulate ------
  std::cout << "\033[2;15H" << "REGISTER FILE";
  std::cout << "\033[3;2H";
  for (int j = 5; j < 24; j+= 2){
    for (int i = 0; i < 19; i++){
      std::cout << "- ";
      if (i == 8){
        std::cout << "\033[1B|\033[1A\033[1D";
      }
    }
    std::cout << "\033[" << j << ";2H";
  }
  // ------ Initialize ------
  for (int j = 4; j < 24; j+= 2){
      if (sepRegAF && j == 4){
        std::cout << "\033[" << j << ";3H 0x" << std::hex << (int)A;
        std::cout << "\033[" << j << ";22H 0x" << std::hex << (int)F;
      }
      if (sepRegCB && j == 6){
        std::cout << "\033[" << j << ";3H 0x" << std::hex << (int)C;
        std::cout << "\033[" << j << ";22H 0x" << std::hex << (int)B;
      }
      if (sepRegDE && j == 8){
        std::cout << "\033[" << j << ";3H 0x" << std::hex << (int)D;
        std::cout << "\033[" << j << ";22H 0x" << std::hex << (int)E;
      }
      if (sepRegHL && j == 10){
        std::cout << "\033[" << j << ";3H 0x" << std::hex << (int)H;
        std::cout << "\033[" << j << ";22H 0x" << std::hex << (int)L;
      }
  }
  std:: cout << "\033[30;40H";
  std::cout << std::endl;
}


