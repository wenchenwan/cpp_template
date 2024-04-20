/**
 * template argument test
 **/

#include <queue>
namespace testTemplate {
template <typename T>
inline T const &max(T const &a, T const &b) {
    return a < b ? b : a;
}

/**
 * template specialization
 **/
template <>
double const &max<double>(double const &a, double const &b) {
    std::cout << "max double" << std::endl;
    return a < b ? b : a;
}

/**
 * exchange template argument
 **/
// template <typename DesT, typename SrcT>
// inline DesT implcit_cast(SrcT const& x)
// {
//     return x;
// }

template <typename SrcT, typename DesT>
inline DesT implcit_cast(SrcT const &x) {
    return x;
}
template <typename func, typename T>
void apply(func funcPtr, T x) {
    funcPtr(x);
}
template <typename T>
void single(T x){};

template <typename T>
void muti(T x){};

template <typename T>
void muti(T *x){};

// testTemplate::apply(&testTemplate::single<int>,10);
// testTemplate::apply(&testTemplate::muti<int>,10); // 定义不唯一
typedef char RT1;

typedef struct {
    char a[100];
} RT2;

template <typename T>
RT1 test(typename T::X const *);

template <typename T>
RT2 test(...);

#define type_has_type_x(T) (sizeof(testTemplate::test<T>(0)) == 1)

template <int N>
int g() {
    return N;
};
template <int *P>
int g() {
    return (*P);
};

template <typename T, template <typename U, typename Alloc = std::allocator<U>>
                      class C = std::deque>
class A {
   private:
    C<T> b;

   public:
    void push(T x) { b.push_front(x); };
    bool size() { return b.size(); };
};

template <typename T, T nontype_param>
class C;

void f();
void f(int);

class X {
   public:
    int a;
    static int c;
};

template <typename T>
void templ_func();

// testTemplate::C<int, 10> *C1;
// // int b = 10;
// testTemplate::C<int *, &b> *C2;

// testTemplate::C<void (*)(int), testTemplate::f> *C3; // 匹配f(int)
// testTemplate::C<void (*)(), testTemplate::f> *C4;    // 匹配f()

// testTemplate::C<int &, testTemplate::X::c> *C5;
// testTemplate::C<int testTemplate::X::*, &testTemplate::X::a> *C6;
// testTemplate::C<void (*)(), &testTemplate::templ_func<double>> *C7;

} // namespace testTemplate
