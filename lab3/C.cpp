#include <cmath> 
#include <vector> 
#include <iostream> 
#include <algorithm>
using namespace std;

int lower_bound_idx(const vector<long long>& a, long long x) {
    int n = (int)a.size();
    int l = 0;
    int r = n;
    while (l < r) {
        int m = l + (r - l) / 2;
        if (a[m] < x) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    return l;
}

int upper_bound_idx(const vector<long long>& a, long long x) {
    int n = (int)a.size();
    int l = 0;
    int r = n;
    while (l < r) {
        int m = l + (r - l) / 2;
        if (a[m] <= x) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    return l;
}

long long count_in_range(const vector<long long>& a, long long L, long long R) {
    if (L > R) return 0;
    int left_idx = lower_bound_idx(a, L);
    int right_idx = upper_bound_idx(a, R);
    return (long long)(right_idx - left_idx);
}

int main() {

    int n, q;
    if (!(cin >> n >> q)) return 0;
    vector<long long> a;
    a.reserve(n);
    for (int i = 0; i < n; ++i) {
        long long x;
        cin >> x;
        a.push_back(x);
    }

    sort(a.begin(), a.end());

    for (int i = 0; i < q; ++i) {
        long long l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;

        long long cnt1 = count_in_range(a, l1, r1);
        long long cnt2 = count_in_range(a, l2, r2);

        long long Lint = (l1 > l2) ? l1 : l2;
        long long Rint = (r1 < r2) ? r1 : r2;
        long long cnt_inter = count_in_range(a, Lint, Rint);

        long long answer = cnt1 + cnt2 - cnt_inter;
        cout << answer << '\n';
    }

    return 0;
}
