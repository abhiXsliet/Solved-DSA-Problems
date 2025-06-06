// https://www.geeksforgeeks.org/problems/search-pattern-rabin-karp-algorithm--141631/1




#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    typedef long long ll;
    const int M = 1e9 + 7;
    int m, n;
    
    ll getHash(string &pat) {
        ll ans = 0, factor = 1;
        for (int i = m - 1; i >= 0; i --) {
            ans   += (factor * (pat[i] - 'a')) % M;
            factor = (factor * 26) % M;  // 26^m, 26^m-1, 26^m-2, ..., 26^0
        }
        return ans % M;
    }
  public:
    // TC : O(M + N)
    // SC : O(1)
    vector<int> search(string &pat, string &txt) {
        m = pat.length(), n = txt.length();
        
        ll dPowerM = 1;
        for (int i = 1; i <= m; i ++) {
            dPowerM = (dPowerM * 26) % M;
        }
        
        ll hashPatt = getHash(pat);
        ll hashTxt  = 0;
        vector<int> result;
        
        for (int i = 0; i <= n - m; i ++) {

            if (i == 0) {
                string s = txt.substr(i, m);
                hashTxt = getHash(s);
            } else {    // calculate rolling hash
                hashTxt = (hashTxt * 26 - (dPowerM * (txt[i - 1] - 'a')) + (txt[i + m - 1] - 'a')) % M;
                hashTxt = (hashTxt + M) % M;
            }
            
            if (hashPatt == hashTxt) {
                int j = 0;
                for (; j < m; j ++) {
                    if (txt[i + j] != pat[j]) {
                        break;
                    }
                }
                if (j == m) {
                    result.push_back(i + 1);
                }
            }
        }
        
        return result;
    }
};