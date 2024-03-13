
#include <iostream>

using namespace std;

int main() {
    std::string text = "Ya dostayu iz shirokih shtanin duplikatom bestsennogo gruza. Chitaite, zaviduite, ya - grazhdanin Sovetskogo Soyuza.";
    std::string signs = ",.!:;!(){}[]<>";
    std::string word;
    std::string specword = "";
    int index;
    while (text.find(" ") != -1) {
        index = text.find(" ");
        word = text.substr(0, index);
        for (int i = 0; i != signs.length(); i++) {
            if (signs[i] == word[0]) {
                word.erase(0, 1);
            }
            if (signs[i] == word[word.length()-1]) {
                word.erase(word.length()-1, 1);
            }       
        }
        text = text.substr(index+1);
        char small = tolower(word[0]);
        if ((word.length() > specword.length()) || ((word.length() == specword.length()) && (small < tolower(specword[0])))) {
            specword = word;
        }
    }
    for (int i = 0; i!=signs.length(); i++) {
            if (signs[i] == text[0]) {
                text.erase(0, 1);
            }
            if (signs[i] == text[text.length()-1]) {
                text.erase(text.length()-1, 1);
            }       
        }
    char small = tolower(text[0]);
    if ((text.length() > specword.length()) || ((text.length() == specword.length()) && (small < tolower(specword[0])))) {
        specword = text;
    }
    std::cout << specword;
    return 0;
}

// Случайно сделанная задача о нахождении самого длинного слова
