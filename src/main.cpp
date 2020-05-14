#include <stdio.h>
#include <iostream>
#include "DCT2/DCT2.h"


int main() {
    int input[] {231, 32, 233, 161, 24, 71, 140, 245, 247, 40, 248, 245, 124, 204, 36, 107, 234, 202, 245, 167, 9, 217, 239, 173, 193, 190, 100, 167, 43, 180, 8, 70, 11, 24, 210, 177, 81, 243, 8, 112, 97, 195, 203, 47, 125, 114, 165, 181, 193, 70, 174, 167, 41, 30, 127, 245, 87, 149, 57, 192, 65, 129, 178, 228};
    auto *output = new float[8];
    output = DCT2::DCT2Compute2D(input, 8);
    for (int z = 0; z < sizeof(input)/sizeof(input[0]); z++)
    {
        std::cout << *&output[z] << " ";
        if(z != 0 && z % 7 == 0) {
            std::cout << std::endl;
        }
    }
    return 0;
}