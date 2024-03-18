// https://www.codechef.com/problems/BGME?tab=statement



#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int t;
    cin >> t; 
    while(t--) {
        int n;
        cin >> n;
        vector<ll> balls(n); 
        for (int i = 0; i < n; i++) {
            cin >> balls[i]; 
        }

        ll odd_cnt  = 0;
        ll ones_cnt = 0;
        
        for (int i = 0; i < n; i++) {
            if (balls[i] == 1) 
                ones_cnt ++;
            if (balls[i] % 2) 
                odd_cnt ++;
        }
        
        ll alice_pt = (ones_cnt + 1) / 2;
        ll bob_pt   = ones_cnt / 2;
        
        // odd balls are present odd number of times -> Alice benefited (wins)
        if (odd_cnt % 2) {
            alice_pt += (n - ones_cnt);
        }
        // odd balls are present even number of times -> Bob benefited (wins)
        else {
            bob_pt += (n - ones_cnt);
        }
    
        if (alice_pt > bob_pt) 
            cout << "Alice" << endl;
        else if (alice_pt < bob_pt)
            cout << "Bob" << endl;
        else 
            cout << "Draw" << endl;
    }
    return 0;
}