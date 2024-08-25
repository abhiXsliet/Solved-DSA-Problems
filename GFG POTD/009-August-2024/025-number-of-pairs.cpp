// https://www.geeksforgeeks.org/problems/number-of-pairs-1587115620/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  public:
    long long countPairs(vector<int> &arr, vector<int> &brr) {
        long long ans=0;
        
        sort(begin(arr), end(arr));
        sort(begin(brr), end(brr));
        
        for (auto i : arr){
            if (i != 1){ // do not consider 1 in arr
                ans += end(brr) - lower_bound(begin(brr), end(brr), i+1);
            } 
        }
        
        for (auto i : brr){
            if (i == 1){ // consider all bigger elements in arr
                ans += end(arr) - lower_bound(begin(arr), end(arr), i+1);
            } 
            else break;
        }
        
        //Special Cases
        ans += count(begin(arr), end(arr),3) * count(begin(brr), end(brr), 2);
        ans -= count(begin(arr), end(arr),2) * count(begin(brr), end(brr), 3);
        ans -= count(begin(arr), end(arr),2) * count(begin(brr), end(brr), 4);
        return ans;   
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        vector<int> ex;
        vector<int> a, b;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            ex.push_back(num);
        a = ex;
        getline(cin, input);
        ss.clear();
        ss.str(input);
        int num2;
        while (ss >> num2)
            b.push_back(num2);

        Solution ob;
        cout << ob.countPairs(a, b) << endl;
    }
}
// } Driver Code Ends