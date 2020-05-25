#include "FFT.h"

double *FFT::FFTWCompute(const int *input, int N) {
    int arraySize = N*N;
    double in[arraySize], *out;
    out = new double[arraySize];

    //std::copy(input, input + arraySize, in);//BROKEN AF
    for(int i = 0; i<arraySize; ++i) {
        in[i] = (double)input[i];
    }

    fftw_plan my_plan;
    my_plan = fftw_plan_r2r_2d(N, N, in, out, FFTW_REDFT10, FFTW_REDFT10, FFTW_ESTIMATE);
    fftw_execute(my_plan);
    fftw_destroy_plan(my_plan);
    fftw_cleanup();
    return out;
}
