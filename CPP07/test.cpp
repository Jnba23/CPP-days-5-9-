#include <iostream>

template <typename T>
T max(T a, T b){
    if (a > b)
        return a;
    return b;
}
void f(int* i){
    (*i)++;
    std::cout << *i << '\n';
}

int main(){
    const int* a = new int(5);
    f(a);
}
