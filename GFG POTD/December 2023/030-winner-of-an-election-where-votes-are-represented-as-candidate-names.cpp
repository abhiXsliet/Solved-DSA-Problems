// https://www.geeksforgeeks.org/problems/winner-of-an-election-where-votes-are-represented-as-candidate-names-1587115621/1



//{ Driver Code Starts
#include <iostream>
#include <map>
#include <algorithm>
#include <cstdlib>
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{
  private:
    // TC : O(N*log(N))
    // SC : O(1)
    vector<string> solve_approach_1(string arr[], int n) {
        vector<string> result;
        
        sort(arr, arr+n);
        
        string maxCandidate = arr[0];
        int maxVotes = 0;
        string currentCandidate = arr[0];
        int currentVotes = 0;
        
        for (int i = 0; i < n; i++) {
            if (arr[i] == currentCandidate) {
                currentVotes++;
                if (currentVotes > maxVotes) {
                    maxVotes = currentVotes;
                    maxCandidate = currentCandidate;
                }
            } else {
                currentCandidate = arr[i];
                currentVotes = 1;
            }
        }
        
        result.push_back(maxCandidate);
        result.push_back(to_string(maxVotes));
        
        return result;
    }
    
    // TC : O(N)
    // SC : O(N)
    vector<string> solve_approach_2(string arr[], int n) {
        vector<string> result;
        map<string, int> mpp;
        
        for (int i = 0; i < n; i++) {
            mpp[arr[i]]++;
        }
        
        int maxVote = 0;
        string candidate;
        
        for (auto it : mpp) {
            if (maxVote < it.second) {
                maxVote = it.second;
                candidate = it.first;
            }
        }
        
        result.push_back(candidate);
        result.push_back(to_string(maxVote));
        
        return result;
    }
  public:
    //Function to return the name of candidate that received maximum votes.
    vector<string> winner(string arr[], int n)
    {
        // return solve_approach_1(arr, n);
        
        return solve_approach_2(arr, n);
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    
    for(int i=0;i<t;i++)
    {
        
        
        int n;
        cin>>n;
        
        string arr[n];
        
        for (int i=0;i<n;i++)
        cin>>arr[i];
        Solution obj;
        vector<string> result = obj.winner(arr,n);
        
        cout<<result[0] << " " << result[1] << endl;
    }
    return 0;
}

// } Driver Code Ends