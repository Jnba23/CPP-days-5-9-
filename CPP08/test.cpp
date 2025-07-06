//STL : standard template library
//organized into four main components :
    // -Containers : 
        // - sequence containers : vectors, list, deque
        // - associative containers : set, map, multiset, multimap
        // - Container adapters : stack, queue, priority_queue
    // -Algorithms : (Applied within containers)
        // - sort, find, copy, for_each
    // -Iterators :
    // -Functors(function objects) :used with algorithms to customize their behavior
    // Array : contiguous memory storage => fast access

#include <algorithm>
#include <vector>
#include <cassert>
#include <iostream>
#include <csignal>

// int devide(int i, int b){
//     assert(b != 0 && "division by 0");
//     return (i / b);
// }

// void printEl3(const std::vector<int>& a){
//     assert(a.size() >= 3 && "vector too small !");
//     std::cout << a[3] << '\n';
// }
int main(){
    // int arr[10] = {1, 5, 7, 12, 21, 8, 6};
    // std::vector<int> a(arr, arr + 10);
    // for (const auto& i : a){
    //     std::cout << i << '\n';
    // }
    int arr[] = {'e', 'b', 't', 'd'};
    std::vector<int>c(arr, arr + 4);
    for (int i = 0; i < 4; i++){
        std::cout << c[i] << '\n';
    }
    std::vector<int>::iterator b = c.begin();
    std::vector<int>::iterator e = c.end();
    std::sort(b, e);
    for (b; b != c.end(); b++){
        std::cout << *b << '\n';
    }
}