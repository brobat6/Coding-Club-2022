 #include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define rep(start,end,x) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define vi vector<int>
#define pb push_back

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n,t1; cin >> n;
    vi tree[n];
    rep(0,n-1,x) {
        cin>>t1;
        tree[t1].pb(x+2);
    }

    auto dfs = [=,&tree](int node, vi h, auto& f) -> void {
        if (node==n) for (int i : h) cout << i << " ";
        else {
            h.pb(node);
            for (int child : tree[node]) f(child,h,f);
        }
    };

    dfs(1,vi(),dfs);
    cout << n << endl;
}