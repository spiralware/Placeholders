#include <cstddef>

#include <iostream>
#include <string>
#include <typeinfo>

//=======================================================

template<size_t N, typename Head, typename ... Tail>
class N_th
{
public:
    typedef typename N_th<N - 1, Tail...>::type type;
};

template<typename Head, typename ... Tail>
class N_th<0, Head, Tail...>
{
public:
    typedef Head type;
};

//=======================================================

template<size_t N>
class placeholder : placeholder<N - 1>
{
public:
    template<typename Head, typename ... Tail>
    typename N_th<N, Head, Tail...>::type operator()(Head head, Tail ... tail)
    {
        return placeholder<N - 1>::operator()(tail...);
    }
};

template<>
class placeholder<0>
{
public:
    template<typename Head, typename ... Tail>
    Head operator()(Head head, Tail ... args)
    {
        return head;
    }
};

//=======================================================

class A {};
class B {};
class C {};

int main()
{
    //=======================================================

    std::cout << typeid(N_th<0, int, double, std::string>::type).name() << std::endl;
    std::cout << typeid(N_th<1, int, double, std::string>::type).name() << std::endl;
    std::cout << typeid(N_th<2, int, double, std::string>::type).name() << std::endl;

    std::cout << typeid(N_th<0, A, B, C>::type).name() << std::endl;
    std::cout << typeid(N_th<1, A, B, C>::type).name() << std::endl;
    std::cout << typeid(N_th<2, A, B, C>::type).name() << std::endl;

    //=======================================================

    placeholder<0> pl_0;
    placeholder<1> pl_1;
    placeholder<2> pl_2;
    std::cout << pl_0(5, "c_str", 3.14) << std::endl;
    std::cout << pl_1(5, "c_str", 3.14) << std::endl;
    std::cout << pl_2(5, "c_str", 3.14) << std::endl;

    return 0;
}
