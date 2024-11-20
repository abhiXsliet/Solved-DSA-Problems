// https://www.geeksforgeeks.org/problems/majority-vote/1



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  public:
    // Function to find the majority elements in the array
    vector<int> findMajority(vector<int>& nums) {
        int n = nums.size();
        
        int cnt1 = 0, cnt2 = 0;
        int ele1 =-1, ele2 =-1;
        
        for (int i = 0; i < n; i ++) {
            if      (ele1 == nums[i]) cnt1 ++;
            else if (ele2 == nums[i]) cnt2 ++;
            else if (cnt1 == 0) {
                ele1 = nums[i];
                cnt1 = 1;
            } else if (cnt2 == 0) {
                ele2 = nums[i];
                cnt2 = 1;
            } 
            else {  // catch
                cnt1 --;
                cnt2 --;
            }
        }
        
        vector<int> result;

        cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < n; i ++) {
            if (ele1 == nums[i]) cnt1 ++;
            if (ele2 == nums[i]) cnt2 ++;
        }
        
        if (cnt1 >= n/3 + 1) result.push_back(ele1);
        if (cnt2 >= n/3 + 1) result.push_back(ele2);
        sort(begin(result), end(result));
        return result;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        vector<int> ans = ob.findMajority(nums);
        if (ans.empty()) {
            cout << "[]";
        } else {
            for (auto &i : ans)
                cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends