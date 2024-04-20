#include <iostream>
#include <template_arg.hpp>
#include <typeinfo>
#include <vector>

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
    return 0;
}
