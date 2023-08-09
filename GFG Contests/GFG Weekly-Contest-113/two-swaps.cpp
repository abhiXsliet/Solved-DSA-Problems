// https://practice.geeksforgeeks.org/contest/gfg-weekly-coding-contest-113/problems


//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    int findIdx(vector<int>& A, int k) {
        int idx = -1;
        for(int i = 0; i < A.size(); i++) {
            if(A[i] == k) {
                idx = i;
            }
        }
        return idx;
    }
public: 
    bool checkSorted(int N, vector<int> A)
    {
        if(N == 1) return 0;
        auto V = A;
        sort(V.begin(), V.end());
        
        int cnt = 0; // to maintain the count of number of swaps
        for(int i = 0; i < N; i++) {
            if(A[i] != V[i]) {
                
                if(cnt < 2) {
                    swap(A[i], A[findIdx(A, V[i])]);
                    cnt++;
                } else {
                    cnt = -1;
                    break;
                }
            }
        }
        if(cnt == -1 || cnt == 1) 
            return 0;
            
        return 1;
    }   
};




//{ Driver Code Starts.
int main() 
{
    
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;

        vector<int> A(N);
        for(int i = 0; i < N; i++)
            cin >> A[i];

        Solution ob;
        if(ob.checkSorted(N, A))
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
    
    return 0;
}  
// } Driver Code Ends