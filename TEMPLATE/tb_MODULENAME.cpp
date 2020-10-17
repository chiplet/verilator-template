#include <iostream>
#include <cstdlib>
#include "VMODULENAME.h"
#include "verilated.h"

int main(int argc, char* argv[])
{
    Verilated::commandArgs(argc, argv);
    VMODULENAME* tb = new VMODULENAME;

    for (int k = 0; k < 20; k++)
    {
        tb->in_wire = k & 1;
        tb->eval();

        printf("k = %02d, ", k);
        printf("in_wire = %d, ", tb->in_wire);
        printf("out_wire = %d, ", tb->out_wire);
        printf("\n");
    }
}
