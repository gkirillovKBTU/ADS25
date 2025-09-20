#include <iostream>
#include <vector>
#include <deque>
#include <stack>
#include <cmath>
#include <climits>
using namespace std;

int main() {
    int n, t; cin >> n;
    vector<int> array;
    int el, closest_el, closest_diff;
    closest_el = -1;
    closest_diff = INT_MAX;
    for(int i = 0; i < n; i ++){
        cin >> el;
        array.push_back(el);
    }
    cin >> t;
    for(int i = 0; i < n; i ++){;
        int curr_diff = abs(t - array[i]);
        if (closest_diff > curr_diff){
            closest_el = i;
            closest_diff = curr_diff;
        }
    }
    std::cout << closest_el << endl;
    return 0;
}