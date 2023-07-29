// https://practice.geeksforgeeks.org/problems/find-nth-element-of-spiral-matrix/1



//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

// } Driver Code Ends

class Solution
{
    public:
    /*You are required to complete this method*/
    int findK(int a[MAX][MAX],int n,int m,int k)
    {
 		int stRow = 0;
 		int stCol = 0;
 		int endRow = n-1;
 		int endCol = m - 1;
 		int ans;

 		while(k > 0) {
 		    //starting row
     		for(int i = stCol; i <= endCol; i++) {
     		   if(k) {
     		       ans = a[stRow][i]; k--;
     		   } else break;
     		}
     		stRow++;
     		
     		//ending col
     		for(int i = stRow; i <= endRow; i++) {
     		   if(k) {
     		       ans = a[i][endCol]; k--;
     		   } else break;
     		}
     		endCol--;
     		
     		//ending row
     		for(int i = endCol; i >= stCol; i--) {
     		   if(k) {
     		       ans = a[endRow][i]; k--;
     		   } else break;
     		}
     		endRow--;
     		
     		//starting col
     		for(int i = endRow; i >= stRow; i--) {
     		   if(k) {
     		       ans = a[i][stCol]; k--;
     		   } else break;
     		}
     		stCol++ ; 		    
 		}
        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        int a[MAX][MAX];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }
        Solution ob;
        cout<<ob.findK(a,n,m,k)<<endl;
        
       
    }
}
// } Driver Code Ends