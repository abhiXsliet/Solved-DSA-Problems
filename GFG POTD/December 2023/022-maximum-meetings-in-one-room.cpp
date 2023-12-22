// https://www.geeksforgeeks.org/problems/maximum-meetings-in-one-room/1



//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends
//User function Template for C++

class Solution{
private:
    static bool cmp(pair<int, pair<int, int>>& a, pair<int, pair<int, int>>& b) {
        return a.second.second < b.second.second;
    }
public:
    // TC : O(N*log(N))
    // SC : O(N)
    vector<int> maxMeetings(int N,vector<int> &S,vector<int> &F){
        vector<pair<int, pair<int, int>>> meetings; // {index, {start_time, end_time}}
        
        for (int i = 0; i < N; i++) {
            meetings.push_back({i, {S[i], F[i]}});
        }

        // sort meeting a/c to finishing time
        sort(begin(meetings), end(meetings), cmp);
        
        vector<int> result;
        result.push_back(meetings[0].first + 1);
        
        int finishTime = meetings[0].second.second;
        
        for (int i = 1; i < N; i++) {
            int startTime = meetings[i].second.first;
            
            if (startTime > finishTime) {
                finishTime = meetings[i].second.second;
                result.push_back(meetings[i].first + 1);
            }
        }
        
        sort(begin(result), end(result));
        return result;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> S(n),F(n);
        for(int i=0;i<n;i++){
            cin>>S[i];
        }
        for(int i=0;i<n;i++){
            cin>>F[i];
        }
        Solution ob;
        vector<int> ans=ob.maxMeetings(n,S,F);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i];
            if(i!=ans.size()-1){
                cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends