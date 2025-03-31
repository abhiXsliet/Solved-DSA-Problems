// https://leetcode.com/problems/apply-operations-to-maximize-score/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    typedef long long int ll;
    const int M = 1e9 + 7;

    ll getPower(ll a, ll b) {
        if (b == 0) return 1;
        ll res = 1;
        while (b > 0) {
            if (b & 1) {
                res = (res * a) % M;
            }
            a = (a % M * a % M) % M;
            b >>= 1;
        }
        return res;
    }

    void getSubArrays(vector<ll> &subarrays, int n, vector<int> &NGE, vector<int> &PGE) {
        for (int i = 0; i < n; i ++) {
            ll rightCnt = NGE[i] - i;   // end of subarrays
            ll leftCnt  = i - PGE[i] ;  // start of subarrays
            subarrays[i] = (leftCnt * rightCnt);
        }
    }

    void getPrevGreaterEqualEle(vector<int> &primeScore, vector<int> &PGE) {
        stack<int> stk;
        for (int i = 0; i < primeScore.size(); i ++) {
            while (!stk.empty() && primeScore[stk.top()] < primeScore[i]) {
                stk.pop();
            }
            PGE[i] = !stk.empty() ? stk.top() : -1;
            stk.push(i);
        }
    }

    void getNextGreaterEle(vector<int> &primeScore, vector<int> &NGE) {
        stack<int> stk;
        for (int i = 0; i < primeScore.size(); i ++) {
            while (!stk.empty() && primeScore[stk.top()] < primeScore[i]) {
                NGE[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);
        }
    }

    int getScore(int num, vector<int> &primes) {
        int score = 0;
        for (int i = 0; i < primes.size(); i ++) {
            if (primes[i] * primes[i] > num) break; // catch : tle
            if (num % primes[i] == 0) {
                score += 1;
                while (num % primes[i] == 0) {
                    num /= primes[i];
                }
            }
        }
        if (num > 1) score += 1;
        return score;
    }

    void getPrimeScores(vector<int> &nums, int n, vector<int> &primeScore, vector<int> &primes) {
        for (int i = 0; i < n; i ++) {
            primeScore[i] = getScore(nums[i], primes);
        }
    }

    void getPrimes(vector<int> &primes, int maxi) {
        primes[0] = primes[1] = 0;
        for (int i = 2; i * i <= maxi; i ++) {
            if (primes[i]) {
                for (int j = i * i; j <= maxi; j += i) {
                    primes[j] = 0;
                }
            }
        }
        vector<int> onlyPrime;
        for (int i = 2; i < maxi; i ++) {
            if (primes[i]) {
                onlyPrime.push_back(i);
            }
        }
        primes = onlyPrime;
    }
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        int maxi = *max_element(begin(nums), end(nums));

        vector<int> primes (maxi + 1, 1);
        getPrimes(primes, maxi);    // O(maxi*log(log(maxi)))

        vector<int> primeScore(n, 0);
        getPrimeScores(nums, n, primeScore, primes);    // O(n*log(maxi))

        vector<int> NGE(n, n);
        getNextGreaterEle(primeScore, NGE); // O(n)

        vector<int> PGE(n, -1);
        getPrevGreaterEqualEle(primeScore, PGE);    // O(n)

        vector<ll> subarrays(n, 0);
        getSubArrays(subarrays, n, NGE, PGE);   // O(n)

        vector<pair<int, int>> store;
        for (int i = 0; i < n; i ++) {
            store.push_back({nums[i], i});
        }

        sort(rbegin(store), rend(store));   // O(n*log(n))

        ll result = 1;
        int idx = 0;
        while (k > 0) { // O(k * log(operations))
            auto [val, i]  = store[idx ++];
            ll operations = min((ll)k, subarrays[i]);
            result = (result * getPower((ll)val, operations)) % M;

            k -= operations;
        }
        return (int)result;
    }
};