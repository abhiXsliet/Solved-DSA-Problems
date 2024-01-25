// https://www.geeksforgeeks.org/problems/shortest-prime-path--141631/1



//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{  
private:
    // TC : O(log(log(N)))
    // SC : O(N) -> primes array size
    void sieve(vector<int>& primes, int n) {
        for (int i = 2; i*i < n; i++) {
            if (primes[i]) {
                for(int j = 2*i; j < n; j += i) {
                    primes[j] = 0;
                }
            }
        }
    }
    
    // TC : O(N)
    // SC : O(N)
    int solve_approach_1(int num1, int num2) {
        vector<int> primes(10000, 1);
        sieve(primes, 10000);
        
        unordered_set<int> st;
        for (int i = 1000; i < 10000; i++) {
            if (primes[i]) {
                st.insert(i);
            }
        }
        
        queue<pair<int, int>> q;
        q.push({0, num1});  // {distance, num1}

        while(!q.empty()) {
            int dist = q.front().first;
            int num  = q.front().second;
            q.pop();
            
            if (num == num2) return dist;
            
            string str = to_string(num);
            
            for (int i = 0; i < 4; i++) {
                
                for (int j = 0; j <= 9; j++) {
                    
                    char ch = str[i];
                    
                    str[i] = ('0' + j); // change values from 0 to 9
                    
                    int val = stoi(str);
                    
                    if (st.find(val) != st.end()) {
                        
                        st.erase(val);
                        
                        if (num2 == val) return dist + 1;
                        
                        q.push({dist+1, val});
                    }
                    
                    str[i] = ch;
                }
            }
        }
        
        return -1;
    }
public:
    int solve(int num1,int num2) {   
        return solve_approach_1(num1, num2);
    }
};


//{ Driver Code Starts.
signed main()
{
  int t;
  cin>>t;
  while(t--)
  {
      int num1,num2;
      cin>>num1>>num2;
      Solution obj;
      int answer=obj.solve(num1,num2);
      cout<<answer<<endl;
  }
}
// } Driver Code Ends