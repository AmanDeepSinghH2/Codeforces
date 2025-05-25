#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void dfs(vector<int>& arr, vector<int>& depth, int l, int r, int d) {
    if (l > r) return;
    
    int max_idx = l;
    for (int i = l; i <= r; i++) {
        if (arr[i] > arr[max_idx]) {
            max_idx = i;
        }
    }
    
    depth[max_idx] = d;
    dfs(arr, depth, l, max_idx - 1, d + 1);
    dfs(arr, depth, max_idx + 1, r, d + 1);
}

void solve() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n), depth(n, -1);
        
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        
        dfs(arr, depth, 0, n - 1, 0);
        
        for (int d : depth) {
            cout << d << " ";
        }
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
