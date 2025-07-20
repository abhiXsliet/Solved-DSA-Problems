// https://codeforces.com/problemset/problem/1765/M




#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

vector<ll> getFactors(ll n) {
    vector<ll> factors;
    for (int i = 2; i * i <= n; i ++) {
        if (n % i == 0) {
            factors.push_back(n / i);
            if (n / i != i) {
                factors.push_back(i);
            }
        }
    }
    return factors;
}

// TC : O(sqrt(N) * log(N))
pair<ll, ll> getMinNum1(ll n) {
    vector<ll> factors = getFactors(n);
    ll lcm = (n - 1);
    pair<ll, ll> ans = {1, (n - 1)};
    for (ll &f : factors) {
        ll a = f;
        ll b = n - a;
        ll newLcm = ((a * b) / gcd(a, b));  // log(n)
        if (newLcm < lcm) {
            lcm = newLcm;
            ans.first  = a;
            ans.second = b;
        }
    }
    return ans;
}

// TC : O(sqrt(N))
pair<ll, ll> getMinNum2(ll n) {
    vector<ll> factors = getFactors(n);
    ll lcm = (n - 1);
    pair<ll, ll> ans = {1, (n - 1)};
    for (int i = 2; i*i <= n; i ++) {
        if (n % i == 0) {
            int a = n / i;
            ans.first  = a;
            ans.second = (n - a);
            break;
        }
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t --) {
        ll n;
        cin >> n;
        // pair<ll, ll> ans = getMinNum1(n);
        pair<ll, ll> ans = getMinNum2(n);
        cout << ans.first << " " << ans.second;
        cout << endl;
    }
    return 0;
}