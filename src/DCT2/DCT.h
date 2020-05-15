#ifndef DCT2_IMAE_COMPRESSION_C_DCT2_H
#define DCT2_IMAGE_COMPRESSION_C_DCT2_H

class DCT {
public:
    typedef double result_type;
    static result_type* DCT2Compute(const int *matrix, int size);
    static result_type* DCT1Compute(const int *array, int size);


private:
    static result_type alpha2D(int k, int l, int N);
    static result_type alpha1D(int k, int N);

};


#endif //DCT2_IMAGE_COMPRESSION_C_DCT2_H
