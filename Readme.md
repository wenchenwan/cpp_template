# 自己学习cpp template的一些实践

- 函数模板产生出来的函数一定不等于普通函数（即使参数数量类型和返回值完全相同）,故模板函数产生的函数永远不会替换一个虚函数，即模板函数永远不能为虚函数。同时从模板函数中产生的构造函数永远不会是缺省值构造函数。

- 模板类中的与模板参数无关的友元函数声明在进行不同类型的模板实例化时没有问题，但是当其在模板类进行定义时，进行不同类型的模板类实例化会发生友元函数的重定义问题。如果友元函数与类模板的模板函数相关，就可以在不同的模板参数条件下完成不同的友元函数的实现。（友元与模板结合会发生比较多的问题，需要注意）。

- 区分受限名称和依赖型名称
 ```cpp
// 受限名称
A.x;
A->x;
// 依赖型名称
A<int>::X;
 ```

-

