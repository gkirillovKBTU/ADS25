#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

bool check_capacity(const vector<int>& children, int flights, int cap){
    long long required = 0;
    for(int c : children){
        required += (c + cap - 1) / cap;
        if(required > flights) return false;
    }
    return required <= flights;
}

int main(){
    int n;
    long long f;
    cin >> n >> f;

    vector<int> children(n);
    int max_children = 0;
    for(int i = 0; i < n; ++i){
        cin >> children[i];
        max_children = max(max_children, children[i]);
    }

    int left = 1, right = max_children;
    int answer = max_children;

    while(left <= right){
        int mid = left + (right - left) / 2;
        if(check_capacity(children, f, mid)){
            answer = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << answer << '\n';
    return 0;
}
