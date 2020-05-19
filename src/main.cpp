#include <iostream>
#include "transforms/DCT.h"
#include "transforms/FFT.h"
#include "timing/Timing.h"

int main() {
    int samples = 100;
    Timing::inputsType inputs = Timing::generateInputs(samples, 10);
//    inputs.print();
    std::cout << "Computing our DCT2 time..." << std::endl;
    Timing dtc2Time(DCT::DCT2Compute, inputs);
    dtc2Time.generateCSV("DCT2.csv");

    std::cout << "Computing fftw time.." << std::endl;
    Timing fftTime(FFT::FFTWCompute, inputs);
    fftTime.generateCSV("fftw.csv");

    std::cout << "Done";

    return 0;
}