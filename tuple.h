#pragma once

namespace try_tuple
{
    template <typename T, size_t I> 
    struct tuple_n{
        template< typename...Args> using type = typename tuple_n<T, I-1>::template type<T, Args...>;
    };

    template <typename T> 
    struct tuple_n<T, 0> {
        template<typename...Args> using type = std::tuple<Args...>;   
    };
    template <typename T, size_t I>  using tuple_of = typename tuple_n<T, I>::template type<>;
//HOW TO USE THIS?
//tuple_of<double, 3> t;    
}//namespace try_tuple

namespace variadic{


template<size_t idx, typename T>
struct GetHelper;

template<typename ... T>
struct tuple
{
};

template<typename T, typename ... Rest>
struct tuple<T, Rest ...>
{
    tuple(const T& first, const Rest& ... rest)
        : first(first)
        , rest(rest...)
    {}
    
    T first;
    tuple<Rest ... > rest;
    
    template<size_t idx>
    auto get()
    {
        return GetHelper<idx, tuple<T,Rest...>>::get(*this);
    }
};

template<typename T, typename ... Rest>
struct GetHelper<0, tuple<T, Rest ... >>
{
    static T get(tuple<T, Rest...>& data)
    {
        return data.first;
    }
};

template<size_t idx, typename T, typename ... Rest>
struct GetHelper<idx, tuple<T, Rest ... >>
{
    static auto get(tuple<T, Rest...>& data)
    {
        return GetHelper<idx-1, tuple<Rest ...>>::get(data.rest);
    }
};


}//namespace tuple