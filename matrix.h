#pragma once

#include <map>
#include <tuple>
#include <array>
#include <proxy.h>
#include <iterator.h>

using std::pair, std::map, std::tuple;

template <size_t Dimensions>
struct coordinates{
    std::array<int, Dimensions> coord;
};

template<class T, T DefaultValue>
class Matrix{
    using IteratorType = typename map<pair<long, long>, T>::iterator;
public:
    Matrix() : DefaultCellValue(DefaultValue) {}
    Proxy<T, DefaultValue> operator[](long x)
    {
        //std::cout<<"Call Proxy<T, DefaultValue> operator[]("<<x<<")"<<std::endl;
        Proxy<T, DefaultValue> proxy(this, x);
        return proxy;
    }
    size_t size(){return matrix.size();}
    T getDefaultCellValue(){return DefaultCellValue;}
    const T& findByCoordinates(pair<long, long> coordinates) const
    {
        //std::cout<<"Call const T& findByCoord(pair<long, long> coordinates) const"<<std::endl;
        auto it = matrix.find(coordinates);
        if(it == matrix.end()) return DefaultCellValue;
        else                   return it->second;
    }
    void removeCell(pair<long, long> coordinates)
    {
        //std::cout<<"removeCell"<<std::endl;
        matrix.erase(matrix.find(coordinates));
    }
    void insertCell(pair<long, long> coordinates, T value)
    {
        //std::cout<<"insertCell"<<std::endl;
        matrix.emplace(coordinates, value);
    }
    void modifyCell(pair<long, long> coordinates, T value)
    {
        //std::cout<<"modifyCell"<<std::endl;
        matrix.at(coordinates) = value;
    }
    Iterator<T,IteratorType> begin(){return Iterator<T,IteratorType>(matrix.begin());};
    Iterator<T,IteratorType> end(){return Iterator<T,IteratorType>(matrix.end());};
private:
    const T DefaultCellValue;
    map<pair<long, long>, T> matrix;
};