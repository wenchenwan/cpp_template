#include <iostream>
#include <template_arg.hpp>
#include <typeinfo>
#include <vector>

#include <template_class_template_member.hpp>
#include<template_policy.hpp>

#define PRINT_FUN(test) \
    { std::cout << test << std::endl; }

// 示例类，不包含foo成员函数
struct test01 {
    typedef int X;
};

int b = 10;
struct test02 {
    char y;
};
int main(int argc, char **argv) {
#ifdef USING_TEMPLATE_ATG
    PRINT_FUN("hello world!");
    PRINT_FUN(testTemplate::max<int>(10, 20));
    PRINT_FUN(testTemplate::max(10, 20));
    PRINT_FUN(testTemplate::max(10.0, 20.0));
    // PRINT_FUN(testTemplate::implcit_cast<double>(100));
    std::cout << testTemplate::implcit_cast<double, bool>(100) << std::endl;
    //   test01 test1;
    //   test02 test2;
    const int *a;
    PRINT_FUN(sizeof(test01::X))
    PRINT_FUN(sizeof(testTemplate::test<test01>(a)));
    PRINT_FUN(sizeof(testTemplate::test<test02>(a)));

    PRINT_FUN(testTemplate::g<1>());

    testTemplate::A<int> t;
    PRINT_FUN(t.size());
    t.push(10);
    t.push(10);
    PRINT_FUN(t.size());

    testTemplate::C<int, 10> *C1;
    // int b = 10;
    testTemplate::C<int *, &b> *C2;

    testTemplate::C<void (*)(int), testTemplate::f> *C3; // 匹配f(int)
    testTemplate::C<void (*)(), testTemplate::f> *C4;    // 匹配f()

    testTemplate::C<int &, testTemplate::X::c> *C5;
    testTemplate::C<int testTemplate::X::*, &testTemplate::X::a> *C6;

    testTemplate::C<void (*)(), &testTemplate::templ_func<double>> *C7;
#endif
    testTemplate::testMemberTemplate<float> testmember(10.0);
    testmember.test<double>();

    float a = 0.10000000000000000000;
    float b = 0.20000000000000000000;

    std::cout << a + b << std::endl;


    testPolicy::Demo<int,testPolicy::demo01> d1;
    testPolicy::Demo<int,testPolicy::demo02> d2;
    testPolicy::Demo<int,testPolicy::demo03> d3;
    
    d1.callfunc01();
    // d1.callfunc02();

    d2.callfunc01();
    d2.callfunc02();

    d3.callfunc01();
    d3.callfunc02();
    d3.callfunc03();
    return 0;
}
