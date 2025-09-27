#include <vector>
#include <iostream>
#include <cmath>
using namespace std;
using ll = long long;

bool feasible(ll limit, int k, const vector<ll>& a, int n) {
    int used = 1;  
    ll cur = 0;
    for (int i = 0; i < n; ++i) {
        if (cur + a[i] <= limit) {
            cur += a[i];
        } else {
            ++used;
            cur = a[i];
            if (used > k) return false;
        }
    }
    return used <= k;
}

int main() {
    
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    ll mx = 0, sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        mx = max(mx, a[i]);
        sum += a[i];
    }

    ll lo = mx;
    ll hi = sum;

    while (lo < hi) {
        ll mid = lo + (hi - lo) / 2;
        if (feasible(mid, k, a, n)) hi = mid;
        else lo = mid + 1;
    }

    cout << lo << '\n';
    return 0;
}
