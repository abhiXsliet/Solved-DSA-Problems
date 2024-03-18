// https://www.codechef.com/problems/CRICKETUDYAM



#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        if(m <= n-1) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
