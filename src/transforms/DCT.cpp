
#define _USE_MATH_DEFINES

#include "DCT.h"
#include <math.h>
#include <iostream>

//This function computes DCT of a matrix of int
DCT::result_type* DCT::DCT2Compute(const int *matrix, int size) {
    // allocando la memoria come  type *array = new type[sizeX*sizeY];
    // consente di gestire in modo più efficente gli array in quanto alloca un unico
    // blocco di memoria l' accesso all' elemento array[i][j] può essere fatto con array[i*sizeY+j]
    result_type *c;
    c = new result_type[size * size];
    result_type sum;
    int l,k,i,j,N;
    N = size;
    for(k=0; k < N; k++) {
        for (l = 0; l < N; l++) {
            sum = 0;
            for (i = 0; i < N; i++) {
                for (j = 0; j < N; j++) {
                    sum += matrix[i*size+j] *
                           cos(k*M_PI*((result_type)(2*i+1)/(result_type)(2*N))) *
                           cos(l*M_PI*((result_type)(2*j+1)/(result_type)(2*N)));
                }
            }
            c[k*size+l] = alpha2D(k,l,N) * sum;
        }
    }
    return c;
}

///This function computes DCT of a matrix of int
DCT::result_type* DCT::DCT1Compute(const int *array, int size) {
    DCT::result_type *c;
    c = new DCT::result_type[size];
    DCT::result_type sum;
    int k,i,N;
    N=size;
    for(k=0; k < N; k++) {
        sum = 0;
        for (i = 0; i < N; i++) {
            sum += array[i] *
                   cos(k*M_PI*((result_type)(2*i+1)/(result_type)(2*N)));
        }
        c[k] = alpha1D(k,N) * sum;
    }
    return c;
}

///This functions computes alphakl values
DCT::result_type DCT::alpha2D(int k, int l, int N) {
    if(k == 0 && l == 0) {
        return 1/(result_type)N;
    }
    else if(l == 0 || k == 0) {
        return M_SQRT2/(result_type)N;
    }
    else {
        return 2/(result_type)N;
    }
}

DCT::result_type DCT::alpha1D(int k, int N) {
    if(k > 0 ) {
        return sqrt(2/(result_type)N);
    }
    else {
        return 1/sqrt((result_type)N);
    }
}