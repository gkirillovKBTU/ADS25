#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int binary_search(const vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    while(left <= right) {
        int mid = left + (right - left) / 2;
        if(arr[mid] == target)
            return mid;
        else if(arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int main() {
    int n, x;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; ++i)
        cin >> arr[i];
    cin >> x;
    int idx = binary_search(arr, x);
    if(idx != -1)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}