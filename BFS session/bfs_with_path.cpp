#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;  // n -> Number of nodes, m -> Number of edges
    cin >> n >> m;
    vector<vector<int>> adj(n);
    // Take input of edges and make adjacency list
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        --x;
        --y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    int source, destination;
    cin >> source >> destination;
    // Find the shortest distance from source to destination, and print the shortest path
    --source;
    --destination;

    vector <int> visited(n, false);
    vector <int> dist(n, -1);
    vector <int> prev(n, -1);

    queue <int> q;
    q.push(source);
    dist[source] = 0;
    prev[source] = source;

    // O(N + M)
    while(!q.empty()) { // while the queue is not empty
        int curr = q.front();
        for(auto next : adj[curr]) {
            if(visited[next] == false) {
                q.push(next);
                visited[next] = true;
                dist[next] = dist[curr] + 1;
                prev[next] = curr;
            }
        }
        q.pop();
    }

    cout << dist[destination] << '\n';
    
    vector <int> path;
    int temp = destination;
    while(temp != source) {
        path.push_back(temp);
        temp = prev[temp];
    }
    path.push_back(source);

    reverse(path.begin(), path.end());

    for(auto i : path) cout << i + 1 << " ";
    
    return 0;
}