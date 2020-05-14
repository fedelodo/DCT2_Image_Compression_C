#include <stdio.h>
#include <iostream>
#include "DCT2/DCT2.h"


int main() {
    int input[] {231,32,233,161,24,71,140,245};
    auto *output = new float[8];
    output = DCT2::DCT2Compute1D(input, 8);
    for (int z = 0; z < sizeof(input)/sizeof(input[0]); z++)
    {
        std::cout << "element:";
        std::cout << *&output[z];
    }
    return 0;
}