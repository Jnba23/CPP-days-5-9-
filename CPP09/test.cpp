#include <iostream>
#include <fstream>
#include <sstream>

int main(){
    std::string a = "   10   ";
    std::istringstream i(a);
    int b;
    i >> b;
    // if (!i.eof())
    //     std::cout << "Failed !" << '\n';
        // std::cout << "failed to read a number !" << '\n';
    std::cout << b << '\n';
    // while (std::getline(i, a, '-')){
    //     std::cout << a << '\n';
    // }
}