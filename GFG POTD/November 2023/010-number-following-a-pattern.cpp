// https://www.geeksforgeeks.org/problems/number-following-a-pattern3126/1


//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
private:
    // TC = O(N)
    // SC = O(N)
    string solve_brute(string str, int n) {
        string ans(n+1, ' ');
        int cnt = 1;
        for (int i = 0; i <= n; i++) {
            if (i == n || str[i] == 'I') {
                for (int j = i - 1; j >= -1; j--) {
                    ans[j + 1] = char('0' + cnt);
                    cnt++;
                    
                    if (j >= 0 && str[j] == 'I')
                        break;
                }
            }
        }
        return ans;
    }
    
    // TC = O(N)
    // SC = O(N)
    string solve_better(string str, int n) {
        string ans = "";
        stack<int> stk;
        for (int i = 0; i <= n; i++) {
            stk.push(i + 1);
            if (i == n || str[i] == 'I') {
                while(!stk.empty()) {
                    ans += to_string(stk.top());
                    stk.pop();
                }
            }
        }
        return ans;
    }
public:
    string printMinNumberForPattern(string S){
        // return solve_brute(S, S.length());
        
        return solve_better(S, S.length());
    }
};


//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.printMinNumberForPattern(S) << endl;
    }
    return 0; 
} 

// } Driver Code Ends