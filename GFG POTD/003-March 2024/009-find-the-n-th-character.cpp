// https://www.geeksforgeeks.org/problems/find-the-n-th-character5925/1



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends
//User function template for C++

class Solution{
  private:
    // TC : O(r * N) where N = s.length()
    // SC : O(N)
    char solve_approach_1(string s, int r, int n) {
        for (int i = 0; i < r; i++) {
            string t = "";
            for (int i = 0; i < s.length(); i++) {
                if (s[i] == '0') t += "01";
                else t += "10";
                
                if (t.size() > s.size())
                    break;
            }
            s = t;
        }
        return s[n];
    }

    // TC : O(r * N) where N = s.length()
    // SC : O(N)
    char solve_approach_2(string s, int r, int n) {
        list<char> list(s.begin(), s.end());
        for(int p = 0; p < r; p++) {
            for(auto it = list.begin(); it != list.end(); it++) {
                if(*it == '0')
                    it = list.insert(++it, '1');
                else 
                    it = list.insert(++it, '0');
                
                if(distance(list.begin(), it) > n) 
                    break;
            }
        }
        auto it = list.begin();
        advance(it, n);
        return *it;
    }
  public:
    char nthCharacter(string s, int r, int n) {
        // return solve_approach_1(s, r, n);
        
        return solve_approach_2(s, r, n);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, N;
        string S;
        cin >> S >> R >> N;
        Solution ob;
        cout << ob.nthCharacter(S, R, N) << endl;
    }
    return 0;
}
// } Driver Code Ends