// https://www.codechef.com/problems/BINPARITY



#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        bitset<32> binary(n);
        int c = __builtin_popcount(n);
        if(c % 2) {
            cout << "ODD" << endl;
        } else {
            cout << "EVEN" << endl;
        }
    }
    return 0;
}
