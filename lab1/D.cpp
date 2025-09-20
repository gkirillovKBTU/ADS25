#include <iostream>
#include <vector>
using namespace std;

int main() {
    char ch;
    std::string result_string;
    while (std::cin.get(ch) && ch != ' ' && ch != '\n') {
        if (!result_string.empty() && result_string.back() == ch) {
            result_string.pop_back();
        }else{
            result_string.push_back(ch);
        }
    }
    std::cout << (result_string.empty() ? "YES" : "NO") << std::endl;
    return 0;
}