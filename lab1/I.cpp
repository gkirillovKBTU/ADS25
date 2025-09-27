#include <iostream>
#include <string>
#include <deque>
using namespace std;



int main(){
    int n; cin>>n;
    string s;
    cin >> s;
    deque<int> qS, qK;
    for(int i=0;i<n;i++){
        if(s[i]=='S') qS.push_back(i);
        else qK.push_back(i);
    }
    while(!qS.empty() && !qK.empty()){
        int a = qS.front();
        int b = qK.front();
        if(a < b){
            qS.pop_front();
            qK.pop_front();
            qS.push_back(a + n);
        } else {
            qK.pop_front();
            qS.pop_front();
            qK.push_back(b + n);
        }
    }
    cout << (qS.empty() ? "KATSURAGI" : "SAKAYANAGI") << '\n';
    return 0;
}
