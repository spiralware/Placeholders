#include <cstddef>

#include <iostream>
#include <string>

template<size_t N, typename ... Args>
class N_th
{
};

template<size_t N>
class placeholder
{
public:
    template<typename ... Args>
    void operator()(Args ... args)
    {
        /*if (N == 0)
        return arg1;
        if (N == 1)
        return arg2;
        if (N == 2)
        return arg3;*/
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

/*template<>
class placeholder<1>
{
public:
    template<typename arg1_t, typename arg2_t, typename arg3_t>
    arg1_t operator()(const arg1_t& arg1, const arg2_t& arg2, const arg3_t& arg3)
    {
        return arg1;
    }
};

template<>
class placeholder<2>
{
public:
    template<typename arg1_t, typename arg2_t, typename arg3_t>
    arg2_t operator()(const arg1_t& arg1, const arg2_t& arg2, const arg3_t& arg3)
    {
        return arg2;
    }
};

template<>
class placeholder<3>
{
public:
    template<typename arg1_t, typename arg2_t, typename arg3_t>
    arg3_t operator()(const arg1_t& arg1, const arg2_t& arg2, const arg3_t& arg3)
    {
        return arg3;
    }
};*/

int main()
{
    placeholder<0> pl;
    std::cout << pl(5);
    return 0;
}
