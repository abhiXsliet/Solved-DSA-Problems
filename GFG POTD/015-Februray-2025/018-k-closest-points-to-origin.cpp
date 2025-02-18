// https://www.geeksforgeeks.org/problems/k-closest-points-to-origin--172242/1




//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  private:
    typedef pair<int, pair<int, int>> P;
    
    int getEuclideanDist(int x, int y) {
        return sqrt(x*x + y*y);
    }
    
    // TC : O(N*log(N))
    // SC : O(N)
    vector<vector<int>> approach_1(vector<vector<int>>& points, int k) {
        priority_queue<P, vector<P>, greater<>> pq; 
        for (vector<int>& point : points) {
            int eucliDist = getEuclideanDist(point[0], point[1]);
            pq.push({eucliDist, {point[0], point[1]}});
        }
        
        vector<vector<int>> result;
        while (!pq.empty() && k --) {
            P it = pq.top();
            pq.pop();
            
            result.push_back({it.second.first, it.second.second});
        }
        return result;
    }
    
    // TC : O(N*log(K))
    // SC : O(K)
    vector<vector<int>> approach_2(vector<vector<int>>& points, int k) {
        priority_queue<P> pq; 
        for (vector<int>& point : points) {
            int eucliDist = getEuclideanDist(point[0], point[1]);
            if (pq.size() >= k) {
                if (pq.top().first > eucliDist) {
                    pq.pop();
                    pq.push({eucliDist, {point[0], point[1]}});
                }
            } else {
                pq.push({eucliDist, {point[0], point[1]}});
            }
        }
        
        vector<vector<int>> result;
        while (!pq.empty() && k --) {
            P it = pq.top();
            pq.pop();
            result.push_back({it.second.first, it.second.second});
        }
        return result;
    }
  public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // return approach_1(points, k);
        return approach_2(points, k);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        int n;
        cin >> n;
        vector<vector<int>> points(n, vector<int>(2));
        for (int i = 0; i < n; i++) {
            cin >> points[i][0] >> points[i][1];
        }
        Solution ob;
        vector<vector<int>> ans = ob.kClosest(points, k);
        sort(ans.begin(), ans.end());
        for (const vector<int>& point : ans) {
            cout << point[0] << " " << point[1] << endl;
        }
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends