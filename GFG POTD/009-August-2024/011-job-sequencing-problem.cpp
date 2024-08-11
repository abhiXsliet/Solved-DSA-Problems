// https://www.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1




//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/
class Solution {
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        auto cmp = [&](Job j1, Job j2) {
            return j1.profit > j2.profit;  
        };
        sort(arr, arr + n, cmp);
        
        int maxDeadLine = 0;
        for (int i = 0; i < n; i ++) {
            maxDeadLine = max(maxDeadLine, arr[i].dead);
        }
        
        vector<int> scheduleJobs(maxDeadLine + 1, 0);
        
        int maxProfit = 0;
        int cntOfJobs = 0;
        
        for (int i = 0; i < n; i ++) {
            int currId     = arr[i].id;
            int currDead   = arr[i].dead;
            int currProfit = arr[i].profit;
            
            for (int j = currDead; j > 0; j --) {
                if (scheduleJobs[j] == 0) {
                    cntOfJobs += 1;
                    scheduleJobs[j] = currId;
                    maxProfit += currProfit;
                    break;
                }
            }
        }
    
        return {cntOfJobs, maxProfit};
    } 
};


//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}
// } Driver Code Ends