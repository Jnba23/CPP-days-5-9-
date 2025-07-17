#include <iostream>
#include <vector>

void insertionSort(std::vector<int>& v){
    int tmp1;
    for(std::vector<int>::iterator i = v.begin() + 1; i != v.end(); i++){
        std::cout << "main vec : " << *i << '\n';
        tmp1 = *i;
        std::vector<int>::iterator j = i;
        for(; j != v.begin(); j--){
            if (*(j - 1) < tmp1){
                *j = *(j - 1);
            }
            else
                break;
            }
        *j = tmp1;
    }
}

int main(){
    std::vector<int> v;
    v.push_back(5);
    v.push_back(78);
    v.push_back(6);
    v.push_back(12);
    v.push_back(7);
    v.push_back(1);
    v.push_back(-62);
    v.push_back(0);
    insertionSort(v);
    for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++){
        std::cout << *it << '\n';
    }
}