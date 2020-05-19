#include "Timing.h"
#include <chrono>
#include <random>
#include <fstream>
#include <iostream>

std::map<int, int> Timing::getResults() {
    return this->_results;
}

void Timing::computeResult()  {
    std::cout << "Computing" << std::endl;
    std::vector<int*> input = _inputs._matrices;
    for(int i = 0; i < input.size(); ++i) {
        int *matrix = input.at(i);
        int index = (i * _inputs._resolution) + 1;

        auto start = std::chrono::high_resolution_clock::now();
//        _funcParam(matrix, index);
        double * result = _funcParam(matrix, index);
        auto stop = std::chrono::high_resolution_clock::now();
        delete result;

        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
        int time = duration.count();
        std::cout << "Computing " << index << "x" << index << std::endl;
        _results.emplace(index, time);
    }
}

Timing::inputsType Timing::generateInputs(int samples, int resolution) {
    std::vector<int*> inputs;
    std::cout << "Generating input matrix" << std::endl;
    for(int i = 0; i < (int)(samples/resolution); ++i) {
        int matSize = (i*resolution)+1;
        std::cout << "Generating: " << matSize << "x" << matSize << std::endl;
        int *matrix = Timing::generateRandomMatrix(matSize);
        inputs.push_back(matrix);

        delete matrix;
    }
    std::cout << std::endl;
    return inputsType(inputs, resolution);
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
    std::ofstream file;
    file.open(filename, std::ofstream::trunc);//TODO: Check file open
    std::map<int, int> times = this->getResults();

    file << "Size;Times";
    for(std::map<int,int>::iterator it = times.begin(); it != times.end(); ++it) {
        file << std::endl << std::to_string(it->first) << ";" << std::to_string(it->second);
    }
    file.close();
}
