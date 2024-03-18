// https://www.codechef.com/problems/SWAPUNITE



#include <bits/stdc++.h>
using namespace std;

// TC : O(N^2) at worst -> TLE
void solve_1() {
    string s;
    cin >> s;
    int n = s.length();
    vector<int> freq(26, 0);
    for (int i = 0; i < n; i++) {
        freq[s[i] - 'a'] ++;
    }
    
    int ans = INT_MAX;
    for (int i = 0; i < 26; i ++) {
        if (freq[i] == 0) continue;
        
        char ch = i + 'a';
        int noC = freq[i];    // total no. of char 'ch' present in freq array
        
        for (int j = 0; j < n; j++) {
            
            int cnt = 0;
            int p1 = j, p2 = j + noC;
            
            for (int k = p1; k < p2; k++) {
                if (s[k] == ch) {
                    cnt ++;
                }
            }
            
            int swaps = noC - cnt;
            ans = min(ans, swaps);
        }
    }
    cout << ans << endl;
}

// TC : O(N)
// SC : O(N)
void solve_2() {
    string s;
    cin >> s;
    int n = s.length();
    vector<int> freq(26, 0);
    for (int i = 0; i < n; i++) {
        freq[s[i] - 'a'] ++;
    }
    
    int ans = INT_MAX;
    for (int i = 0; i < 26; i ++) {
        if (freq[i] == 0) continue;
        
        char ch = i + 'a';
        int noC = freq[i];    // total no. of char 'ch' present in freq array
        
        vector<int> prefix(n); // stores the char 'ch' occurance in every size = freq[i]
        
        int cnt = 0;
        int p1  = 0, p2 = 0;
        
        while(p1 < n) {
            if (p2 < n)
                if (s[p2] == ch) cnt++;
            if (p2 - p1 + 1 == freq[i]) {
                prefix[p1] = cnt;
                if (s[p1] == ch) cnt--;
                p1 ++;
            }
            p2 ++;
        }
        
        for (int j = 0; j < n; j++) {
            int swaps = noC - prefix[j];
            ans = min(ans, swaps);
        }
    }
    cout << ans << endl;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
	   // solve_1();  // TLE
	   
	   solve_2();
	}
	return 0;
}
