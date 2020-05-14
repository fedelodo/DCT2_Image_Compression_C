#ifndef DCT2_IMAE_COMPRESSION_C_DCT2_H
#define DCT2_IMAGE_COMPRESSION_C_DCT2_H

class DCT2 {
    typedef float DCT2matrix;
    public:
        static DCT2matrix* DCT2Compute(const int *matrix);

    private:
        static DCT2matrix alphakl(int k, int l, int N);
};


#endif //DCT2_IMAGE_COMPRESSION_C_DCT2_H
