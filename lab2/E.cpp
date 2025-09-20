#include <iostream>
#include <vector>
#include <deque>
#include <stack>
#include <cmath>
#include <climits>
#include <string>
using namespace std;

int main() {
    int n, t; cin >> n;
    string name;
    t = 0;
    stack<string> seq_records;
    for(int i=0; i < n; i++){
        cin >> name;
        if(seq_records.empty() || !(seq_records.top() == name)){
            seq_records.push(name);
            t++;
        }
    }

    std::cout << "All in all: " << t << endl;
    cout << "Students:" << endl;
    while(!seq_records.empty()){
        cout << seq_records.top() << endl;
        seq_records.pop();
    } 
    return 0;
}