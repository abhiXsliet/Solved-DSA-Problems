// https://www.geeksforgeeks.org/problems/three-way-partitioning/1



//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
private:
    // TC : O(N)
    // SC : O(1)
    void approach_2(vector<int>& arr, int a, int b) {
        int n    = arr.size();
        int left = 0, right = n - 1;
        
        for (int i = 0; i <= right; i++) {
            if (arr[i] < a) {
                swap(arr[i], arr[left]);
                left ++;
            }
            else if (arr[i] > b) {
                swap(arr[i], arr[right]);
                
                right --;
                i --;
            }
        }
    }
    
    // TC : O(N)
    // SC : O(1)
    // Intution -> DNF Sort
    // (similar as sort 0, 1, 2)
    void approach_3(vector<int>& array, int a, int b) {
        int n    = array.size();
        int low  = 0;
        int mid  = 0; 
        int high = n - 1;
        
        while (mid <= high) {
            if (array[mid] < a) { // == 0 (sort 0, 1, 2)
                swap(array[mid++], array[low++]);
            }
            else if (array[mid] >= a && array[mid] <= b) { // in range [a, b] inclusive 
                mid++;                                    // == 1 in sort(0, 1, 2)
            }
            else if (array[mid] > b) { // > b              // == 2 in sort(0, 1, 2)
                swap(array[mid], array[high--]);
            }
        }

    }
public:
    //Function to partition the array around the range such 
    //that array is divided into three parts.
    void threeWayPartition(vector<int>& arr,int a, int b)
    {
        // sort(begin(arr), end(arr));
        
        // approach_2(arr, a, b);
        
        approach_3(arr, a, b);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        
        vector<int> array(N);
        unordered_map<int,int> ump;
        
        for(int i=0;i<N;i++){
            cin>>array[i];
            ump[array[i]]++;
        }
        
        int a,b;
        cin>>a>>b;
        
        vector<int> original = array;

        int k1=0,k2=0,k3=0;
        int kk1=0;int kk2=0;int kk3=0;
        
        for(int i=0; i<N; i++)
        {
            if(original[i]>b)
                k3++;
            else if(original[i]<=b and original[i]>=a)
                k2++;
            else if(original[i]<b)
                k1++;
        }
        
        Solution ob;
        ob.threeWayPartition(array,a,b);
      
        for(int i=0;i<k1;i++)
        {
            if(array[i]<b)
            kk1++;
        }
        
        for(int i=k1;i<k1+k2;i++)
        {
            if(array[i]<=b and array[i]>=a)
            kk2++;
            
        }
        
        for(int i=k1+k2;i<k1+k2+k3;i++)
        {
            if(array[i]>b)
            kk3++;
        }
        bool ok = 0;
        if(k1==kk1 and k2 ==kk2 and k3 == kk3)
            ok = 1;
        
        for(int i=0;i<array.size();i++)
            ump[array[i]]--;
        
        for(int i=0;i<array.size();i++)
            if(ump[array[i]]!=0)
                ok=0;
        
        if(ok)
            cout<<1<<endl;
        else
            cout<<0<<endl;
        
    }
    
    return 0;
}
// } Driver Code Ends