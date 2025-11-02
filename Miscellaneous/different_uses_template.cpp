#include<iostream>
using namespace std;
//T == any valid data type, 
//T != 
/*1. function template*/
template<typename T>
void swap(T a, T b){
    T temp = a;
    a = b;
    b = temp;
}
/*2. Class Template*/
template<typename T>
class List{
        T val;
        T* next;
    public:
        List(): val(0), next(nullptr){}
        List(T data): val(data), next(nullptr){}
};

/*3. variable templates*/
template <typename T>
constexpr T pi = T(3.1415926535897932385);
//pi ki value ka precision according to data type aayega
/*
std::cout << pi<float>;  // 3.14159
std::cout << pi<double>; // higher precision
*/

/*4. Alias Templates*/
template<typename T>
using Vec = std::vector<T>;
// Vec<pair<int, char>> would work the same as std::vector<pair<int, char>>
// Use case: Simplifying complex types, improving readability

/*5. Variadic Templates*/
template <typename... Args>
void print(Args... args) {
    (std::cout << ... << args) << '\n';  // Fold expression (C++17)
}

// Usage:
// print(1, "hello", 3.14, true);


