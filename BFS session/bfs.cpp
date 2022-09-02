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

    int source, destination;
    cin >> source >> destination;
    // Find the shortest distance from source to destination, and print the shortest path

    vector <int> visited(n, false);
    vector <int> dist(n, -1);

    queue <int> q;
    q.push(source);
    dist[source] = 0;

    // O(N + M)
    while(!q.empty()) { // while the queue is not empty
        int curr = q.front();
        for(auto next : adj[curr]) {
            if(visited[next] == false) {
                q.push(next);
                visited[next] = true;
                dist[next] = dist[curr] + 1;
            }
        }
        q.pop();
    }

    
    return 0;
}