#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;

int main(){
    int n, k, el;
    cin >> n >> k;

    vector<int> arr(n);
    vector<int> prefix_sums(n+1);
    int answer = INT_MAX;
    prefix_sums[0] = 0; 
    cin >> el;
    prefix_sums[1] = el;
    for(int i = 1; i < n; ++i){
        cin >> el;
        prefix_sums[i+1] = (el + prefix_sums[i]);
    }

    for(int start=0; start < n; ++start){
        int startIdx = start, maxIdx = n - 1;
        while(startIdx <= maxIdx){
            int endIdx = startIdx + (maxIdx - startIdx) / 2;
            // cout << " End index" << endIdx << endl;
            // cout << " Probable sum" << prefix_sums[endIdx+1] << prefix_sums[startIdx] << endl;
            if(prefix_sums[endIdx+1] - prefix_sums[start] >= k){
                answer = min(endIdx - start + 1, answer);
                maxIdx = endIdx - 1;
            } else {
                startIdx = endIdx + 1;
            }
        }
    }

    cout << answer << '\n';
    return 0;
}