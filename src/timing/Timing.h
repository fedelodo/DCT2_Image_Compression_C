#ifndef DCT2_TIMING_H
#define DCT2_TIMING_H

#include <string>
#include <vector>


class Timing {
public:
    typedef std::vector<int*> inputsType;
    Timing(double*(*funcParam)(const int *matrix, int size), const inputsType &input) : _funcParam(funcParam), _inputs(input) {
        computeResult()
    };
    std::vector<int> getResults();
    void generateCSV(std::string filename);

    static inputsType generateInputs(int samples);

private:
    std::vector<int> _results;
    inputsType _inputs;
    double *(*_funcParam)(const int *matrix, int size);

    static int *generateRandomMatrix(int N);

    void computeResult();
};

#endif //DCT2_TIMING_H
