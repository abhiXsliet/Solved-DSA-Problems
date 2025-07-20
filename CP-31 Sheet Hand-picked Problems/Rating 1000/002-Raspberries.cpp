#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& arr, int n, int k) {
    int ans = INT_MAX;
    int oddCnt = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2) {
            oddCnt ++;
        }
        if (arr[i] % k == 0) {
            return 0;
        } else {
            ans = min(ans, k - (arr[i] % k));
        }
    }
    int evenCnt = n - oddCnt;
    if (k == 4) {
        if (evenCnt == 0) {
            ans = min(ans, 2);
        } else {
            if (evenCnt >= 2) {
                return 0;
            }
            ans = min(ans, 1);
        }
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cout << solve(arr, n, k) << endl;
    }
    return 0;
}


/* 
5
7 3
2 3

3 3
7 4 1
1 1 1

5 2
9 7 7 3 9
1 1 1 1 1

4 5
8 9 9 3
3 4 4 3

2 5
1 6
1 1

3 4
3 5 3
3 1 3

4 4
1 4 1 1
1 0 1 1

3 4
1 5 9
1 1 1

3 4
6 3 6
2 

*/