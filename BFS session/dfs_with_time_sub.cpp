#include <bits/stdc++.h>
using namespace std;
#define int long long

int n;
vector<vector<pair<int,int>>> adj;
int ans=0;

void dfs(int node) {
    for(auto next : adj[node]) {
        if(next.first < node) {
            // "next" is the supervisor of "node"
            dfs(next.first);
            ans+=next.second;
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    adj.resize(n);
    for(int i = 1; i < n; i++) {
        int x,y; 
        cin >> x>>y;
        --x;
        adj[i].push_back({x,y});
        adj[x].push_back({i,y});

    }
    dfs(n - 1);
    cout<<ans;
    
    return 0;
}