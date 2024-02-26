// https://www.geeksforgeeks.org/problems/play-with-or5515/1



//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


int* game_with_number(int arr[], int n);

int main()
{
    
    int t;cin>> t;
    while(t--)
    {
        int n;
        cin >> n;
        int arr[n];
        
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        int *arr2;
        
        arr2 = game_with_number(arr, n);
        for(int i = 0;i < n; i++)
            cout << arr2[i] << " ";
        
        cout << endl;
        
    }

}

// } Driver Code Ends

// TC : O(N)
// SC : O(N)
int* solve_1(int arr[], int n) {
    int* ans = new int[n];
    for (int i = 0; i < n - 1; i++) {
        ans[i] = (arr[i] | arr[i + 1]);
    }
    ans[n - 1] = arr[n - 1];
    return ans;
}

// TC : O(N)
// SC : O(1)
int* solve_2(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        arr[i] = (arr[i] | arr[i + 1]);
    }
    return arr;
}
int* game_with_number(int arr[], int n)
{
    // return solve_1(arr, n);
    
    return solve_2(arr, n);
}
