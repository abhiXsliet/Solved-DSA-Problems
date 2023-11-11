// https://www.geeksforgeeks.org/problems/isomorphic-strings-1587115620/1


//{ Driver Code Starts
// C++ program to check if two strings are isomorphic


#include<bits/stdc++.h>


using namespace std;
#define MAX_CHARS 256

// } Driver Code Ends
class Solution
{
    private:
    // TC = O(n1 + n2)
    // SC = O(Number of different characters) ~ O(1)
    bool solve_approch_1_code_1(string& s1, string& s2, int n1, int n2) {
        if (n1 != n2) return false;
        
        unordered_map<char, char> mpp(26);
        vector<int> vis(26, -1);
        
        for (int i = 0; i < n1; i++) {
            if (mpp.find(s1[i]) != mpp.end()) {
                // check if s1[i] is in relation with s2[i] only otherwise return false
                if (mpp[s1[i]] != s2[i]) 
                    return false;
            }
            else {
                if (vis[s2[i] - 'a'] != -1) 
                    return false;
                else {
                    // relate s1[i] with s2[i] 
                    // and mark s2[i] as 1 sice s2[i] gets hooked with s1[i]
                    mpp[s1[i]] = s2[i];
                    vis[s2[i] - 'a'] = 1;
                }
            }
        }
        
        return true;
    }
    
    // TC = O(N)
    // SC = O(Number of distinct char) ~ O(1)
    bool solve_approch_1_code_2(string& s1, string& s2, int n, int m) {
        if (n != m) return false;
        
        unordered_map<char, char> mpp(26);
        unordered_map<char,  int> vis(26);
        
        for (int i = 0; i < n; i++) {
            // if s1[i] is not mapped then map it with s2[i]
            if (mpp.find(s1[i]) == mpp.end()) {
                // check s2[i] is not visited previously 
                // then map it with s1[i] and mark vis[s2[i]] = true
                if (vis.find(s2[i]) == vis.end()) {
                    mpp[s1[i]] = s2[i];
                    vis[s2[i]] = 1;
                }
                // if s2[i] is visited already then return false
                else if (vis[s2[i]] == 1) {
                    return false;
                }
            }
            // if s1[i] is already mapped with someone
            // then check and if it is mapped with same s2[i] otherwise return false
            else if (mpp[s1[i]] != s2[i]) {
                return false;
            }
        }
        
        return true;
    }
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string str1, string str2)
    {
        // return solve_approch_1_code_1(str1, str2, str1.length(), str2.length());
        
        return solve_approch_1_code_2(str1, str2, str1.length(), str2.length());
    }
};

//{ Driver Code Starts.

// Driver program
int main()
{
    int t;
    cin>>t;
    string s1,s2;
    while (t--) {
        cin>>s1;
        cin>>s2;
        Solution obj;
        cout<<obj.areIsomorphic(s1,s2)<<endl;
    }
    
    return 0;
}
// } Driver Code Ends