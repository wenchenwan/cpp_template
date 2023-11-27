
#include<iostream>
#include<template_is_prime.hpp>

int main(int argc, char** argv){
    constexpr unsigned test_number = 17;
    std::cout << "template test !" << std::endl;
    if (template_is_prime<test_number>::value) {
        std::cout << test_number << " is a prime number.\n";
    } else {
        std::cout << test_number << " is not a prime number.\n";
    }
    return 0;
}
