// https://www.geeksforgeeks.org/problems/search-pattern-z-algorithm--141631/1



//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution
{
    private:
        // TC : O(N * M) Where 'N' is the size of the text and 'M' is the size of the pattern
        // SC : O(N) Where 'N' is the size of text
        vector<int> solve_brute(string& pat, string& txt) {
            vector<int> ans;
            for (int i = 0; i < txt.size(); i++) {
                if (txt.substr(i, pat.length()) == pat) {
                    ans.push_back(i + 1);
                }
            }
            return ans;
        }
        
        // TC : O(Quadratic) M^2 Where M is the length of concatenated new_string 
        // SC : O(N + M) Where 'N' is the size of text
        vector<int> z_brute(string& pat, string& txt) {
            vector<int> z;
            string new_str = pat + "#" + txt;
            int len    = new_str.length();
            int i      = 0;
            
            while (i < len) {
                if (i <= pat.length()) z.push_back(0);
                else {
                    int left  = 0, right = 0;
                    if (new_str[left] == new_str[i]) {
                        right = i;
                        
                        while (new_str[left] == new_str[right] && right < len) {
                            left ++;
                            right++;
                        }
                    }
                    z.push_back(left);
                }
                i++;
            }
            
            vector<int> result;
            for (int i = 0; i < len; i++) {
                if (z[i] == pat.length()) {
                    result.push_back(i - pat.length());
                }   
            }
            return result;
        }
        
        // TC : O(N + M)
        // SC : O(N + M)
        // OPTIMAL APPROACH
        vector<int> z_function(string& pat, string& txt) {
            string new_str = pat + "#" + txt;
            int len = new_str.length();
            
            vector<int> z(len, 0);
            
            for (int i = 1, l = 0, r = 0; i < len; i++) {
                if (i <= r) {
                    z[i] = min(r - i + 1, z[i - l]);
                }
                
                while (i + z[i] < len && new_str[z[i]] == new_str[i + z[i]])
                    z[i]++;
                    
                if (i + z[i] - 1 > r) {
                    l = i;
                    r = i + z[i] - 1; 
                }
            }
            
            vector<int> result;
            for (int i = 0; i < len; i++) {
                if (z[i] == pat.length()) {
                    result.push_back(i - pat.length());
                }   
            }
            return result;
        }

    public:
        vector <int> search(string pat, string txt)
        {
            // return solve_brute(pat, txt);
            
            // return z_brute(pat, txt);
            
            return z_function(pat, txt);
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
        if(res.size()==0)
            cout<<"-1 ";
        else
            for (int i : res)
                cout << i << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends