#include <bits/stdc++.h>
using namespace std;
#define int long long

int n;
vector<vector<int>> adj;
vector <int> ans;

void dfs(int node) {
    ans.push_back(node);
    for(auto next : adj[node]) {
        if(next < node) {
            // "next" is the supervisor of "node"
            dfs(next);
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    adj.resize(n);
    for(int i = 1; i < n; i++) {
        int x; 
        cin >> x;
        --x;
        adj[i].push_back(x);
        adj[x].push_back(i);
    }
    dfs(n - 1);
    reverse(ans.begin(), ans.end());
    for(auto i : ans) cout << i + 1 << " ";
    
    return 0;
}