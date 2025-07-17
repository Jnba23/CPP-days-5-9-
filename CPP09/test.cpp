#include <iostream>   // For std::cout
#include <typeinfo>   // For typeid
#include <string>     // For std::string
#include <vector>     // For std::vector
#include <deque>      // For std::deque
#include <type_traits> // For std::is_same, std::decay_t

// A templated function to detect the type of the passed parameter
template <typename T>
void detectType(T param) {
    std::cout << "--- Inside detectType function ---" << std::endl;

    // 1. Using typeid for runtime type information:
    //    typeid(T).name() gives the name of the deduced template type 'T'.
    //    This 'T' might include const/reference qualifiers depending on how it's deduced.
    std::cout << "Deduced template type (T): " << typeid(T).name() << std::endl;

    //    typeid(param).name() gives the name of the actual type of the parameter 'param'.
    //    Note: For fundamental types (like int, double), 'param' is usually passed by value,
    //    so reference/const qualifiers might be dropped.
    std::cout << "Actual parameter type (decltype(param)): " << typeid(decltype(param)).name() << std::endl;

    // 2. Using type_traits for compile-time type checks:
    //    std::is_same<Type1, Type2>::value checks if two types are exactly the same.
    std::cout << "Is T an int? " << std::boolalpha << std::is_same<T, int>::value << std::endl;
    std::cout << "Is T a double? " << std::boolalpha << std::is_same<T, double>::value << std::endl;
    std::cout << "Is T a std::string? " << std::boolalpha << std::is_same<T, std::string>::value << std::endl;
    std::cout << "Is T an int&? " << std::boolalpha << std::is_same<T, int&>::value << std::endl;
    std::cout << "Is T a const int&? " << std::boolalpha << std::is_same<T, const int&>::value << std::endl;

    // New checks for std::vector and std::deque
    std::cout << "Is T a std::vector<int>? " << std::boolalpha << std::is_same<T, std::vector<int> >::value << std::endl;
    std::cout << "Is T a std::deque<int>? " << std::boolalpha << std::is_same<T, std::deque<int> >::value << std::endl;

    std::cout << "--------------------------------" << std::endl << std::endl;
}

int main() {
    // // Test with different types
    // int myInt = 10;
    // detectType(myInt); // T will be deduced as 'int'

    // double myDouble = 3.14;
    // detectType(myDouble); // T will be deduced as 'double'

    // std::string myString = "Hello, C++!";
    // detectType(myString); // T will be deduced as 'std::string'

    // const int constInt = 20;
    // detectType(constInt); // T will be deduced as 'int' (by value, const is dropped)

    // // To preserve const/reference in deduction, pass by reference:
    // detectType<const int&>(constInt); // Explicitly deduce T as 'const int&'

    // int& refInt = myInt;
    // detectType(refInt); // T will be deduced as 'int' (by value, reference is dropped)

    // detectType<int&>(refInt); // Explicitly deduce T as 'int&'

    // int* ptrInt = &myInt;
    // detectType(ptrInt); // T will be deduced as 'int*'

    // Test with std::vector and std::deque
    std::vector<int> myVector;
    myVector.push_back(1);
    myVector.push_back(2);
    myVector.push_back(3);
    detectType(myVector); // T will be deduced as 'std::vector<int>'

    std::deque<int> myDeque;
    myDeque.push_back(4);
    myDeque.push_back(5);
    myDeque.push_back(6);
    detectType(myDeque); // T will be deduced as 'std::deque<int>'

    // const std::vector<double>& constRefVector = {7.0, 8.0};
    // detectType(constRefVector); // T will be deduced as 'const std::vector<double>&'

    return 0;
}
