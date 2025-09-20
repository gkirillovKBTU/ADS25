#include <iostream>
#include <vector>
#include <deque>
#include <stack>
using namespace std;

int main() {
    int t; cin >> t;
    stack<int> helper;
    vector<int> array;
    int el, prev_el;
    for(int i = 0; i < t; i++){
        cin >> el;
        prev_el = -1;
        while(!helper.empty() && helper.top() > el){
            helper.pop();
        };
        if(!helper.empty()){
            prev_el = helper.top();
        }
        array.push_back(prev_el);
        std::cout << prev_el << " ";
        helper.push(el);
    }
    return 0;
}