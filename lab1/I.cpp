#include <iostream>
#include <string>
#include <map>
#include <stack>
using namespace std;

int main() {
    int n; cin >> n;
    char ch;
    int S_score = 0, K_score = 0;
    map<char,stack<char>> counter;
    map<char,char> opposites;
    opposites['S'] = 'K';
    opposites['K'] = 'S';
    while(n--){
        cin >> ch;
        if(counter[opposites[ch]].empty()){
            if(ch == 'S'){
                S_score += 1;
            }else{
                K_score += 1;
            }
        }else{
            counter[opposites[ch]].pop();
        }
        counter[ch].push(ch);
    }

    std::cout << ((K_score > S_score) ? "KATSURAGI" : "SAKAYANAGI") << std::endl;
    return 0;
}