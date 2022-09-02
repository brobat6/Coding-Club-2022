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
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    int source, destination;
    cin >> source >> destination;
    // Find the shortest distance from source to destination, and print the shortest path

    vector <int> visited(n, -1);
    vector <int> dist(n, -1);
    vector <int> path;
    visited[source-1] = -2;

    queue <int> q;
    q.push(source-1);
    dist[source-1] = 0;
    // O(N + M)
    while(!q.empty()) { // while the queue is not empty
        int curr = q.front();
        if (curr == destination-1) {
            while (curr != -2) {
                path.push_back(curr+1);
                curr = visited[curr];
            }
            cout << endl;

            break;
        }

        //cout << curr << endl;

        for(auto next : adj[curr]) {
            if(visited[next] == -1) {
                q.push(next);
                visited[next] = curr;
                dist[next] = dist[curr] + 1;
            }
        }
        q.pop();
    }

    reverse(path.begin(), path.end());
    cout << dist[destination-1] << endl;
    for(int i = 0; i < path.size(); i++) {
        cout << path[i] << " ";
    }
    cout << endl;

    
    return 0;
}