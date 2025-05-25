#include <bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>>& graph, vector<int>& goods, vector<vector<int>>& dist, int k, int n) {
    queue<int> q;
    vector<bool> visited(n + 1, false);
    
    for (int i = 1; i <= n; i++) {
        if (goods[i] == k) {
            q.push(i);
            visited[i] = true;
            dist[i][k] = 0;
        }
    }
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        for (int v : graph[u]) {
            if (!visited[v]) {
                visited[v] = true;
                dist[v][k] = dist[u][k] + 1;
                q.push(v);
            }
        }
    }
}

void solve() {
    int n, m, k, s;
    cin >> n >> m >> k >> s;
    
    vector<int> goods(n + 1);
    for (int i = 1; i <= n; i++) cin >> goods[i];
    
    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    vector<vector<int>> dist(n + 1, vector<int>(k + 1, INT_MAX));
    
    for (int type = 1; type <= k; type++) {
        bfs(graph, goods, dist, type, n);
    }
    
    for (int i = 1; i <= n; i++) {
        vector<int> costs;
        for (int type = 1; type <= k; type++) {
            costs.push_back(dist[i][type]);
        }
        sort(costs.begin(), costs.end());
        
        int min_cost = accumulate(costs.begin(), costs.begin() + s, 0);
        cout << min_cost << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
