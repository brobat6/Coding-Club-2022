#include <bits/stdc++.h>
using namespace std;
#define int long long


int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;  // n -> Number of nodes, m -> Number of edges
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for(int i=0;i<m;i++){
        int x,y;
        cin >> x >> y;
        --x;
        --y;
        adj[x].push_back(y);
        adj[y].push_back(x);        
    }
    vector <int> visited(n, false);    
    int maxi=0;
    int source=0;
    queue <int> q;
    q.push(source);

    int t=0;
    while(t==0){     
        int s=0;   
        while(!q.empty()) { 
            int curr = q.front();
            for(auto next : adj[curr]) {
                if(visited[next] == false) {
                    s++;
                    q.push(next);
                    visited[next] = true;
                }
            }
            q.pop();
        }
        maxi=max(s,maxi);
        int i;
        for(i=0;i<n;i++){
            if (!visited[i]){
                source = i;
                q.push(source);
                break;
            }
        }
        if(i==n){
            t=1;
        }
    }
    cout << maxi;
}