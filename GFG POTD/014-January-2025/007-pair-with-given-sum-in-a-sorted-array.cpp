// https://www.geeksforgeeks.org/problems/pair-with-given-sum-in-a-sorted-array4940/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  public:
    // TC : O(N)
    // SC : O(1)
    int countPairs(vector<int> &arr, int target) {
        int n = arr.size();
        int i = 0, j = n - 1;
        int pairs = 0;
        while (i < j) {
            int sum = arr[i] + arr[j];
            if (sum == target) {
                if (arr[i] == arr[j]) {
                    int cnt = j - i + 1;
                    pairs += (cnt * (cnt - 1)) / 2;
                    break;
                } else {
                    int lSkip = 1, rSkip = 1;
                    while (i < j && arr[i] == arr[i + 1]) {
                        lSkip ++;
                        i ++;
                    }
                    while (i < j && arr[j] == arr[j - 1]) {
                        rSkip ++;
                        j --;
                    }
                    pairs += (lSkip * rSkip);
                    i ++, j --;
                }
            } else if (sum > target) j --;
            else i ++;
        }
        return pairs;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        int target;
        string input;
        getline(cin, input);

        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        cin >> target;
        cin.ignore();
        Solution obj;
        cout << obj.countPairs(arr, target) << endl;
        cout << "~\n";
    }

    return 0;
}
// } Driver Code Ends