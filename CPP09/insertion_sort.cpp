#include <iostream>
#include <vector>

void insertionSort(std::vector<int>& v){
    int tmp;
    for (std::vector<int>::iterator i = v.begin() + 1; i != v.end(); i++){
        tmp = *i;
        if (*i > *(i - 1)){
        std::vector<int>::iterator j = i;
        for (; j != v.begin(); j--){
            if (*(j - 1) < tmp)
                *j = *(j - 1);
            else
                break;
        }
        *j = tmp;
    }}
}

int main(){
    std::vector<int> v;
    v.push_back(5);
    v.push_back(89);
    v.push_back(-578);
    v.push_back(0);
    v.push_back(789);
    v.push_back(1);
    insertionSort(v);
    for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++){
        std::cout << *it << '\n';
    }
}