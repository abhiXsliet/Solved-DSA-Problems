// https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    void sort012(int a[], int n)
    {
        int low = 0, mid = 0, high = n - 1;
        while(mid <= high) {
            if (a[mid] == 0) {
                swap(a[mid], a[low]);
                low++;
                mid++;
            }
            else if (a[mid] == 1) {
                mid++;
            }
            else {
                swap(a[high], a[mid]);
                high--;
            }
        }
    }
    
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}


// } Driver Code Ends