#include <iostream>
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
    std::list<int> nums = {1, -2, -3, 4, -5, 3, 0, 8};
    std::list<int> plus = {};
    std::list<int> minus = {};
    std::list<int> nulls = {};
    for(int num : nums) {
        if (num > 0) {
            int j = 0;
            if (plus.size() == 0) {
                plus.push_front(num);
                continue;
            }
            for (auto it = plus.begin(); it != plus.end(); ++it) {
                j = j + 1;
                if (num <= (*it)) {
                    plus.insert(it, num);
                    break;
                }
            }
            if (j == plus.size()) {
                plus.push_back(num);
            }
        }
        else if (num < 0) {
            int j = 0;
            if (minus.size() == 0) {
                minus.push_front(num);
                continue;
            }
            for (auto it = minus.begin(); it != minus.end(); ++it) {
                j = j + 1;
                if (num <= (*it)) {
                    minus.insert(it, num);
                    break;
                }
            }
            if (j == minus.size()) {
                minus.push_back(num);
            }
        }
        else if (num == 0) {
            nulls.push_front(0);
        }
    }
    print(plus, ", ");
    print(minus, ", ");
    print(nulls, ", ");
    return 0;
}