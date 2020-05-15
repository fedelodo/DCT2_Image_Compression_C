#include <chrono>
#include <iostream>
#include <fstream>
#include <functional>
#include "DCT2/DCT.h"
#include <fftw3.h>
#include "math.h"

double *usefftw(int *input,int N){
    double *in, *out;
    out = new double[N];
    in = (double *)input;
    fftw_plan my_plan;
    my_plan = fftw_plan_r2r_1d(N, in, out, FFTW_REDFT10, FFTW_ESTIMATE);
    fftw_execute(my_plan);
    fftw_destroy_plan(my_plan);
    return out;
}

int main() {
    int input[] {231, 32, 233, 161, 24, 71, 140, 245, 247, 40, 248, 245, 124, 204, 36, 107, 234, 202, 245, 167, 9, 217, 239, 173, 193, 190, 100, 167, 43, 180, 8, 70, 11, 24, 210, 177, 81, 243, 8, 112, 97, 195, 203, 47, 125, 114, 165, 181, 193, 70, 174, 167, 41, 30, 127, 245, 87, 149, 57, 192, 65, 129, 178, 228};    std::ofstream ourfunctionfile;
    std::ofstream FFTWfile;
    FFTWfile.open("fftw.csv", std::ios_base::app);
    ourfunctionfile.open("ourfunction.csv", std::ios_base::app);
    auto *output = new double[64];
    auto *output1 = new double[64];
    output = DCT::DCT2Compute(input, 8);
    output1 =usefftw(input, 64);
    std::cout << "ourfunc: " << std::endl;
    for (int i=0;i < (sizeof(input)/sizeof(input[0]));i++) {
        std::cout << output[i] << std::endl;
    }
    std::cout << "fftw: " << std::endl;
    for (int i=0;i < (sizeof(input)/sizeof(input[0]));i++) {
        std::cout << output1[i] << std::endl;
    }
    return 0;
}


/*
auto start = std::chrono::high_resolution_clock::now();
auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    int time = duration.count();
    ourfunctionfile << time;
 */