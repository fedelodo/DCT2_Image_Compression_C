#ifndef DCT2_TIMING_H
#define DCT2_TIMING_H

#include <string>
#include <vector>
#include <iostream>
#include <map>


class Timing {
public:
    struct inputsType{
        std::vector<int*> _matrices;
        int _resolution;
        inputsType(std::vector<int*> inputs, int resolution) : _matrices(inputs), _resolution(resolution) {}

        void print() {
            for (int i = 0; i < this->_matrices.size(); i++) {
                int *print = this->_matrices.at(i);
                int index = (i * _resolution) + 1;
                std::cout << std::endl << "MATRIX: " << i+1 << " - " << index << " " << std::endl;
                int matSize = index * index;
                for (int j = 0; j < matSize; j++) {
                    std::cout << print[j] << " " ;
                    if(((j+1) % (index) == 0)) {
                        std::cout << std::endl;
                    }
                }
            }
        }
    };

    Timing(double*(*funcParam)(const int *matrix, int size), const inputsType &input) : _funcParam(funcParam), _inputs(input) {
        computeResult();
    };
    std::map<int, int> getResults();
    void generateCSV(std::string filename);

    static inputsType generateInputs(int samples, int resolution);

    ~Timing() {
//        delete &_results;
//        delete &_inputs;
//        delete &_funcParam;
    }
private:
    std::map<int, int> _results;
    inputsType _inputs;
    double *(*_funcParam)(const int *matrix, int size);

    static int *generateRandomMatrix(int N);

    void computeResult();
};

#endif //DCT2_TIMING_H
