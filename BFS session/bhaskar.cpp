#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> tree;
vector<int> visited;
vector<int> parent;

void dfs(int node) {
    visited[node] = 1;
    for (int i = 0; i < (int)tree[node].size(); i++) {
        int n = tree[node][i];
        if (visited[n] == 0) {
            parent[n] = node;
            dfs(tree[node][i]);
        }
    }


}

int main() {
    int n;
    cin >> n;
    tree.resize(n);
    visited.resize(n);
    parent.resize(n);

    for (int i = 1; i < n; i++) {
        int ele;
        cin >> ele;
        ele--;
        tree[ele].push_back(i);
        tree[i].push_back(ele);
    }

    parent[0] = -1;
    dfs(0);
    int cur = n-1;
    vector<int> path;
    while (cur != -1) {
        path.push_back(cur+1);
        cur = parent[cur];
    }

    for (int i = (int)path.size()-1; i>= 0; i--) {
        cout << path[i] << " ";
    }
    cout << endl;

}