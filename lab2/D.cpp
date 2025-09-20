#include <iostream>
#include <string>
#include <map>
#include <climits>
#include <cmath>
using namespace std;

int main() {
    int n, el; cin >> n;
    map<int, int> counter;
    int cur_max = 0;
    for(int i=0; i < n; i++){
        cin >> el;
        counter[el]++;
        cur_max = max(counter[el], cur_max);
    }
    map<int, int>::iterator it = counter.end();
    do{
        it--;
        if(it->second == cur_max){
            cout << it->first << " ";  
        }
    }while(it != counter.begin());
    cout << endl;
    return 0;
}