#include "CPU.h"
#include "Memory.h"


int main(){

Memory gbMem;
CPU gbCPU(gbMem);
gbCPU.print();


return 0;
}
