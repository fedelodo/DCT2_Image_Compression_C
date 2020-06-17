#ifndef DCT2_IMAE_COMPRESSION_C_DCT2_H
#define DCT2_IMAGE_COMPRESSION_C_DCT2_H

class DCT {
public:
    static double* DCT2Compute(const int *matrix, int size);


private:
    static double alpha2D(int k, int l, int N);

};


#endif //DCT2_IMAGE_COMPRESSION_C_DCT2_H
