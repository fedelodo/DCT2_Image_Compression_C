
#include "DCT2.h"
#include <math.h>
#define _USE_MATH_DEFINES

float **DCT2::DCT2Compute(int **matrix,int size) {
    float **out;
    float alphakl;
    float sum;
    int l,k,i,j,N,M;
    N=M=size;
    for(k=0; k<N; k++)
    {
        for (l = 0; l < size; l++) {
            if (k == 0 && l == 0) {
                alphakl = 1.0f / N;
            }
            if (k == 0 || l == 0) {
                alphakl = M_SQRT2  / N;
            }
            else {
                alphakl = 2.0f / N;
            }
            sum = 0;
            for (i = 0; i < size; i++)
            {
                for (j = 0; j < size; j++) {
                    sum += matrix[i][j]*cos(k*M_PI*((2*i+1)/2*N))*cos(l*M_PI*((2*j+1)/(2*M)));
                }
            }
            out[k][l] = alphakl * sum;
        }
    }

    return out;
}
