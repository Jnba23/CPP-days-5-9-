#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include <vector>
#include <algorithm>

//merge sort
void merge(std::vector<int>& lv, std::vector<int>& rv, std::vector<int>& orig){
    size_t lv_s = lv.size();
    size_t rv_s = rv.size();
    size_t i = 0;
    size_t j = 0;
    size_t o = 0;
    while (i < lv_s && j < rv_s){
        if (lv[i] < rv[j]){
            orig[o] = lv[i];
            i++;
            o++;
        } else {
            orig[o] = rv[j];
            j++;
            o++;
        }
    }
    while (i < lv_s){
        orig[o] = lv[i];
        o++;
        i++;
    }
    while (j < rv_s){
         orig[o] = rv[j];
         o++;
         j++;
    }
}

void mergeSort(std::vector<int>& v){
    //divide v to lv and rv
    if (v.size() <= 1)
        return ;
    std::vector<int>lv;
    std::vector<int>rv;
    lv.insert(lv.end(), v.begin(), v.begin() + v.size() / 2);
    rv.insert(rv.end(), v.begin() + v.size() / 2, v.end());
    mergeSort(lv); //divide the whole left vector up until one element
    mergeSort(rv); //divide the whole right vector up until one element
    merge(lv, rv , v); //start merging
}

int main(){
    std::vector<int> v;
    v.push_back(2);
    v.push_back(3);
    v.push_back(25);
    v.push_back(17);
    v.push_back(30);
    mergeSort(v);
    for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++){
        std::cout << *it << '\n';
    }
}