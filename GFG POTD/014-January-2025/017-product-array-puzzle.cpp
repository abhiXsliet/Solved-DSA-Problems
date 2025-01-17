// https://www.geeksforgeeks.org/problems/product-array-puzzle4525/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

// User function template for C++
class Solution {
  private:
    // TC : O(N)
    // SC : O(1)
    vector<int> approach_1(vector<int>& arr) {
        int n = arr.size();
        vector<int> res(n, 0);
        long mul = 1;
        int isZero = 0;
        for (int &val : arr) {
            isZero += val == 0 ? 1 : 0;
            mul *= val == 0 ? 1 : val;
        }
        if (isZero > 1) return res;
        if (isZero) {
            for (int i = 0; i < n; i ++) {
                if (arr[i] == 0) {
                    res[i] = mul;
                }
            }
            return res;
        }
        for (int i = 0; i < n; i ++) {
            res[i] = mul / arr[i];
        }
        return res;
    }
        
    // TC : O(N)
    // SC : O(1)
    vector<int> approach_2(vector<int>& arr) {
        int n = arr.size();
        vector<int> res(n, 1); 

        int leftProduct = 1;
        for (int i = 0; i < n; i++) {
            res[i] *= leftProduct;  
            leftProduct *= arr[i]; 
        }

        int rightProduct = 1;
        for (int i = n - 1; i >= 0; i--) {
            res[i] *= rightProduct;  
            rightProduct *= arr[i];  
        }
        return res;
    }
  public:
    vector<int> productExceptSelf(vector<int>& arr) {
        // return approach_1(arr);  // brute
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
        getline(cin, input);
        stringstream ss(input);
        int number;

        while (ss >> number) {
            arr.push_back(number);
        }

        Solution obj;
        vector<int> res = obj.productExceptSelf(arr);

        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }
        cout << endl;
        cout << "~\n";
    }

    return 0;
}
// } Driver Code Ends