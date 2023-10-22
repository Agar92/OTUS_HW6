#include <iostream>
#include <string>
#include <cassert>
#include <tuple>
#include <vector>
#include <matrix.h>
#include <tuple.h>

int main(int argc, char const *argv[]) {
    Matrix<int, 0, 2> matrix;

    assert(matrix.size() == 0);
    auto a = matrix[0][0];
/*
Call Proxy<T, DefaultValue> operator[](0)
Call Proxy& operator[](0)
Call const T& findByCoordinates(pair<long, long> coordinates) const
Call operator T()
*/
    assert(a == 0);
    assert(matrix.size() == 0);
    matrix[100][100] = 100;
    assert(matrix[100][100] == 100);
    assert(matrix.size() == 1);
    matrix[100][100] = 0;
    assert(matrix[100][100] == 0);
    assert(matrix.size() == 0);


    for (auto i = 0; i < 10; i++)
        matrix[i][i] = i;
    for (auto i = 0, j = 9; i < 10; i++, j--)
        matrix[i][j] = j;

    for(auto i = 1; i < 9; i++){
        for (auto j = 1; j < 9; j++){
            std::cout<<matrix[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
    
    std::cout<<"size: "<<matrix.size()<<std::endl;

    for(auto c : matrix){
        std::array<int, 2> Array;
        int v;
        std::tie(Array, v) = c;
        std::cout<<"["<<Array[0]<<"]"<<"["<<Array[1]<<"]"<<" value: "<<v<< std::endl;
    }
    //((((matrix[100][100] = 314) = 0) = 217) = -2) = 129;
    //std::cout<<matrix[100][100]<<std::endl;
    return 0;
}