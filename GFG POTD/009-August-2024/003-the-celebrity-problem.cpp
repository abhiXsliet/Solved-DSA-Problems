// https://www.geeksforgeeks.org/problems/the-celebrity-problem/1




//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

// User function template for C++
class Solution {
  private:
    // TC : O(N^2)
    // SC : O(1)
    int brute(vector<vector<int>>& mat) {
        int n = mat.size();
        
        int celeb = -1;
        
        for (int i = 0; i < n; i ++) {
            bool isCeleb = 1;
            for (int j = 0; j < n; j ++) {
                if (i == j) continue;
                if (mat[i][j] == 1) {
                    isCeleb = 0;
                    break;
                }
            }
            
            if (isCeleb) {
                for (int j = 0; j < n; j ++) {
                    if (i == j) continue;
                    if (mat[j][i] == 0) {
                        isCeleb = 0;
                        break;
                    } 
                }
            }
            
            if (isCeleb) {
                celeb = i;
                break;
            }
        }
        
        return celeb;
    }
    
    // TC : O(N)
    // SC : O(N)
    int optimal(vector<vector<int>>& mat) {
        int n = mat.size();
        
        queue<int> q;
        for (int i = 0; i < n; i ++) 
            q.push(i);
            
        auto isKnows = [&](int A, int B) {
            return mat[A][B];  
        };
        
        int celeb = -1;
        
        while (q.size() >= 1) {
            if (q.size() == 1) {
                celeb = q.front(); 
                break;
            }
            int personA = q.front(); q.pop();
            int personB = 0;
            if (!q.empty()) {
                personB = q.front();
                q.pop();
            }
            if (isKnows(personA, personB)) {    // A knows B : A can't be celeb
                q.push(personB);
            } else {
                q.push(personA);
            }
        }
        
        // check row & col of celeb is completely 0 & 1 respectively
        for (int i = 0; i < n; i ++) {
            if (celeb != i && (mat[celeb][i] || mat[i][celeb] == 0)) {
                celeb = -1;
                break;
            }
        }
        
        return celeb;
    }
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int>>& mat) {
        // return brute(mat);
        
        return optimal(mat);    // persons : 0, 1, 2, ..., n
                                // check two persons only (A, B) : if A knows B, A can't be celebrity => put B in ds
                                //                               : if B knows A, B can't be celebrity => put A in ds
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int> > M(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> M[i][j];
            }
        }
        Solution ob;
        cout << ob.celebrity(M) << endl;
    }
}
// } Driver Code Ends