// 5 April, 2022

#include <bits/stdc++.h>
using namespace std;

bool check_prime(int n) {
    // O(sqrt(N))
    if(n < 2) return false;
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            return false;
        }
    }
    return true;
}

const int N = 1E6;
bool is_prime[N + 1];

void sieve() {
    // O(N Log(Log(N)))
    for(int i = 0; i <= N; i++) {
        is_prime[i] = true;
    }

    is_prime[0] = false;
    is_prime[1] = false;

    for(int i = 2; i <= N; i++) {
        if(is_prime[i]) {
            for(int j = i * i; j <= N; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

vector<vector<int>> factors(N);

vector<int> prime_factors(int x) {
    vector <int> ans;
    int i = 2;
    while(x > 1 && i * i <= x) {
        if(x % i == 0) {
            ans.push_back(i);
            x /= i;
        } else {
            i += 1;
        }
    }
    if(x != 1) {
        ans.push_back(x);
    }
    return ans;
}

vector<int> distinct_prime_factors(int x) {
    vector <int> ans;
    int i = 2;
    int last = 0;
    while(x > 1 && i * i <= x) {
        if(x % i == 0) {
            if(i != last) {
                ans.push_back(i);
            }
            last = i;
            x /= i;
        } else {
            i += 1;
        }
    }
    if(x != 1) {
        if(last != x) {
            ans.push_back(x);
        }
    }
    return ans;
}

/*
Notes : 
Upper bound on NUMBER of prime factors of a given number : Log2(N)

Upper bound on NUMBER of total factors of a given number (less than 10^9) : 360
*/


/*
Homework:
Given an array with N (= 10^6) elements in the range 1 to 10^6, find the prime factorisation of
all the numbers in the array.
Trivial solution : O(N * sqrt(N))
Find a better solution.
Hint : Use sieve, with some modifications. 
Hint2 : Create an array SPF (smallest prime factors) 
Array will be as follows : 
spf[2] = 2; spf[3] = 3; spf[4] = 2; spf[5] = 5; .... spf[12] = 2; ... spf[69] = 3; etc 
*/


int main(){
    
    for(int i = 2; i <= 20; i++) {
        cout << i << ": ";
        auto x = distinct_prime_factors(i);
        for(auto j : x) cout << j << " ";
        cout << endl;
    }


    return 0;
}
