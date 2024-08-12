// https://www.geeksforgeeks.org/problems/sum-of-middle-elements-of-two-sorted-arrays2305/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends
// User function template for C++

//Position this line where user code will be pasted.
class Solution {
  private:
    // TC : O(M + N)
    // SC : O(M + N)
    int brute(vector<int>& arr1, vector<int>& arr2) {
        int m = arr1.size();
        int n = arr2.size();
        vector<int> merged(m + n, 0);
        
        int i = 0, j = 0, k = 0;
        while (i < m && j < n) {
            if (arr1[i] <= arr2[j]) {
                merged[k ++] = arr1[i ++];
            } else {
                merged[k ++] = arr2[j ++];
            }
        }
        while (i < m) merged[k ++] = arr1[i ++];
        while (j < n) merged[k ++] = arr2[j ++];
        
        if ((m + n) % 2 == 0) {
            return (merged[(m + n) / 2] + merged[(m + n - 1) / 2]);
        } 
        return merged[(m + n) / 2] + merged[(m + n + 1) / 2];
    }
    
    // TC : O(M + N)
    // SC : O(1)
    int better(vector<int>& arr1, vector<int>& arr2) {
        int m = arr1.size();
        int n = arr2.size();
        
        int el1  = -1;
        int el2  = -1;
        int idx1 = -1;
        int idx2 = -1;
        
        if ((m + n) % 2 == 0) {
            idx1 = (m + n - 1) / 2;
            idx2 = (m + n) / 2;
        } else {
            idx1 = (m + n) / 2;
            idx2 = (m + n + 1) / 2;
        }
        
        int cnt = 0;
        int i   = 0;
        int j   = 0;
        
        while (i < m && j < n) {
            if (cnt > idx1 && cnt > idx2) break;
            
            if (arr1[i] <= arr2[j]) {
                if (cnt == idx1) el1 = arr1[i];
                if (cnt == idx2) el2 = arr1[i];
                i ++;
            } else {
                if (cnt == idx1) el1 = arr2[j];
                if (cnt == idx2) el2 = arr2[j];
                j ++;
            }
            cnt ++;
        }
        while (i < m) {
            if (cnt > idx1 && cnt > idx2) break;
            
            if (cnt == idx1) el1 = arr1[i];
            if (cnt == idx2) el2 = arr1[i];
            i ++;
            cnt ++;
        }
        while (j < n) {
            if (cnt > idx1 && cnt > idx2) break;
            
            if (cnt == idx1) el1 = arr2[j];
            if (cnt == idx2) el2 = arr2[j];
            j ++;
            cnt ++;
        }
        
        return (el1 + el2);
    }
    
    // TC : O(log(N) + log(M))
    // SC : O(1)
    int optimal(vector<int>& arr1, vector<int>& arr2) {
        int m = arr1.size();
        int n = arr2.size();
        if (m > n) {
            return optimal(arr2, arr1);
        }
        
        int low  = 0;   // minimum no. of elements can be taken from arr1 in left half
        int high = m;   // maximum no. of elements can be taken from arr1 in left half
        int left = (m + n + 1) / 2; // total no. of elements in left half
        int size = (m + n);
        
        while (low <= high) {
            int mid1 = (low + high) >> 1;
            int mid2 = left - mid1;
            
            int l1  = INT_MIN, l2 = INT_MIN;
            int r1  = INT_MAX, r2 = INT_MAX;
            
            if (mid1 < m) r1 = arr1[mid1];
            if (mid2 < n) r2 = arr2[mid2];
            if (mid1 - 1 >= 0) l1 = arr1[mid1 - 1];
            if (mid2 - 1 >= 0) l2 = arr2[mid2 - 1];
            
            if (l1 <= r2 && l2 <= r1) {
                if (size % 2 == 0) {
                    return max(l1, l2) + min(r1, r2);
                } else {
                    return max(l1, l2) + min(r1, r2);
                }
            } 
            else if (l1 > r2) high = mid1 - 1;
            else low = mid1 + 1;
        }
        return 0; // flow not reach here
    }
  public:
    int SumofMiddleElements(vector<int> &arr1, vector<int> &arr2) {
        // return brute(arr1, arr2);
        
        // return better(arr1, arr2);
        
        return optimal(arr1, arr2);
    }
};

//{ Driver Code Starts.
//Back-end complete function template in C++
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr, brr;
        string input1;
        getline(cin, input1);
        stringstream ss1(input1);
        int number1;
        while (ss1 >> number1) {
            arr.push_back(number1);
        }
        string input2;
        getline(cin, input2);
        stringstream ss2(input2);
        int number2;
        while (ss2 >> number2) {
            brr.push_back(number2);
        }
        Solution ob;
        int res = ob.SumofMiddleElements(arr, brr);
        cout << res << endl;
    }
}
// } Driver Code Ends