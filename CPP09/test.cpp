#include <iostream>   // For std::cout
#include <typeinfo>   // For typeid
#include <string>     // For std::string
#include <vector>     // For std::vector
#include <deque>      // For std::deque
#include <sstream>      // For std::deque
// #include <unordered_set>      // For std::unordered set
#include <sstream>      // For std::deque

// A templated function to detect the type of the passed parameter
// void insertion(std::vector<int>& pend){
// 	std::vector<int> J;
// 	J.push_back(0);
// 	J.push_back(1);
// 	size_t s = pend.size();
//     std::cout << s << '\n';
// 	for (size_t i = 2; J[i - 1] <= s; i++){
// 		J.push_back(J[i - 1] + 2 * J[i - 2]);
// 	}
//     std::cout << "Jacobsthale sequence :" << '\n';
// 	for(size_t i = 0; i < J.size(); i++){
//         std::cout << J[i] << '\n';
//     }
// }

int main(){
    // std::istringstream in("1 sdfsd");
    // int i;
    // while (in >> i){
    //     if (!in)
    //         std::cout << "Failed !" << '\n';
    //     std::cout << i << '\n';
    // }
    // std::vector<int> v;
    // v.push_back(10);
    // v.push_back(3);
    // v.push_back(44);
    // v.push_back(15);
    // v.push_back(31);
    // v.push_back(90);
    // insertion(v);
    std::istringstream i;
    long a;
    i.str("-");
    i >> a;
    if (!i)
        std::cout << "failed " << '\n';
}
    