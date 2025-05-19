#include <iostream>
#include <string>

enum level {
    LOW,
    MEDIUM,
    HIGH,
};

int main(){
    enum level l = HIGH;
    try {
        if (l == HIGH)
            throw (static_cast<const std::string&>("High level"));
    }
    catch(const std::string& s){
        std::cerr << "It's high level !" << '\n';
    }
    return (0);
}