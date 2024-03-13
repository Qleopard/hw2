#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    std::string text = "Ya dostayu iz shirokih shtanin duplikatom bestsennogo gruza. Chitaite, zaviduite, ya - grazhdanin Sovetskogo Soyuza.";
    std::string signs = ",.!:;!(){}[]<>";
    std::string word;
    std::vector<std::string> words;
    std::vector<int> numbers;
    std::string specword;
    int number = 0;
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
        word[0] = tolower(word[0]);
        bool found = std::find (words.begin(), words.end(), word) != words.end();
        if (found == false) {
            words.push_back(word);
            numbers.push_back(1);
        }
        else {
            int counter = 0;
            for (auto it = words.begin(); it != words.end(); ++it, ++counter) {
                if (word == words[counter]) {
                    ++numbers[counter];
                }
            }  
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
    text[0] = tolower(text[0]);
    bool found = std::find (words.begin(), words.end(), text) != words.end();
    if (found == false) {
            words.push_back(text);
            numbers.push_back(1);
        }
        else {
            int counter = 0;
            for (auto it = words.begin(); it != words.end(); ++it, ++counter) {
                if (text == words[counter]) {
                    ++numbers[counter];
                }
            }  
        }
    int counter = 0;
    for (auto it = words.begin(); it != words.end(); ++it, ++counter) {
        if ((numbers[counter] > number) || ((numbers[counter] == number) && (word[0] < specword[0]))) {
            specword = words[counter];
            number = numbers[counter];
        }
    }
    std::cout << specword;
    return 0;
}