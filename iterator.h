#pragma once

#include <tuple>

template <class T, typename IteratorType, size_t Dimensions>
class Iterator{
public:
    Iterator(IteratorType matrixIterator):iterator(matrixIterator){}
    IteratorType getInsideIterator(){return this->iterator;}
    void operator++(){iterator++;}
    std::tuple<std::array<T, Dimensions>, T> operator*()
    {
        return std::make_tuple(iterator->first, iterator->second);
    }
    void operator--(){iterator--;}
    bool operator !=(Iterator& other){return iterator != other.getInsideIterator();}
    bool operator ==(Iterator& other){return iterator == other.getInsideIterator();}
private:
    IteratorType  iterator;
};
