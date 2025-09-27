#include <iostream>
#include <vector>
#include <queue>


using namespace std;
int main() {
    int T;
    if(!(cin >> T)) return 0;
    while (T--) {
        int N;
        cin >> N;
        vector<int> cnt(26,0);
        queue<char> q;
        bool firstOut = true;
        for (int i = 0; i < N; ++i) {
            char ch;
            cin >> ch;
            cnt[ch - 'a']++;
            q.push(ch);
            while (!q.empty() && cnt[q.front() - 'a'] > 1) q.pop();
            if (!firstOut) cout << ' ';
            firstOut = false;
            if (q.empty()) cout << -1;
            else cout << q.front();
        }
        cout << '\n';
    }
    return 0;
}
