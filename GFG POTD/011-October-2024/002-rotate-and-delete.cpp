// https://www.geeksforgeeks.org/problems/rotate-and-delete-1587115621/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  private:
    // TC : O(N^2)
    // SC : O(1)
    int naive(vector<int>& arr) {
        int k = 1;
        while (arr.size() > 1) {
            int temp = arr[arr.size() - 1];
            for (int i = arr.size() - 1; i > 0; i --) {   // Rotate
                arr[i] = arr[i - 1];
            }
            arr[0] = temp;
            
            if (k > arr.size()) {
                arr.erase(begin(arr) + 0);
            } else {
                arr.erase(begin(arr) + (arr.size() - k));
            }
            
            k ++;
        }
        return arr[0];
    }
    
    // TC : O(N^2)
    // SC : O(1)
    int better(vector<int>& arr) {
        int k = 1;
        while (arr.size() > 1) {
            // Rotate by 1
            int temp = arr.back();
            arr.pop_back();                 // O(1)
            arr.insert(begin(arr), temp);   // O(1)
            
            int eraseIdx = (arr.size() - k);
            if (eraseIdx < 0) {
                eraseIdx = 0;
            }
            
            arr.erase(begin(arr) + eraseIdx);
            k ++;
        }
        return arr[0];
    }
  public:
    int rotateDelete(vector<int> &arr) {
        // return naive(arr);
        
        return better(arr);
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
        int res = obj.rotateDelete(arr);
        cout << res << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}
// } Driver Code Ends