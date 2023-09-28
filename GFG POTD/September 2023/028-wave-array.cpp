// https://practice.geeksforgeeks.org/problems/wave-array-1587115621/1


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
// #include <algorithm>


// } Driver Code Ends
class Solution{
    private:
    void solve_1(int n, vector<int>& arr) {
        int lastEle = arr[n - 1];
        
        for (int i = 0; i < n; i+=2) 
            swap(arr[i], arr[i+1]);
        
        if (arr.size() % 2 == 1) 
            arr[n - 1] = lastEle;
    }
    
    void solve_2(int n, vector<int>& arr) {
       for (int i = 0; i < n-1; i+=2) 
            swap(arr[i], arr[i+1]); 
    }
    public:
    // arr: input array
    // n: size of array
    //Function to sort the array into a wave-like array.
    void convertToWave(int n, vector<int>& arr){
        // solve_1(n, arr);
        solve_2(n, arr);
    }
};

//{ Driver Code Starts.

int main()
{
    int t,n;
    cin>>t; //Input testcases
    while(t--) //While testcases exist
    {
        cin>>n; //input size of array
        vector<int> a(n); //declare vector of size n
        for(int i=0;i<n;i++)
            cin>>a[i]; //input elements of array
        sort(a.begin(),a.end());
        Solution ob;
        ob.convertToWave(n, a);

        for(int i=0;i<n;i++)
            cout<<a[i]<<" "; //print array
            
        cout<<endl;
    }
}
// } Driver Code Ends