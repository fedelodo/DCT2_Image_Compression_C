#ifndef DCT2_TIMING_H
#define DCT2_TIMING_H

#include <string>
#include <vector>
#include <iostream>
#include <map>

/*
 *  The Timing class is build to measure the performance of any function that can receive an int matrix as input.
 *  It can be used by passing a function pointer of the function that you want to analyze and a set of
 *  matrices(inputsType) that will be used as inputs for the function when measuring execution times.
 *  This class provides a method to generate a set of quare matrices filled with random values.
 *  The results will be saved in a map that contain the size of the square matrix as a key and the execution time
 *  as a value.
 *  Results can be written to a CSV file using the generateCSV method.
 */
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
                    std::cout << print[j] << " ";
                    if(((j+1) % (index) == 0)) {
                        std::cout << std::endl;
                    }
                }
            }
        }

        void cleanup(){
            for(int *matrix : _matrices) {
                delete[] matrix;
            }
        }
    };

    Timing(double*(*funcParam)(const int *matrix, int size), const inputsType &input) : _funcParam(funcParam), _inputs(input) {
        computeResult();
    };
    std::map<int, int> getResults();
    void generateCSV(std::string filename);

    static inputsType generateInputs(int samples, int resolution);
private:
    std::map<int, int> _results;
    inputsType _inputs;
    double *(*_funcParam)(const int *matrix, int size);

    static int *generateRandomMatrix(int N);

    void computeResult();
};

#endif //DCT2_TIMING_H
