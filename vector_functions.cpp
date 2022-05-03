#include <bits/stdc++.h>
using namespace std;
#define int long long

// Find the number of binary strings of length N which don't have 2 consecutive 0s
int bin_strings(int n, int b) {
    if(n == 1) return 1;
    if(b == 0) {
        return bin_strings(n - 1, 1);
    } else {
        return bin_strings(n - 1, 1) + bin_strings(n - 1, 0);
    }
}

// Find sum of GP in O(Log N) using bin exp concept (without using the result of sum of GP)
/*
1 + r + r^2 + r^3 + ..... r^(n - 1).

1 + r + r^2 + .... r^7

1 + r^2 + r^4 + r^6
r + r^3 + r^5 + r^7
= (1 + r^2 + r^4 + r^6) * (1 + r)

(1 + r + r^2 + r^3) + (r^4 + r^5 + r^6 + r^7)
(1 + r + r^2 + r^3) * (1 + r^4)


1 + r + r^2 + .... r^8
1 + r(1 + r + r^2 + ... r^7)
1 + r*(1 + r^2 + r^4 + r^6)*(1 + r)
*/
int gp(int r, int n) {
    if(n == 1) return 1;
    if(n % 2 == 0) {
        return gp(r*r, n/2) * (1 + r);
    } else {
        return 1 + r*gp(r*r, n/2) * (1 + r);
    }
}

bool comp(int a, int b) {
    return a > b;
}

void vector_functions() {
    vector <int> v = {1, 2, 10, 5, 2, 5, 10, 4};
    // Find length of vector
    int n = (int)v.size();
    // for(int i = 0; i < (int)v.size(); i++) {
        // cout << v[i] << " ";
    // }
    // for-each loop
    for(auto i : v) {
        cout << i << " ";
    }
    cout << '\n';
    sort(v.begin(), v.end()); // sort
    // sort(v.begin(), v.end(), greater<int>()); // sort in reverse
    // sort(v.begin(), v.end(), comp);

    cout << is_sorted(v.begin(), v.end()) << '\n';

    cout << accumulate(v.begin(), v.end(), 0ll) << '\n';

    vector <int> w(10);
    // 0, 1, 2, 3, 4, ....
    iota(w.begin(), w.end(), 0ll);
    for(auto i : w) cout << i << " ";

    // reverse(v.begin(), v.end());
    reverse(v.begin() + 2, v.end());
    reverse(v.begin() + 3, v.begin() + 5);

    int x = *max_element(v.begin(), v.end());
    int x_ind = max_element(v.begin(), v.end()) - v.begin();
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector_functions();
    
    return 0;
}