#include <iostream>   // For std::cout
#include <typeinfo>   // For typeid
#include <string>     // For std::string
#include <vector>     // For std::vector
#include <deque>      // For std::deque

// A templated function to detect the type of the passed parameter
template <typename T>
void processCont(T& container, int a){
    container.push_back(a);
}


int main(){
    std::vector<int> a;

    processCont(a, 40);
    processCont(a, 570);
    processCont(a, 0);
    for(std::vector<int>::iterator it = a.begin(); it != a.end(); it++){
        std::cout << *it << std::endl;
    }
}