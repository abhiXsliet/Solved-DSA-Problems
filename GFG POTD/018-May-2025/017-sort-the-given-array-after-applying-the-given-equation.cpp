// https://www.geeksforgeeks.org/problems/sort-the-given-array-after-applying-the-given-equation0304/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  private:
    int getUpdatedValue(int element, int A, int B, int C) {
        return (A*(element * element) + B*element + C);
    }
    
    // TC : O(N*log(N))
    // SC : O(1)
    vector<int> brute(vector<int> &arr, int A, int B, int C) {
        int n = arr.size();
        for (int i = 0; i < n; i ++) {
            arr[i] = getUpdatedValue(arr[i], A, B, C);
        }
        sort(begin(arr), end(arr));
        return arr;
    }

    // TC : O(N)
    // SC : O(N)
    vector<int> optimal(vector<int> &arr, int A, int B, int C) {
        int n = arr.size();
        vector<int> result(n, 0);
        
        int left = 0, right = n - 1;
        int idx = A >= 0 ? n - 1 : 0;
        while (left <= right) {
            int leftVal  = getUpdatedValue(arr[left] , A, B, C);
            int rightVal = getUpdatedValue(arr[right], A, B, C);
            if (A >= 0) {
                if (leftVal <= rightVal) {
                    result[idx --] = rightVal;
                    right --;
                } else {
                    result[idx --] = leftVal;
                    left ++;
                }
            } else {
                if (leftVal > rightVal) {
                    result[idx ++] = rightVal;
                    right --;
                } else {
                    result[idx ++] = leftVal;
                    left ++;
                }
            }
        }
        return result;
    }
  public:
    vector<int> sortArray(vector<int> &arr, int A, int B, int C) {
        // return brute(arr, A, B, C);
        return optimal(arr, A, B, C);   // ax^2 + bx + c represents parabola, [for a > 0 : Upward parabola] and [for a < 0 : DownWard Parabola]
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

        int a, b, c;
        cin >> a >> b >> c;
        cin.ignore();

        Solution obj;
        vector<int> ans = obj.sortArray(arr, a, b, c);
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << ' ';
        cout << endl;

        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends