#ifndef DCT2_IMAE_COMPRESSION_C_DCT2_H
#define DCT2_IMAGE_COMPRESSION_C_DCT2_H

class DCT2 {
public:
    typedef double DCT2matrix;
    static DCT2matrix* DCT2Compute2D(const int *matrix, int size);
    static DCT2matrix* DCT2Compute1D(const int *array, int size);


private:
    static DCT2matrix alpha2D(int k, int l, int N);
    static DCT2matrix alpha1D(int k,int N);

};


#endif //DCT2_IMAGE_COMPRESSION_C_DCT2_H
