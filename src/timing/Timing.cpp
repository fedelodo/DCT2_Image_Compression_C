#include "Timing.h"
#include <chrono>
#include <random>

std::vector<int> Timing::getResults() {
    return this->_results;
}

void Timing::computeResult()  {
    for(int i = 0; i < this->_inputs.size(); ++i) {
        int *matrix = this->_inputs.at(i);

        auto start = std::chrono::high_resolution_clock::now();
        _funcParam(matrix, i+1);
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
        int time = duration.count();

        _results.push_back(time);
    }
}

Timing::inputsType Timing::generateInputs(int samples, int resolution) {
    inputsType inputs(samples);

    for(int i = 0; i <= samples; i+=resolution) {
        int matSize = i+1;
        int *matrix = Timing::generateRandomMatrix(matSize);
        inputs.assign(i, matrix);
    }
    return inputs;
}

int *Timing::generateRandomMatrix(int N) {
    const int arraySize = N * N;
    int *matrix = new int[arraySize];

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, 255);
    for(int i = 0; i < arraySize; i++) {
        matrix[i] = dist(gen);//0 - 255
    }

    return matrix;
}

void Timing::generateCSV(std::string filename) {

}
