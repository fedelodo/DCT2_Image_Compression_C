#include <iostream>
#include "transforms/DCT.h"
#include "transforms/FFT.h"
#include "timing/Timing.h"

int main() {
    int samples = 500;
    std::cout << "Generating Sample matrix...";
    Timing::inputsType inputs = Timing::generateInputs(samples);
    Timing dtc2Time(DCT::DCT2Compute, inputs);
    Timing fftTime(FFT::FFTWCompute, inputs);
    std::cout << "Computing our DCT2 time...";
    dtc2Time.generateCSV("DCT2.csv");
    std::cout << "Computing fftw time..";
    fftTime.generateCSV("fftw.csv");
    std::cout << "Done";
//    for (int i = 0; i<inputs.size(); i++) {
//        int *print = inputs.at(i);
//        std::cout << "VECTOR: " << i << " " << std::endl;
//        int matSize = (i+1) * (i+1);
//        for (int j = 0; j < matSize; j++) {
//            std::cout << print[j] << " " ;
//            if(((j+1) % (i+1) == 0)) {
//                std::cout << std::endl;
//            }
//        }
//    }

    return 0;
}


/*
auto start = std::chrono::high_resolution_clock::now();
auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    int time = duration.count();
    ourfunctionfile << time;
 */