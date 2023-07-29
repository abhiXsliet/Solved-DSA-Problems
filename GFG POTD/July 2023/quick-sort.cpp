// https://practice.geeksforgeeks.org/problems/quick-sort/1


//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// } Driver Code Ends

class Solution
{
    public:
    //Function to sort an array using quick sort algorithm.
    int partation(int arr[], int s, int e) {
    
        int pivot = arr[s];
    
        int cnt = 0;
        for(int i=s+1; i<=e; i++) {
            if(arr[i] <= pivot) {
                cnt++;
            }
        }
    
        //place pivot at right position
        int pivotIndex = s + cnt;
        swap(arr[s], arr[pivotIndex]);
    
        //handle left and right part
        int i = s;
        int j = e;
    
        while(i < pivotIndex && j > pivotIndex) {
            while(arr[i] <= pivot) {
                i++;
            }
    
            while(arr[j] > pivot) {
                j--;
            }
    
            if(i < pivotIndex && j > pivotIndex) {
                swap(arr[i++], arr[j--]);
            }   
        } 
        return pivotIndex;
    }
    
    void quickSort(int arr[], int s, int e) {
        //base case
        if(s >= e) {
            return;
        }
        //create partation
        int p = partation(arr, s, e);
    
        //sort left of partation
        quickSort(arr, s, p-1);
        
        //sort right of partation
        quickSort(arr, p+1, e);
    }
};


//{ Driver Code Starts.
int main()
{
    int arr[1000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
      Solution ob;
    ob.quickSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends