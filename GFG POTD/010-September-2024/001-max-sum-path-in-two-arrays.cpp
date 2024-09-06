// https://www.geeksforgeeks.org/problems/max-sum-path-in-two-arrays/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  public:
    // TC : O(M + N)
    // SC : O(1)
    int maxPathSum(vector<int> &arr1, vector<int> &arr2) {
        int m = arr1.size();
        int n = arr2.size();
        
        int sum1 = 0;
        int sum2 = 0;
        
        int i = m - 1;
        int j = n - 1;
        
        while (i >= 0 && j >= 0) {
            if (arr1[i] > arr2[j]) {
                sum1 += arr1[i];
                i --;
            } else if (arr1[i] < arr2[j]) {
                sum2 += arr2[j];
                j --;
            } else {    // arr1[i] == arr2[j]
                sum1 += arr1[i];
                sum2 += arr2[j];
                
                sum1 = sum2 > sum1 ? sum2 : sum1;
                sum2 = sum1;
                
                i --;
                j --;
            }
        }
        
        for (; i >= 0; i --) sum1 += arr1[i];
        for (; j >= 0; j --) sum2 += arr2[j];
        
        return sum1 > sum2 ? sum1 : sum2;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr1;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr1.push_back(number);
        }
        vector<int> arr2;
        string input2;
        getline(cin, input2);
        stringstream ss2(input2);
        int number2;
        while (ss2 >> number2) {
            arr2.push_back(number2);
        }
        Solution ob;
        long long ans = ob.maxPathSum(arr1, arr2);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends