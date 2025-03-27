// https://www.geeksforgeeks.org/problems/minimum-platforms-1587115620/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  private:
    // TC : O(N*log(N))
    // SC : O(N)
    int approach_1(vector<int> &arr, vector<int> &dep) {
        int n = arr.size();
        
        sort(begin(arr), end(arr));
        sort(begin(dep), end(dep));
        
        auto cmp = [&] (vector<int> a, vector<int> b) {
            return a[1] >= b[1];
        };
        
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> pq(cmp);

        int minPlatform = 0;
        for (int i = 0; i < n; i ++) {
            while (!pq.empty() && pq.top()[1] < arr[i]) {
                pq.pop();
            }
            pq.push({arr[i], dep[i]});
            minPlatform = max(minPlatform, (int)pq.size());
        }
        return minPlatform;
    }
    
    // TC : O(N*log(N))
    // SC : O(N)
    int approach_2(vector<int> &arr, vector<int> &dep) {
        int n = arr.size();
        
        sort(begin(arr), end(arr));
        sort(begin(dep), end(dep));
        
        int minPlatform = 0, platform = 0;
        int i = 0, j = 0;
        while (i < n) {
            if (arr[i] <= dep[j]) {
                platform += 1;
                i ++;
            } else {
                platform --;
                j ++;
            }
            minPlatform = max(minPlatform, platform);
        }
        return minPlatform;
    }
  public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        // return approach_1(arr, dep);
        return approach_2(arr, dep);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr, dep;
        string input;

        // Read first array (arr)
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        // Read second array (dep)
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            dep.push_back(number);
        }

        // Assuming Solution class is defined elsewhere with a method findPlatform
        Solution ob;
        cout << ob.findPlatform(arr, dep);

        cout << endl;
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends