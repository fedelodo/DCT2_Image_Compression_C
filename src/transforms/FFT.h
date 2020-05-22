#ifndef DCT2_FFT_H
#define DCT2_FFT_H

#include "../include/fftw3.h"

class FFT {
public:
    static double *FFTWCompute(const int *input,int N);
};


#endif //DCT2_FFT_H
