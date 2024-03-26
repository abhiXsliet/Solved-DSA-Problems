// https://www.codechef.com/problems/DICEGAME3



#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        long long ans = 0;
        int sevensCnt = 0;
        int sixesCnt  = 0;
        if (n % 2) {
            sixesCnt  = (n + 1) / 2;
            sevensCnt = n / 2;
        }
        else {
            sevensCnt = n / 2;
            sixesCnt  = n / 2;
        }
        ans = ((sevensCnt * 7) + (sixesCnt * 6));
        cout << ans << endl;
    }
}
