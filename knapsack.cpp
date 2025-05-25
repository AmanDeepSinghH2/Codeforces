#include <bits/stdc++.h>
using namespace std;

void solve() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        long long W;
        cin >> n >> W;
        vector<pair<long long, int>> items(n);
        
        for (int i = 0; i < n; i++) {
            cin >> items[i].first;
            items[i].second = i + 1;
        }
        
        sort(items.rbegin(), items.rend());  // Sort in descending order
        long long sum = 0;
        vector<int> selected;
        
        for (auto item : items) {
            if (item.first >= (W + 1) / 2 && item.first <= W) {
                cout << "1\n" << item.second << endl;
                goto next_case;
            }
        }
        
        for (auto item : items) {
            if (sum + item.first <= W) {
                sum += item.first;
                selected.push_back(item.second);
            }
            if (sum >= (W + 1) / 2) break;
        }
        
        if (sum >= (W + 1) / 2) {
            cout << selected.size() << endl;
            for (int idx : selected) cout << idx << " ";
            cout << endl;
        } else {
            cout << "-1\n";
        }
        
        next_case:;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
