// Identical to G.cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

bool check_capacity(const vector<int>& bars, int flights, int cap){
    long long required = 0;
    for(int c : bars){
        required += (c + cap - 1) / cap;
        if(required > flights || cap == 0) return false;
    }
    return required <= flights;
}

int main(){
    int n, f;
    cin >> n >> f;

    vector<int> bars(n);
    int max_bars = 0;
    for(int i = 0; i < n; ++i){
        cin >> bars[i];
        max_bars = max(max_bars, bars[i]);
    }

    int left = 1, right = max_bars;
    int answer = max_bars;

    while(left <= right){
        int mid = left + (right - left) / 2;
        if(check_capacity(bars, f, mid)){
            answer = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << answer << '\n';
    return 0;
}