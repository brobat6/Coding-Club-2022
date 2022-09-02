#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl '\n'
#define forn(i, n) for(int i = 0; i < n; i++)
#define fora(i, a, n) for(int i = a; i < n; i++)
#define pb push_back
#define vi vector<int>
const int N = (int)2e5 + 10;



vi adj[N];
int vis[N];
int path[N];

void dfs(int node, int n)
{
    vis[node]=1;
    path[node]=0;
    for(int c : adj[node])
    {
        if(vis[c]) continue;
        dfs(c, n);
        path[node] |= path[c];
    }
    if(node == n) path[node]=1;
}

void dfs2(int node){
    vis[node]=1;
    if(path[node])
    {
        cout << node << " ";
    }
    for(int c : adj[node])
    {
        if(vis[c]) continue;
        dfs2(c);
    }
}

int32_t main(void)
{
    fast;
    int t = 1;
    // cin >> t;
    while(t--)
    {
       int n;
       cin >> n;
       for(int i=2; i <= n; i++)
       {
            int x;
            cin >> x;
            adj[i].pb(x);
            adj[x].pb(i);
       }
       dfs(1, n);
       forn(i, n+1)
       {
            vis[i]=0;
       }
       dfs2(1);
    }       
}