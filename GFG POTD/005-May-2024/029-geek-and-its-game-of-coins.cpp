// https://www.geeksforgeeks.org/problems/geek-and-its-game-of-coins4043/1



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  public:
    int findWinner(int n, int x, int y) {
        vector<int>arr(n + 1, 0);
        arr[1] = 1;
        for(int i = 2; i <= n; i ++){
            int j=i-1;
            if(j >= 0 && arr[j] == 0) {
                arr[i] = 1;
            }
            j = i - x;
            if(j >= 0 && arr[j] == 0){
                arr[i] = 1;
            }
            j = i - y;
            if(j >= 0 && arr[j] == 0){
                arr[i] = 1;
            }
        }
        return arr[n];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        int x;
        scanf("%d", &x);

        int y;
        scanf("%d", &y);

        Solution obj;
        int res = obj.findWinner(n, x, y);

        cout << res << endl;
    }
}
// } Driver Code Ends