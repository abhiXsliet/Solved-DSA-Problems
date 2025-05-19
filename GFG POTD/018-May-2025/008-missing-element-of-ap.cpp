// https://www.geeksforgeeks.org/problems/missing-element-of-ap2228/1




//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

// User function template for C++
class Solution {
  private:
    // TC : O(N)
    // SC : O(1)
    int approach_1(vector<int> &arr) {
        int n = arr.size();
        
        int cd = ((arr[1] - arr[0]) == (arr[n - 1] - arr[n - 2])) ? (arr[1] - arr[0]) 
               : ((arr[1] - arr[0]) == (arr[n - 1] - arr[0]) / n) ? (arr[1] - arr[0]) : (arr[n - 1] - arr[n - 2]); 
    
        if (cd == 0) return arr[0]; // all elements are same
        
        // sn = [2a + (n - 1)*d] * n/2 
        long long sum = (2LL * arr[0] + (n * cd)) * (n + 1)/2;
        
        long long s = 0;
        for (int &num : arr) {
            s += num;
        }
        
        return sum - s;
    }

    // TC : O(log(N))
    // SC : O(1)
    int approach_2(vector<int> &arr) {
        int n = arr.size();
        
        int cd = ((arr[1] - arr[0]) == (arr[n - 1] - arr[n - 2])) ? (arr[1] - arr[0]) 
               : ((arr[1] - arr[0]) == (arr[n - 1] - arr[0]) / n) ? (arr[1] - arr[0]) : (arr[n - 1] - arr[n - 2]); 
    
        if (cd == 0) return arr[0]; // all elements are same
        
        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            // arr[i] = arr[0] + i * cd 
            if ((arr[mid] - arr[0]) / cd == mid) {  // ((arr[i] - arr[0]) / cd) == i
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return arr[high] + cd;
    }
  public:
    int findMissing(vector<int> &arr) {
        // return approach_1(arr);  // Math
        return approach_2(arr);  // log(N)
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

        getline(cin, input);

        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        cout << ob.findMissing(arr) << "\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends