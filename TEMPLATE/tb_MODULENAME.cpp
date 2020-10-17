#include <iostream>
#include <cstdlib>
#include <bitset>
#include "TestBench.hpp"
#include "VMODULENAME.h"
#include "verilated.h"

int main(int argc, char* argv[])
{
    Verilated::commandArgs(argc, argv);
    TestBench<VMODULENAME> tb = TestBench<VMODULENAME>();

    for (int t = 0; t < 20; t++)
    {
        tb.Tick();
        printf("t = %02d, ", t);
        printf("i_clk = %d, ", tb.GetModule()->i_clk);
        std::bitset<8> o_count_bits(tb.GetModule()->o_count);
        std::cout << "o_count = " << o_count_bits << ", ";
        printf("\n");
    }
}
