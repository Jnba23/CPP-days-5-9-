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

#include <algorithm>
#include <vector>
#include <iostream>
#include <thread>

class User{
    private:
    public:
        bool completed;
        std::thread t;
        User():completed(false){};
        void setTaskAsComp(){
            completed = true;
        }
        void routine(){
            for (int i = 0; i < 10; i++){
            }
            setTaskAsComp();
        }
};


int main(){
    std::vector<User> users(5);
    std::vector<bool> a(5, false);
    for (int i = 0; i < 5; i++){
        users.at(i).completed = a.at(i);
    }
    for (int i = 0; i < 5; i++){
        users.at(i).t = std::thread(users.at(i).routine);
    }
}