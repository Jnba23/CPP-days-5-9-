#include <iostream>
#include <vector>

void merge(std::vector<int>& lv, std::vector<int>& rv, std::vector<int>& v){
    size_t l = 0, r = 0, o = 0;
    while (l < lv.size() && r < rv.size()){
        if (lv[l] > rv[r]){
            v[o] = rv[r];
            o++;
            r++;
        } else {
            v[o] = lv[l];
            o++;
            l++;
        }
    }
    while (l < lv.size()){
        v[o] = lv[l];
        o++;
        l++;
    }
    while (r < rv.size()){
        v[o] = rv[r];
        o++;
        r++;
    }
}

void mergeSort(std::vector<int>& v){
    if (v.size() <= 1)
        return ;
    std::vector<int> lv;
    std::vector<int> rv;
    lv.insert(lv.end(), v.begin(), v.begin() + v.size() / 2);
    rv.insert(rv.begin(), v.begin() + v.size() / 2, v.end());
    mergeSort(lv);
    mergeSort(rv);
    merge(lv, rv, v);
}

int main(){
    std::vector<int> v;
    v.push_back(9);
    v.push_back(10);
    v.push_back(78);
    v.push_back(-4);
    v.push_back(88);
    v.push_back(-300);
    mergeSort(v);
    for(std::vector<int>::iterator it = v.begin(); it != v.end(); it++){
        std::cout << *it << '\n';
    }
}

