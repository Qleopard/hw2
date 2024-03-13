#include <iostream>
#include <vector>
#include <list>

using namespace std;

template<typename Cont> void print(Cont cont, std::string s) {
    int counter = 0;
    int len = cont.size()-1;
    for (auto it = cont.begin(); it != cont.end(); ++it, ++counter) {
        if (len == counter) {
            std::cout << *it << "\n";
            break;
        }
        else {
            std::cout << *it << s;
        }
    }  
}

int main() {
    std::list<int> cont = {1, 2, 3, 4, 5};
    std::string s = ", ";
    print(cont, s);
    return 0;
}