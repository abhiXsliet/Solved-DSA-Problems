// https://practice.geeksforgeeks.org/problems/rotate-bits4524/1



//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
        vector <int> rotate (int n, int d)
        {   
            // to store the binary of n
            vector<int> store(26);
            
            d = d % 16; // e.g., 18 % 16 = 2 or looping 18-times gives index = 2
            
            for (int i = 0; i < 16; i++) {
                store[i] = (n & 1) == 1 ? 1 : 0;
                n  /= 2;
            }
            
            int left  = (16 - d) % 16;
            int right = d;  // no need to do mod again since above d = d%16
            
            int l = 0, r = 0, i = 0;
            
            while (i < 16) { // iterate over 16-bits
                if (store[left] == 1)
                    l += 1 << i;
                    
                if (store[right] == 1)
                    r += 1 << i;
                    
                left  = (left + 1)  % 16;
                right = (right + 1) % 16;
                
                i++;
            }   
            
            vector<int> result;
            result.push_back(l);
            result.push_back(r);
            
            return result;
        }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        
        int n, d; cin >> n >> d;
        Solution ob;
        vector <int> res = ob.rotate (n, d);
        cout << res[0] << endl << res[1] << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends