#include <iostream>
#include <limits>
#include <cstdlib>
#include <iomanip>
#include <stdint.h>

enum level {
    LOW,
    MEDIUM,
    HIGH,
};

int main(){
    std::string i = "--12561.10";
    char* end;
    // std::cout << std::setprecision(2) << std::fixed <<  std::strtod(i.c_str(), &end) << '\n';
    // std::cout << std::numeric_limits<float>::max() << '\n';
    // std::cout << -std::numeric_limits<float>::max()<< '\n';
    // std::cout << std::numeric_limits<double>::max()<< '\n';
    // std::cout << -std::numeric_limits<double>::max()<< '\n';
    std::cout << std::fixed << std::setprecision(1) << strtof("0.f", NULL) << '\n';
    std::cout << std::fixed << std::setprecision(1) << static_cast<float>(strtoll("112312313456", NULL, 10)) << '\n';
    std::cout << ".5" << '\n';
    // std::cout << sizeof(uintptr_t) << '\n';
    // std::cout << sizeof(int*) << '\n';
    // int* s = new int(6);
    // uintptr_t addr = reinterpret_cast<uintptr_t>(s);
    // int *ptrback = reinterpret_cast<int *>(addr); 
    // std::cout << s << ' ' << *s << " addr is : " << addr << " addrback is : " << *ptrback << '\n';
}