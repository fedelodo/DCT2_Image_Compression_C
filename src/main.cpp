#include <iostream>
#include "transforms/DCT.h"
#include "transforms/FFT.h"
#include "timing/Timing.h"

int main() {
    int samples = 100;
    std::cout << "Generating Sample matrix...";
    Timing::inputsType inputs = Timing::generateInputs(samples, 10);
//    inputs.print();
    Timing dtc2Time(DCT::DCT2Compute, inputs);
    Timing fftTime(FFT::FFTWCompute, inputs);
    std::cout << "Computing our DCT2 time...";
    dtc2Time.generateCSV("DCT2.csv");
    std::cout << "Computing fftw time..";
    fftTime.generateCSV("fftw.csv");
    std::cout << "Done";

    return 0;
}