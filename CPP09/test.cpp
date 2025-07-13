#include <iostream>
#include <fstream>
#include <sstream>
#include <list>

int main(){
    std::list<std::string> s;
    s.push_back("a");
    s.push_back("b");
    s.push_back("c");
    s.push_back("d");
    s.push_back("e");
    std::cout << s.front() << '\n';
    for (std::list<std::string>::iterator it = s.begin(); it != s.end(); it++){
        std::cout << (*it)[0] << '\n';
    }
}