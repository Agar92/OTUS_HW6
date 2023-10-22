#pragma once

#include <map>
#include <tuple>
#include <array>
#include <proxy.h>
#include <iterator.h>

using std::pair, std::map, std::tuple;

template<class T, T DefaultValue, size_t Dimensions>
class Matrix{
    using IteratorType = typename map<coordinates<Dimensions>, T>::iterator;
public:
    Matrix() : DefaultCellValue(DefaultValue) {}
    Proxy<T, DefaultValue, Dimensions> operator[](long x)
    {
        //std::cout<<"Call Proxy<T, DefaultValue> operator[]("<<x<<")"<<std::endl;
        Proxy<T, DefaultValue, Dimensions> proxy(this, x);
        return proxy;
    }
    size_t size(){return matrix.size();}
    T getDefaultCellValue(){return DefaultCellValue;}
    const T& findByCoordinates(coordinates<Dimensions> coord) const
    {
        //std::cout<<"Call const T& findByCoord(pair<long, long> coordinates) const"<<std::endl;
        auto it = matrix.find(coord);
        if(it == matrix.end()) return DefaultCellValue;
        else                   return it->second;
    }
    void removeCell(coordinates<Dimensions> coord)
    {
        //std::cout<<"removeCell"<<std::endl;
        matrix.erase(matrix.find(coord));
    }
    void insertCell(coordinates<Dimensions> coord, T value)
    {
        //std::cout<<"insertCell"<<std::endl;
        matrix.emplace(coord, value);
    }
    void modifyCell(coordinates<Dimensions> coord, T value)
    {
        //std::cout<<"modifyCell"<<std::endl;
        matrix.at(coord) = value;
    }
    size_t GetNumberIfDimensions() const {return Dimensions;}
    Iterator<T,IteratorType, Dimensions> begin(){return Iterator<T,IteratorType, Dimensions>(matrix.begin());};
    Iterator<T,IteratorType, Dimensions> end(){return Iterator<T,IteratorType, Dimensions>(matrix.end());};
private:
    const T DefaultCellValue;
    map<coordinates<Dimensions>, T> matrix;
};