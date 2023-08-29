// https://practice.geeksforgeeks.org/problems/student-record1752/1?



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    string studentRecord(vector<vector<string>> S, int N) {
        string ans = "";
        vector<string> name;
        int average = INT_MIN;
        for(int i = 0; i < N; i++) {
            
           int marks1 = stoi(S[i][1]);
           int marks2 = stoi(S[i][2]);
           int marks3 = stoi(S[i][3]);
           
            int total = (marks1 + marks2 + marks3) / 3;
            
            if(total > average) {
                average = max(total, average);
                name.clear();
                name.push_back(S[i][0]);
            }
            else if(total == average) {
                name.push_back(S[i][0]);
            }
        }
        
        for(string n : name) {
            ans += n += " ";
        }
        
        ans += to_string(average);
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;

        string a,b,c,d;
        
        vector<vector<string>> S(N);
        
        for(int i=0; i<N; i++)
        {
            cin>>a>>b>>c>>d;
            S[i].push_back(a);
            S[i].push_back(b);
            S[i].push_back(c);
            S[i].push_back(d);
        }
        
        Solution ob;
        cout << ob.studentRecord(S,N) << endl;
    }
    return 0;
}
// } Driver Code Ends