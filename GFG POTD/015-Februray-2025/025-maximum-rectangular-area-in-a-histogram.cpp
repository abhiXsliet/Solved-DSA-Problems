// https://www.geeksforgeeks.org/problems/maximum-rectangular-area-in-a-histogram-1587115620/1




//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  private:
    vector<int> nextSmallerElement(vector<int>& arr, int n) {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);
        for(int i=n-1; i>=0; i--) {
            int curr = arr[i];
            while((s.top() != -1) && (arr[s.top()] >= curr)) {
                s.pop();
            }
            //ans is stack top
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }

    vector<int> prevSmallerElement(vector<int>& arr, int n) {
        stack<int> s;
        s.push(-1);
        vector<int>ans(n);

        for(int i=0; i<n; i++) {
            int curr = arr[i];
            while((s.top() != -1) && (arr[s.top()] >= curr)) {
                s.pop();
            }

            //ans is top of stack
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
  public:
    int getMaxArea(vector<int> &heights) {
        int n = heights.size();

        vector<int> next(n);
        next = nextSmallerElement(heights, n);

        vector<int> prev(n);
        prev = prevSmallerElement(heights, n);

        int area = INT_MIN;
        for(int i=0; i<n; i++)
        {
            int l = heights[i];            
            if(next[i] == -1) next[i] = n;
            int b = next[i] - prev[i] - 1;
            int newArea = l*b;
            area = max(area, newArea);
        }
        return area;
    }
};

//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
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
        int res = obj.getMaxArea(arr);
        cout << res << endl;
        cout << "~" << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}
// } Driver Code Ends