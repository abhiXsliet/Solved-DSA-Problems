// https://www.geeksforgeeks.org/problems/find-h-index--165609/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

// User function Template for C++
class Solution {
  private:
    bool isPossibleHIdx(vector<int>& citations, int tar) {
        int count = 0;
        for (int i = 0; i < citations.size(); i ++) {
            if (citations[i] >= tar) {
                count ++;
            }
        }
        return count >= tar;
    }
    
    // TC : O(N*log(N))
    // SC : O(1)
    int approach_1(vector<int>& citations) {
        int n = citations.size();
        sort(begin(citations), end(citations));
        int low = 0, high = *max_element(begin(citations), end(citations));
        int ans = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isPossibleHIdx(citations, mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
    
    // TC : O(N)
    // SC : O(N)
    int approach_2(vector<int>& citations) {
        int n = citations.size();
        vector<int> countCitations(n + 1, 0);    // h-index could be only 0 to n
        for (int i = 0; i < n; i ++) {
            if (citations[i] < n) {
                countCitations[citations[i]] ++;
            } else {
                countCitations[n] ++;
            }
        }
        int hIdx = -1;
        int suffixSum = 0;
        for (int i = n; i >= 0; i --) { // citations from 0...n 
            if (countCitations[i] + suffixSum >= i) {
                hIdx = i;
                break;
            }
            suffixSum += countCitations[i];
        }
        return hIdx;
    }
  public:
    // Function to find hIndex
    int hIndex(vector<int>& citations) {
        // return approach_1(citations);    // BS
        return approach_2(citations);    // max-hIdx could be n: so, the countCitations array
    }
};


//{ Driver Code Starts.
int main() {

    int test_cases;
    cin >> test_cases;
    cin.ignore();
    while (test_cases--) {
        string input;
        vector<int> arr;

        // Read the array from input line
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        // Solution instance to invoke the function
        Solution ob;
        int result = ob.hIndex(arr);

        cout << result << endl;

        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends