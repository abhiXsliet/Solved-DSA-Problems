// https://www.geeksforgeeks.org/problems/minimum-sum4058/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

// User function template for C++
class Solution {
  private:
    string summation(string &s1, string &s2) {
        int m = s1.length(), n = s2.length();
        int i = m - 1, j = n - 1;
        int carry = 0;
        string res;
        while (i >= 0 || j >= 0 || carry) {
            int val = carry;
            
            if (i >= 0) {
                val += (s1[i] - '0');
                i --;
            }
            
            if (j >= 0) {
                val += (s2[j] - '0');
                j --;
            }
            
            res  += to_string(val % 10);
            carry = val / 10;
        }
        reverse(begin(res), end(res));
        return res;
    }
  public:
    // TC : O(N * log(N)) Where N = array size
    // SC : O(N)
    string minSum(vector<int> &arr) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int &num : arr) {
            pq.push(num);
        }
        
        string first, second;
        while (!pq.empty()) {
            first += to_string(pq.top());
            pq.pop();
            
            if (pq.empty()) break;
            
            second += to_string(pq.top());
            pq.pop();
        }
        
        string res = summation(first, second);
        res.erase(0, res.find_first_not_of('0'));
        return res;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;
        string ans = ob.minSum(a);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends