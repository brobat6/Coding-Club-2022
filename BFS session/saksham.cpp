#include <bits/stdc++.h>
using namespace std;

#define forn(i,a,n) for(long long i = a; i < n; i++)
#define endl "\n" 
#define int long long

vector<vector<int> > edge;
vector <bool> inpath;
vector <bool> vis;
int n;

const int MAXN = 200100;
const int MOD = 1000000007;
void dfs(int node){
    vis[node]=1;
    if(node==n){
        inpath[node]=true;
        return;
    }
    inpath[node]=false;
    for(int i=0;i<edge[node].size();i++){
        if(!vis[edge[node][i]]){
            dfs(edge[node][i]);
        }
        inpath[node]=inpath[node] || inpath[edge[node][i]];
    }
}
void solve() {
    cin>>n;
    edge.clear();
    edge.resize(n);
    inpath.clear();
    inpath.resize(n,0);
    vis.clear();
    vis.resize(n,0);
    for (int i=2;i<=n;i++) {
        int x;
        cin>>x;
        edge[x].push_back(i);
    }
    dfs(1);
    int answer=1;
    cout<<"1 ";
    while(answer!=n){
        for(int i=0;i<edge[answer].size();i++){
            if(inpath[edge[answer][i]]){
                cout<<edge[answer][i]<<" ";
                answer=edge[answer][i];
                break;
            }
        }
    }

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T = 1;
    //cin >> T;
    for(int I = 1; I <= T; I++) {
        solve(); 
    }
    return 0;
}