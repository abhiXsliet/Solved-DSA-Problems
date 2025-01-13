// https://www.geeksforgeeks.org/problems/container-with-most-water0535/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  private:
    // TC : O(N)
    // SC : O(1)
    int getLeftMaxIdx(vector<int>& arr, int idx, int n) {
        if (idx == 0) return 0;
        int maxH = arr[idx];
        int maxI = -1;
        for (int i = idx - 1; i >= 0; i --) {
            if (arr[i] >= arr[idx]) {
                maxI = i;
            } 
        }
        return maxI;
    } 
    // TC : O(N)
    // SC : O(1)
    int getRightMaxIdx(vector<int>& arr, int idx, int n) {
        if (idx == n - 1) return n - 1;
        int maxH = arr[idx];
        int maxI = -1;
        for (int i = idx + 1; i < n; i ++) {
            if (arr[i] >= arr[idx]) {
                maxI = i;
            } 
        }
        return maxI;
    } 
    
    // TC : O(N^2)
    // SC : O(1)
    int approach_1(vector<int>& arr) {
        int n = arr.size();
        int mostWaterCont = 0;
        for (int i = 0; i < n; i ++) {
            int idx1 = getLeftMaxIdx(arr,  i, n);
            int idx2 = getRightMaxIdx(arr, i, n);
            int leftMaxIdx  = idx1 == -1 ? i : idx1;
            int rightMaxIdx = idx2 == -1 ? i : idx2;
            int areaCovered = (rightMaxIdx - leftMaxIdx) * arr[i];
            mostWaterCont   = max(mostWaterCont, areaCovered);
        }
        return mostWaterCont;
    }
    
    // TC : O(N)
    // SC : O(1)
    int approach_2(vector<int>& arr) {
        int n = arr.size();
        int i = 0, j = n - 1;
        int mostWaterCont = 0;
        while (i < j) {
            int waterCont = (j - i) * min(arr[i], arr[j]);  // Area = (L * B)
            mostWaterCont = max(mostWaterCont, waterCont);
            if (arr[i] < arr[j]) {
                i ++;
            } else {
                j --;
            }
        }
        return mostWaterCont;
    }
  public:
    int maxWater(vector<int> &arr) {
        // return approach_1(arr);  // Brute
        return approach_2(arr);  // Optimal
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.maxWater(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends