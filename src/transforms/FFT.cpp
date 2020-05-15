//
// Created by emagi on 15/05/2020.
//

#include "FFT.h"

double *FFT::FFTWCompute(int *input, int N) {
    double *in, *out;
    out = new double[N];
    in = (double *)input;
    fftw_plan my_plan;
    my_plan = fftw_plan_r2r_1d(N, in, out, FFTW_REDFT10, FFTW_ESTIMATE);
    fftw_execute(my_plan);
    fftw_destroy_plan(my_plan);
    return out;
}
