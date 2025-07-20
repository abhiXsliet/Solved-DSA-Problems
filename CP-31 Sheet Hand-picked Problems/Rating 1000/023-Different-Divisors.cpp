// https://codeforces.com/problemset/problem/1474/B




#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> getAllPrimes(int n) {
    vector<bool> primes(n + 1, 1);
    primes[0] = primes[1] = 0;
    for (int i = 2; i * i <= n; i ++) {
        for (int j = 2*i; j <= n; j += i) {
            if (primes[i]) {
                primes[j] = 0;
            }
        }
    }
    vector<int> result;
    for (int i = 2; i <= n; i ++) {
        if (primes[i]) {
            result.push_back(i);
        }
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n = 1e5;
    vector<int> primes = getAllPrimes(n);
    
    int t;
    cin >> t;
    while (t --) {
        int d;
        cin >> d;

        // p >= d + 1, q >= d + p
        int p = *lower_bound(begin(primes), end(primes), d + 1);
        int q = *lower_bound(begin(primes), end(primes), d + p);
        
        ll mini = min((ll)p*p*p, (ll)p*q);
        cout << mini << endl;
    }
    return 0;
}