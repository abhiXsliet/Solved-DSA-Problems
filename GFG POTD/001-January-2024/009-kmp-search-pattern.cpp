// https://www.geeksforgeeks.org/problems/search-pattern0205/1




//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution
{
    private:
        // TC : O(N)
        // SC : O(N)
        vector<int> prefixStore(string s) {
            int n = s.length();
            vector<int> prefix_idx(n, 0);
            
            for (int i = 1; i < n; i++) {
                int j = prefix_idx[i - 1];
                
                while (j > 0 && s[i] != s[j]) {
                    j = prefix_idx[j - 1];
                }
                
                if (s[i] == s[j]) j ++;
                prefix_idx[i] = j;
            }
            return prefix_idx;
        }
    public:
        // TC : O(N + M)
        // SC : O(N)
        vector<int>search(string pat, string txt)
        {
            vector<int> prefix = prefixStore(pat);
            
            vector<int> result;
            int i = 0, j = 0;
            
            while (i < txt.size()) {
                if (txt[i] == pat[j]) {
                    i++, j++;
                }
                else {
                    if (j != 0) {
                        j = prefix[j - 1];
                    }
                    else {
                        i ++;
                    }
                }
                
                if (j == pat.size()) {
                    result.push_back(i - j + 1);
                    j = prefix[j - 1];
                }
            }
            
            return result;
        }
     
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        if (res.size()==0)
            cout<<-1<<endl;
        else {
            for (int i : res) cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}
// } Driver Code Ends