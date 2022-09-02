#include <bits/stdc++.h>
#define endl "\n"
#define int long long
using namespace std;

vector<vector<int>> edge;
vector<int> parent;
vector<bool> vis;
vector<int> ans;
int chk = 0;
void dfs(int node)
{
    vis[node] = 1;
    // Code here

    for (int i = 0; i < edge[node].size(); i++)
    {
        int nbr = edge[node][i];
        if (!vis[nbr])
        {
            if (nbr == parent.size() - 1)
                chk = 1;
            if (chk)
            {
                break;
            }
            dfs(nbr);
        }
    }
    if (chk)
        ans.push_back(node);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // int T = 0;
    // cin >> T; // You can comment out this line when you don't need to take test cases as input.
    // for(int t = 0; t < T; t++) {

    //}
    int n;
    cin >> n;
    vis.resize(n);
    parent.resize(n);
    edge.resize(n);
    for (int i = 1; i < n; i++)
    {
        int m;
        cin >> m;
        parent[i] = m - 1;
        edge[m - 1].push_back(i);
    }
    dfs(0);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[ans.size() - 1 - i] + 1 << " ";
    }
    cout << n << endl;

    return 0;
}