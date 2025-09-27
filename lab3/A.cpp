#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<int, pair<int,int>> pos;
vector<int> targets_order;

bool binary_search_in_row(const vector<int>& arr, int target, bool sort_desc, int rowIndex) {

    int L = 0, R = (int)arr.size() - 1;
    while (L <= R) {
        int mid = L + (R - L) / 2;
        int val = arr[mid];

        if (pos.find(val) != pos.end() && pos[val].first < 0) {
            pos[val] = {rowIndex, mid};
        }

        if (val == target) {
            return true;
        }

        if (!sort_desc) {
            if (val < target) {
                L = mid + 1;
            } else {
                R = mid - 1;
            }
        } else {
            if (val < target) {
                R = mid - 1;
            } else {
                L = mid + 1;
            }
        }
    }

    if (!sort_desc) {
        if (target < arr.front()) {
            pos[target] = {-3, -3};
        } else if (target > arr.back()) {
            pos[target] = {-2, -2};
        } else {
            pos[target] = {-1, -1};
        }
    } else {
        if (target > arr.front()) {
            pos[target] = {-2, -2};
        } else if (target < arr.back()) {
            pos[target] = {-3, -3};
        } else {
            pos[target] = {-1, -1};
        }
    }

    return false;
}

int main() {

    int k;
    if (!(cin >> k)) return 0;

    targets_order.reserve(k);
    for (int i = 0; i < k; ++i) {
        int x; cin >> x;
        targets_order.push_back(x);
        pos[x] = {-1, -1};
    }

    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> mat[i][j];
        }
    }

    for (int t : targets_order) {
        if (pos[t].first >= 0) {
            cout << pos[t].first << " " << pos[t].second << "\n";
            continue;
        }

        int u = 0, d = n - 1;
        while (u <= d) {
            int midRow = u + (d - u) / 2;
            bool row_desc = (midRow % 2 == 0);

            bool rowFound = binary_search_in_row(mat[midRow], t, row_desc, midRow);
            if (rowFound) {
                cout << pos[t].first << " " << pos[t].second << "\n";
                break;
            } else {
                std::pair<int, int> searchResult = pos[t];
                if (searchResult == make_pair(-2, -2)) {
                    // u = midRow + 1;
                    d = midRow - 1;
                    continue;
                } else if (searchResult == make_pair(-3, -3)) {
                    // d = midRow - 1;
                    u = midRow + 1;
                    continue;
                } else if (searchResult == make_pair(-1, -1)) {
                    break;
                }
            }
        }

        if (pos[t].first < 0) {
            cout << -1 << "\n";
        }
    }

    return 0;
}