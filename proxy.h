#pragma once

#include <matrix.h>

template <size_t Dimensions>
using coordinates = std::array<int, Dimensions>;

template<class T, T DefaultValue, size_t Dimensions>
class Matrix;

template<class T, T DefaultValue, size_t Dimensions>
class Proxy{
    using indices = std::array<int, Dimensions-1>;
public:
    Proxy(Matrix<T, DefaultValue, Dimensions> * matrixPtr_, long x_) : matrixPtr(matrixPtr_), cell(0), x(x_) {}
    Proxy& operator[](int y)
    {
        //std::cout<<"Call Proxy& operator[]("<<y<<")"<<std::endl;
        counter++;
        coord[counter]=y;
        if(Dimensions-1 == counter)
        {
            counter=0;
            coord[0]=x;
            cell = matrixPtr->findByCoordinates(coord);
        }
        return *this;
    }
    Proxy& operator=(T newValue)
    {
        //std::cout<<"Call Proxy& operator=("<<newValue<<") | cell="<<cell<<std::endl;
        if(newValue != matrixPtr->getDefaultCellValue())
        {
            //std::cout<<"Channel #1"<<std::endl;
            if(cell != matrixPtr->getDefaultCellValue())
            {
                cell = newValue;
                matrixPtr->modifyCell(coord, newValue);
                //std::cout<<"Channel #1.1 cell="<<cell<<std::endl;
            }
            else
            {
                cell = newValue;
                matrixPtr->insertCell(coord, newValue);
                //std::cout<<"Channel #1.2 cell="<<cell<<std::endl;
            }
        }
        else
        {
            //std::cout<<"Channel #2"<<std::endl;
            if(cell != matrixPtr->getDefaultCellValue())
            {
                //std::cout<<"Channel #2.1"<<std::endl;
                matrixPtr->removeCell(coord);
                cell=0;
                return *this;
            }
            else
            {
                //std::cout<<"Channel #2.2"<<std::endl;
                return *this;
            }
        }
        return *this;
    }
    operator T()
    {
        //std::cout<<"Call operator T()"<<std::endl;
        return cell;
    }
private:
    long x;
    int counter=0;
    coordinates<Dimensions> coord;
    T cell;
    Matrix<T, DefaultValue, Dimensions>*  matrixPtr;
};