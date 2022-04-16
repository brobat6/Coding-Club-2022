#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MOD = 1000000007;
// const int MOD2 = 998244353;

int fib(int n) {
    // O(2^n)
    if(n == 1 || n == 2) return 1;
    return fib(n - 1) + fib(n - 2);
}

vector <int> fibo(100000, 0);
// vector <int> name(size, initial value);

int fib_memoised(int n) {
    if(fibo[n] == 0) {
        if(n == 1 || n == 2) {
            fibo[n] = 1;
        } else {
            fibo[n] = fib_memoised(n - 1) + fib_memoised(n - 2);
        }
    }
    return fibo[n];
}

void fib_iterative(int n) {
    int fib[n];
    fib[0] = 1;
    fib[1] = 1;
    for(int i = 2; i < n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
        // if we had to calculate modulo M
        fib[i] = (fib[i - 1] + fib[i - 2]) % MOD;
    }
}

int fact(int n) {
    if(n == 0) return 1;
    return n * fact(n - 1);
}

vector <int> facto(1000, 1);

int fact_memoised(int n) {
    if(n > 1 && facto[n] == 1) {
        facto[n] = n * fact_memoised(n - 1);
    }
    return facto[n];

}

int custom_pow(int a, int b) {
    if(b == 0) return 1;
    return a * custom_pow(a, b - 1);
}

void modulo() {
    int x = 7;
    int y = 99;
    int r = 5;
    cout << (x + y) % r << '\n';
    cout << (x * y) % r << '\n';
    // cout << (x - y + r) % r << '\n';
    // cout << (x%r - y%r + r) % r << '\n';
    cout << ((x - y) % r + r) % r << '\n';
}

int the_cooler_custom_pow(int a, int b) {
    if(b == 0) return 1;
    int c = the_cooler_custom_pow(a, b/2);
    if(b % 2 == 1) {
        return a * c * c;
    } else {
        return c * c;
    }
}

int binpow(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }   
    return res % MOD;
}

/* 
QUESTIONS - 
Q1. Find the number of binary strings of length N which don't have 2 consecutive 0s
Q2. Find sum of GP in O(Log N) using bin exp concept (without using the result of sum of GP)
Q3. https://leetcode.com/problems/climbing-stairs/
*/

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    // fib_memoised(10);
    // for(int i = 0; i <= 10; i++) {
    //     cout << fibo[i] << " ";
    // }

    modulo();

    return 0;
}