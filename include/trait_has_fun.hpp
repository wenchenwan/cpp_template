#include <vector>
#include <iostream>

// 定义一个trait，用于检查类是否包含指定的成员函数
template<typename T>
class has_member_function_foo {
private:
    // 检查函数的helper，用于判断是否存在成员函数foo
    template<typename U>
    static char check(decltype(&U::foo));

    template<typename U>
    static int check(...);

public:
    // 通过检查函数的返回类型来确定是否存在成员函数foo
    static constexpr bool value = sizeof(check<T>(nullptr)) == sizeof(char);
};

// 示例类，包含foo成员函数
struct MyClass1 {
    void foo() {
        std::cout << "MyClass1::foo() called." << std::endl;
    }
};

// 示例类，不包含foo成员函数
struct MyClass2 {
    void bar() {
        std::cout << "MyClass2::bar() called." << std::endl;
    }
};

// std::cout << "MyClass1 has foo(): " << has_member_function_foo<MyClass1>::value << std::endl; // true
// std::cout << "MyClass2 has foo(): " << has_member_function_foo<MyClass2>::value << std::endl; // false