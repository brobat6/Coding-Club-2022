#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double

double pos = 0.0;
double neg = 0.0;

void func(string s) {
    if((int)s.length() == 11) {
        if(s[0] == 'O') return;
        int earnings = 0;
        double first = 1.0;
        double second = 1.0;
        for(auto i : s) {
            if(i == 'O') {
                first *= 0.2;
                second *= 0.8;
                earnings -= 9;
            } else {
                first *= 0.8;
                second *= 0.2;
                earnings += 10;
            }
        }
        if(earnings > 0) {
            pos += first;
            pos += second;
        } else if(earnings < 0) {
            neg += first;
            neg += second;
        }
    } else {
        func(s + "O");
        func(s + "E");
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string t;
    func(t);

    cout << setprecision(15) << pos << " " << neg;
    
    return 0;
}