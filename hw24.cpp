#include <iostream>
#include <stack>

using namespace std;

bool leftism (char br) {
    return ('(' == br || '{' == br || '[' == br);
}

bool fitted (char lbr, char rbr) {
    return ('(' == lbr && ')' == rbr) || ('[' == lbr && ']' == rbr) || ('{' == lbr && '}' == rbr);
}

int main() {
    std::string brackets = "()[()]{()()[]}";
    std::stack<char> opened;
    for(char bracket : brackets) {
        if(leftism(bracket)) {
            opened.push(bracket);
        }
        else if (opened.size() > 0) {
            if (fitted(opened.top(), bracket)) {
                opened.pop();
            }
        }
        else {
            opened.push(bracket);
            break;
        }
    }
    if (opened.size() == 0) {
        std::cout << "Good sequence <3";
    }
    else {
        std::cout << "Bad sequence :(";
    }
    return 0;
}