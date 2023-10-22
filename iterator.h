#pragma once

#include <tuple>

template <class T, typename IteratorType>
class Iterator{
public:
    Iterator(IteratorType matrixIterator):iterator(matrixIterator){}
    IteratorType getInsideIterator(){return this->iterator;}
    void operator++(){iterator++;}
    std::tuple<long, long, T> operator*(){return std::make_tuple(iterator->first.first, iterator->first.second, iterator->second);}
    void operator--(){iterator--;}
    bool operator !=(Iterator& other){return iterator != other.getInsideIterator();}
    bool operator ==(Iterator& other){return iterator == other.getInsideIterator();}
private:
    IteratorType  iterator;
};
