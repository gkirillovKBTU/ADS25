#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int countDefeated(const vector<int>& competitors, int M) {
    int left = 0, right = competitors.size() - 1;
    int result = -1;
    while(left <= right) {
        int mid = left + (right - left) / 2;
        if(competitors[mid] <= M) {
            result = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return result + 1;
}

int main() {
    int N;
    cin >> N;
    
    vector<int> competitors(N);
    for(int i = 0; i < N; i++) {
        cin >> competitors[i];
    }
    
    sort(competitors.begin(), competitors.end());
    
    int P, M;
    cin >> P;
    
    while(P--) {
        cin >> M;
        
        int defeated = countDefeated(competitors, M);
        
        long long sum = 0;
        for(int i = 0; i < defeated; i++) {
            sum += competitors[i];
        }
        
        cout << defeated << " " << sum << endl;
    }
    
    return 0;
}
