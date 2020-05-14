#ifndef DCT2_IMAGE_COMPRESSION_C_DCT2_H
#define DCT2_IMAGE_COMPRESSION_C_DCT2_H

class DCT2 {
    public:
        auto* DCT2Compute(int *matrix,int size);

    private:
        static float alphakl(int k, int l, int N);
};


#endif //DCT2_IMAGE_COMPRESSION_C_DCT2_H
