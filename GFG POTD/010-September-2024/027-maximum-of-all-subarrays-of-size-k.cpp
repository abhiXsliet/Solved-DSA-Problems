// https://www.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1




//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

// User function template for C++
class Solution {
  public:
    // TC : O(N)
    // SC : O(K)
    // Function to find maximum of each subarray of size k.
    vector<int> max_of_subarrays(int k, vector<int> &arr) {
        int n = arr.size();
        list<int> li;
        vector<int> result;
        int i = 0, j = 0;
        while (j < n) {
            while (!li.empty() && li.back() < arr[j]) {
                li.pop_back();
            }
            
            li.push_back(arr[j]);
            
            if (j - i + 1 > k) {
                if (li.front() == arr[i]) {
                    li.pop_front();
                }
                i ++;
            }
            
            if (j - i + 1 == k) {
                result.push_back(li.front());
            }
            
            j ++;
        }
        return result;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();

    while (t--) {

        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        vector<int> res = obj.max_of_subarrays(k, arr);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}
// } Driver Code Ends