#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

bool check_paddocks(const vector<pair<int,int>>& sheep_corners, int k, int pad_size){
    // cout << "candidate is called " << pad_size << endl;
    long long covered = 0;
    for(auto [cx, cy] : sheep_corners){
        covered += ((cx <= pad_size) && (cy <= pad_size));
    }
    // cout << "candidate is valid: " << (covered >= k) << endl;
    return covered >= k;
}

int main(){
    int n, k;
    cin >> n >> k;

    int x1, y1, x2, y2;
    vector<pair<int, int>> sheep_corners;
    int max_dim = 0;
    for(int i = 0; i < n; ++i){
        cin >> x1 >> y1 >> x2 >> y2;
        sheep_corners.push_back({x2, y2});
        max_dim = max(max_dim, max(x2, y2));
    }
    int left = 0, right = max_dim;
    int answer = max_dim;

    while(left <= right){
        int mid = left + (right - left) / 2;
        if(check_paddocks(sheep_corners, k, mid)){
            answer = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << answer << '\n';
    return 0;
}