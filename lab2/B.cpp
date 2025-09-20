#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main() {
    int n, k; cin >> n >> k;
    deque<string> array;
    string word;
    for(int i=0; i < n; i++){
        cin >> word;
        array.push_back(word);
    }
    for(int i=0; i < k; i++){
        word = array.front();
        array.pop_front();
        array.push_back(word);
    }
    for(int i=0; i < n; i++){
        cout << array[i] << " ";
    }
    return 0;
}