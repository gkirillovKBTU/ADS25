#include <iostream>
#include <deque>
#include <stack>
#include <climits>
#include <string>
using namespace std;

int main() {
    int n, t; cin >> n;
    char ch;
    bool dupl;
    for(int i=0; i < n; i++){
        deque<char> lookup;
        cin >> t;
        for(int j=0; j < t; j++){
            cin >> ch;
            dupl = false;
            while(!lookup.empty() && lookup.back() == ch){
                // cout << " LOGG " << lookup.back() << " " << ch << endl;
                dupl = true;
                lookup.pop_back();
            }
            if(!dupl){
                lookup.push_front(ch);
            }    
            cout << (lookup.empty() ? "-1" : string(1, lookup.back())) << " ";
        }
        cout << endl;
    }
    return 0;
}