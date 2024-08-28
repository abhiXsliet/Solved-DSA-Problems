// https://www.geeksforgeeks.org/problems/sorting-elements-of-an-array-by-frequency-1587115621/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  public:
    // TC : O(N*log(N))
    // SC : O(N)
    // Function to sort the array according to frequency of elements.
    vector<int> sortByFreq(vector<int>& arr) {
        int n = arr.size();
        
        unordered_map<int, int> freq;
        for (int& num : arr) {
            freq[num] ++;
        }
        
        auto cmp = [&](int a, int b) {
            if (freq[a] == freq[b])
                return a < b;
            return freq[a] > freq[b];  
        };
        
        sort(begin(arr), end(arr), cmp);
        return arr;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution obj;
        vector<int> v;
        v = obj.sortByFreq(arr);
        for (int i : v)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}
// } Driver Code Ends