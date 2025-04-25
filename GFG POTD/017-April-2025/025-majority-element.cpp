// https://www.geeksforgeeks.org/problems/majority-element-1587115620/1




//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // TC : O(N)
    // SC : O(1)
    int majorityElement(vector<int>& arr) {
        int n = arr.size();
        int cnt = 0, ele = -1;
        for (int &num : arr) {
            if (ele == num) {
                cnt ++;
            } else {
                if (cnt == 0) {
                    cnt = 1;
                    ele = num;
                    continue;
                }
                cnt --;
            }
        }
        cnt = 0;
        for (int &num : arr) {
            if (num == ele) {
                cnt ++;
            }
        }
        return (cnt > n/2) ? ele : -1;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n;
        vector<int> a, b;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.majorityElement(a) << endl;
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends