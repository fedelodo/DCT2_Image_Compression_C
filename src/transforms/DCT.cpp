
#define _USE_MATH_DEFINES

#include "DCT.h"
#include <math.h>
#include <iostream>

//This function computes DCT of a matrix of int
double *DCT::DCT2Compute(const int *matrix, int size) {
    // allocando la memoria come  type *array = new type[sizeX*sizeY];
    // consente di gestire in modo più efficente gli array in quanto alloca un unico
    // blocco di memoria l' accesso all' elemento array[i][j] può essere fatto con array[i*sizeY+j]
    double *c;
    c = new double[size * size];
    double sum;
    int l,k,i,j,N;
    N = size;
    for(k=0; k < N; k++) {
        for (l = 0; l < N; l++) {
            sum = 0;
            for (i = 0; i < N; i++) {
                for (j = 0; j < N; j++) {
                    sum += matrix[i*size+j] *
                           cos(k*M_PI*((double)(2*i+1)/(double)(2*N))) *
                           cos(l*M_PI*((double)(2*j+1)/(double)(2*N)));
                }
            }
            c[k*size+l] = alpha2D(k,l,N) * sum;
        }
    }
    return c;
}

///This function computes DCT of a matrix of int
double *DCT::DCT1Compute(const int *array, int size) {
    double *c;
    c = new double[size];
    double sum;
    int k,i,N;
    N=size;
    for(k=0; k < N; k++) {
        sum = 0;
        for (i = 0; i < N; i++) {
            sum += array[i] *
                   cos(k*M_PI*((double)(2*i+1)/(double)(2*N)));
        }
        c[k] = alpha1D(k,N) * sum;
    }
    return c;
}

///This functions computes alphakl values
double DCT::alpha2D(int k, int l, int N) {
    if(k == 0 && l == 0) {
        return 1/(double)N;
    }
    else if(l == 0 || k == 0) {
        return M_SQRT2/(double)N;
    }
    else {
        return 2/(double)N;
    }
}

double DCT::alpha1D(int k, int N) {
    if(k > 0 ) {
        return sqrt(2/(double)N);
    }
    else {
        return 1/sqrt((double)N);
    }
}