/* ==================================================================
* Copyright (c) 2023, wenchenwan.
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions
* are met:
*
* 1. Redistributions of source code must retain the above copyright
* notice, this list of conditions and the following disclaimer.
* 2. Redistributions in binary form must reproduce the above copyright
* notice, this list of conditions and the following disclaimer in the
* documentation and/or other materials provided with the
* distribution.
* 3. All advertising materials mentioning features or use of this software
* must display the following acknowledgement:
* This product includes software developed by the xxx Group. and
* its contributors.
* 4. Neither the name of the Group nor the names of its contributors may
* be used to endorse or promote products derived from this software
* without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY xxx,GROUP AND CONTRIBUTORS
* ===================================================================
*
*
* Author:  Wen Chenwan (wenchenwan@outlook.com).
* @version 0.1
* @date 2024-08-07
* @file template_policy.hpp
* @brief 
*/
#include<iostream>
namespace testPolicy
{

template<typename T, typename... Policies>
class testTemplate : public Policies...
{
public:
    testTemplate() = default;
};

template<typename T,typename Enable = void>
struct test01
{
    static int print01()
    {
        std::cout << "test01 print01 ." << std::endl;
        return 0;
    }
};

template<typename T,typename Enable = void>
struct test02
{
    static int print02()
    {
        std::cout << "test02 print02 ." << std::endl;
        return 0;
    }
};

template<typename T,typename Enable = void>
struct test03
{
    static int print03()
    {
        std::cout << "test03 print03 ." << std::endl;
        return 0;
    }
};
template<typename T>
using demo01 = testTemplate<T,test01<T>>;

template<typename T>
using demo02 = testTemplate<T,test01<T>,test02<T>>;

template<typename T>
using demo03 = testTemplate<T,test01<T>,test02<T>,test03<T>>;

template<typename T,template<typename > class policy>
class Demo
{
public:
    int callfunc01()
    {
        policy<T>::print01();
        return 0;
    };

    int callfunc02()
    {
        policy<T>::print02();
        return 0;
    }

    int callfunc03()
    {
        policy<T>::print03();
        return 0;
    }
};
} // namespace name