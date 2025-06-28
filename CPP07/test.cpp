#include <iostream>

template <typename a>
struct s{
    a o1;
    a o2;
};

template <typename b>
b max(b o1, b o2){
    if (o1 > o2)
        return o1;
    return (o2);
}

int main(){
    s<int > p;
    p.o1 = 6;
    p.o2 = 8;
    std::cout << max(p.o1, p.o2) << '\n';
}