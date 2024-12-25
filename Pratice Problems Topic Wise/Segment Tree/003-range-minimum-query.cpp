// https://www.geeksforgeeks.org/problems/range-minimum-query/1




//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int *constructST(int arr[],int n);


int RMQ(int st[] , int n, int a, int b);
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int A[N];
        for(int i=0;i<N;i++)
            cin>>A[i];
        int Q;
        cin>>Q;



        int *segTree = constructST(A,N);

        for(int i=0;i<Q;i++)
        {
            int start,e;
            
            cin>>start>>e;
            if(start>e)
            {
                swap(start,e);
            }
            cout<<RMQ(segTree,N,start,e)<<" ";
        }
        cout<<endl;
    
cout << "~" << "\n";
}
}

// } Driver Code Ends

// TC : O(N)
// SC : O(log(N)) Due to Recursive Stack
void buildSegTree(int segTree[], int arr[], int i, int l, int r) {
    if (l == r) {
        segTree[i] = arr[l];    // or segTree[i] = arr[r]
        return;
    }
    
    int mid = l + (r - l) / 2;
    buildSegTree(segTree, arr, 2*i+1, l, mid);
    buildSegTree(segTree, arr, 2*i+2, mid + 1, r);
    
    segTree[i] = min(segTree[2 * i + 1], segTree[2 * i + 2]);
}

// TC : O(log(N))
// SC : O(log(N)) Due to Recursive Stack
int querySegTree(int st[], int i, int l, int r, int startQ, int endQ) {
    if (r < startQ || l > endQ)  // out of bound
        return INT_MAX;

    if (l >= startQ && r <= endQ) // in-bound
        return st[i];
    
    int mid = l + (r - l) / 2;
    return min(querySegTree(st, 2*i+1, l,   mid, startQ, endQ), 
               querySegTree(st, 2*i+2, mid+1, r, startQ, endQ));
}

// TC : O(N)
// SC : O(N)
/* The functions which builds the segment tree */
int *constructST(int arr[],int n) {
    int *segTree = new int[4*n];
    buildSegTree(segTree, arr, 0, 0, n - 1);
    return segTree;
}

// TC : O(log(N))
// SC : O(1)
/* The functions returns the min element in the range from a and b */
int RMQ(int st[] , int n, int a, int b) {
    return querySegTree(st, 0, 0, n - 1, a, b);
}