#include <iostream>
#include <deque>
#include <stack>
#include <unordered_set>
#include <climits>
#include <string>
using namespace std;

int main() {
    int n, t; cin >> n;
    char ch;
    bool dupl;
    unordered_set<char> duplicates;
    deque<char> lookup;
    for(int i=0; i < n; i++){
        cin >> t;
        for(int j=0; j < t; j++){
            cin >> ch;
            dupl = false;
            while(!lookup.empty() && lookup.back() == ch){
                // cout << " LOGG " << lookup.back() << " " << ch << endl;
                lookup.pop_back();
            }
            if(duplicates.find(ch) == duplicates.end()){
                lookup.push_front(ch);
                duplicates.insert(ch);
            }
            cout << (lookup.empty() ? "-1" : string(1, lookup.back())) << " ";
        }
        cout << endl;
        duplicates.clear();
        lookup.clear();
    }
    return 0;
}