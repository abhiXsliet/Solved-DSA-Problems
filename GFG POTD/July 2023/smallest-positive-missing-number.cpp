// https://practice.geeksforgeeks.org/problems/smallest-positive-missing-number-1587115621/1



//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to find the smallest positive number missing from the array.
    int missingNumber(int arr[], int n) 
    {   
        // // TLE since the time complexity => O(n^2)
        // int j = 1; 
        // while(j <= n+1) {
        //     int i = 0;
        //     for(; i<n; i++) {
        //         if(arr[i] == j) break;
        //     }
        //     if(i == n) return j;
        //     j++;
        // }
        // return j;
        
        
        
        // // TC => O(N)
        // // SC => O(N)
        // set<int>st;
        // int num = 1;
        // for(int i=0; i<n; i++) {
        //     int ele = arr[i];
        //     st.insert(ele);
        // }
        // for(auto& i: st) {
        //     if(st.find(num) != st.end()) {
        //         num++;
        //     }
        // }
        // return num;
        
        
        // TC => O(N)
        // SC => O(1)
        //logic for swapping elements at its correct position
        for(int i=0; i<n; i++) {
            int element = arr[i];
            if(element > 0 && element <= n) {
                //checking if the swapped element is at its correct position
                if(arr[element-1] != element) {
                    swap(arr[element-1], arr[i]);
                    //to check the swapped position again
                    i--;
                }
            }
        }
        for(int i=0; i<n; i++) {
            if(i+1 != arr[i])
                return i+1;
        }
        return n+1;

    } 
};


//{ Driver Code Starts.

int missingNumber(int arr[], int n);

int main() { 
    
    //taking testcases
    int t;
    cin>>t;
    while(t--){
        
        //input number n
        int n;
        cin>>n;
        int arr[n];
        
        //adding elements to the array
        for(int i=0; i<n; i++)cin>>arr[i];
        
        Solution ob;
        //calling missingNumber()
        cout<<ob.missingNumber(arr, n)<<endl;
    }
    return 0; 
} 
// } Driver Code Ends