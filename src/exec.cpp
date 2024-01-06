
#include<iostream>
#include<template_is_prime.hpp>
#include<SFINAE.hpp>
#include<if_constexp.hpp>
#include<vector>
#include<SignalSlot.hpp>

template<typename T, T Z = T{}>
class RefMem {
private:
    T zero;
    public:
    RefMem() : zero{Z}
    {
    }
};
int null = 0;
int main(int argc, char** argv){
#if USE_constexpr
    constexpr unsigned test_number = 17;
    std::cout << "template test !" << std::endl;
    if (template_is_prime<test_number>::value) {
        std::cout << test_number << " is a prime number.\n";
    } else {
        std::cout << test_number << " is not a prime number.\n";
    }
#endif
#if SFINAE
    int arr[10];
    std::cout << len(arr) << std::endl;
    std::cout << len("arr") << std::endl;
    const std::vector<int> v;
    std::cout << len(v) << std::endl;

    int* p;
    std::cout << len(p) << std::endl;
    class a {
    public:
        int size(){return 10;};
    };
    a c;
    std::cout << c.size() << "" << len(c) << std::endl;
    // ! 为什么这个直接匹配了省略号？？？

    std::allocator<int> x;
    std::cout << len(x) << std::endl;

#endif

    // print("21321");
    // print("rwerew","asfsd");
    // 创建信号
    Signal<int> mySignal;

    // 绑定槽函数
    mySignal.connect(mySlot);

    // 触发信号
    mySignal.emit(42);





    RefMem<int> rm1, rm2;
    rm1 = rm2; // OK
    // RefMem<int&> rm3; // ERROR: invalid default value for N
    // RefMem<int&, 0> rm4; // ERROR: invalid default value for N extern int null;
    RefMem<int&,null> rm5, rm6;
    // rm5 = rm6; // ERROR: operator= is deleted due to reference member

    return 0;
}
