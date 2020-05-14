
#define _USE_MATH_DEFINES

#include "DCT2.h"
#include <math.h>
///This function computes DCT2 of a matrix of int
DCT2::DCT2matrix *DCT2::DCT2Compute(const int *matrix) {
    // allocando la memoria come  type *array = new type[sizeX*sizeY];
    // consente di gestire in modo più efficente gli array in quanto alloca un unico
    // blocco di memoria l' accesso all' elemento array[i][j] può essere fatto con array[i*sizeY+j]
    const  int size = sizeof(matrix)/sizeof(matrix[0]);
    DCT2matrix *c;
    c = new DCT2matrix[size * size];
    DCT2::DCT2matrix sum;
    int l,k,i,j,N;
    N=size;
    for(k=0; k < N; k++)
    {
        for (l = 0; l < N; l++) {
            sum = 0;
            for (i = 0; i < N; i++)
            {
                for (j = 0; j < N; j++) {
                    sum += matrix[i*size+j]*
                            cos(k*M_PI*((2*(DCT2::DCT2matrix)i+1)/2*(DCT2::DCT2matrix)N))*
                            cos(l*M_PI*((2*(DCT2::DCT2matrix)j+1)/(2*(DCT2::DCT2matrix)N)));
                }
            }
            c[i*size+j] = alphakl(k,l,N) * sum;
        }
    }
    return c;
}

///This functions computes alphakl values
DCT2::DCT2matrix DCT2::alphakl(int k, int l, int N) {
    if(k > 0 && l > 0) {
        return 2/(DCT2matrix)N;
    }
    else if(l == 0 || k == 0) {
        return M_SQRT2/(DCT2matrix)N;
    }
    else {
        return 1/(DCT2matrix)N;
    }
}
