// ---------- May This New Year 2025 filled with Love❣️, Happiness😊, Health🧑‍⚕️, Wealth💶💵 and Prosperity🎉🎆 to everyone ----------


// https://www.geeksforgeeks.org/problems/print-anagrams-together/1



//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
// } Driver Code Ends

// User function Template for C++
class Solution {
  private:
    // TC : O(N * M*log(M) + N * M) = O(N * Mlog(M))
    // SC : O(N * M)
    vector<vector<string>> approach_1(vector<string>& arr) {
        unordered_map<string, vector<string>> mpp;
        for (string& word : arr) {
            string temp = word;
            sort(begin(temp), end(temp));
            mpp[temp].push_back(word);
        }
        
        vector<vector<string>> result;
        for (auto& it : mpp) {
            result.push_back(it.second);
        }
        return result;
    }
  public:
    vector<vector<string>> anagrams(vector<string>& arr) {
        return approach_1(arr);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        vector<string> arr;
        string input_line;
        getline(cin, input_line);
        stringstream ss(input_line);
        string word;
        while (ss >> word) {
            arr.push_back(word);
        }

        Solution ob;
        vector<vector<string> > result = ob.anagrams(arr);
        sort(result.begin(), result.end());
        for (int i = 0; i < result.size(); i++) {
            for (int j = 0; j < result[i].size(); j++) {
                cout << result[i][j] << " ";
            }
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends