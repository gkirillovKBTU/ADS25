#include <iostream>
#include <string>

std::string get_formatted_input(){
    char ch;
    std::string result_string;
    while (std::cin.get(ch) && ch != ' ' && ch != '\n') {
        if (ch == '#' && !result_string.empty()) {
            result_string.pop_back();
        }else{
            result_string.push_back(ch);
        }
    }
    return result_string;
}

int main() {;
    bool are_equal = get_formatted_input() == get_formatted_input();
    std::cout << (are_equal ? "Yes" : "No") << std::endl;
    return 0;
}