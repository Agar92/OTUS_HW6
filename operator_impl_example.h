#pragma once

template <size_t Dimensions>
class C{
    using type=int;
    using coordinates=std::array<int, Dimensions>;
    typedef std::map<coordinates, type>::const_iterator _Iterator;
    class Proxy{
    public:
        Proxy(C * _c, int X):c(_c), x(X){}
        Proxy& operator[](int index)
        {
            std::cout<<"Proxy& operator[]("<<index<<")"<<std::endl;
            indices[counter++]=index;
            std::cout<<"indices:"<<std::endl;
            for(auto i : indices) std::cout<<i<<" ";
            std::cout<<std::endl;
            return *this;
        }
        operator int() const
        {
            std::cout<<"operator int() const"<<std::endl;
            _Iterator iter=(*c).m.find({x,indices[0], indices[1]});
            if(iter==(*c).m.end()) return -1;
            else                   return iter->second;
        }
    private:
        C * c;
        type x;
        type value;
        int counter=0;
        std::array<int, Dimensions-1> indices;
    };
    friend class Proxy;
public:
    C(){}
    void Add(const coordinates & coord, type val)
    {
        m[coord]=val;
    }
    Proxy operator [](int index)
    {
        std::cout<<"Proxy operator []("<<index<<")"<<std::endl;
        return Proxy(this, index);
    }
private:
    std::map<coordinates, type> m;
};

class A{
public:
    A(){}
    A& operator[](int index)
    {
        indices[counter]=index;
        counter++;
        std::cout<<"A& operator[]("<<index<<")"<<std::endl;
        if(counter==3)
        {
            std::cout<<"Return ["<<indices[0]<<","<<indices[1]<<","<<indices[2]<<"]"<<std::endl;
            counter=0;
        }
        return *this;
    }
private:
    int counter=0;
    std::array<int, 3> indices;
    std::array<int ,3> array{12,15,17};
};
