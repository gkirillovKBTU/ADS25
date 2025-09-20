#include <iostream>
#include <string>
#include <unordered_map>
#include <stack>
using namespace std;

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

void clean_stack(stack<char>& stack_to_clean){
    while(!stack_to_clean.empty()){
        stack_to_clean.pop();
    }
}

int main() {
    int n; cin >> n;
    char ch; cin.get(ch);
    int S_score = 0, K_score = 0, i = n;
    unordered_map<char,stack<char>> counter;
    unordered_map<char,char> opposites;
    opposites['S'] = 'K';
    opposites['K'] = 'S';
    while(std::cin.get(ch) && ch != '\n'){
        // cout << ch << endl;
        if(counter[opposites[ch]].empty()){
            if(ch == 'S'){
                S_score += 1;
            }else{
                K_score += 1;
            }
            counter[ch].push(ch);
        }else{
            counter[opposites[ch]].pop();
        }
        // if(i-- == 0){
        //     // std::cout << "Stacks are cleaned" << endl;
        //     clean_stack(counter['S']);
        //     clean_stack(counter['K']);
        //     i = n;
        // }
    }
    
    // std::cout << K_score << " " << S_score << endl;
    std::cout << ((K_score > S_score) ? "KATSURAGI" : "SAKAYANAGI") << std::endl;
    return 0;
}