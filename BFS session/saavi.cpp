#include <bits/stdc++.h>
using namespace std;
#define forn(i,a,k) for(long long i = a; i < k; i++)
#define endl "\n"
#define int long long
const int MAXN = 200100;
const int MOD = 1000000007;
int n,m;
int u=0;
vector<vector<int>> edge;
vector<bool> vis;
vector <int> A;

void dfs(int node) {
    vis[node]=1;
    for (int i=0;i<edge[node].size();i++) {
        int nbr=edge[node][i];
        if (!vis[nbr]) {
            if (nbr==(n-1)){
                u=1;
            }
            if (u==1){
                break;
            }
            dfs(nbr);
        }
    }
    if (u==1){
    A.push_back(node);
}
}


int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    edge.resize(n);
    vis.resize(n,0);
    forn(i,1,n){
        int x;
        cin >> x;
        edge[x-1].push_back(i);
        edge[i].push_back(x-1);
    }
    dfs(0);
    sort (A.begin(),A.end());
    int s= A.size();
    forn (i,0,s){
        cout<<(A[i]+1)<<" ";
    }
    cout <<n<<"\n";
      
}