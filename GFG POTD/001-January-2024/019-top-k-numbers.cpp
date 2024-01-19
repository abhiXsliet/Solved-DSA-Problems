// https://www.geeksforgeeks.org/problems/top-k-numbers3425/1



//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  private:
    // TC : O(N * K)
    // SC : O(N) + O(K)
    vector<vector<int>> solve_approach_1(vector<int>& arr, int n, int k) {
        vector<vector<int>> result;
        vector<int> store(k+1, 0);
        unordered_map<int, int> mpp;
        
        for (int i = 0; i < n; i++) {
            mpp[arr[i]]++;
            store[k] = arr[i];
            
            auto it = find(begin(store), end(store), arr[i]);
            int idx = it - begin(store) - 1;
            
            for (int j = idx; j >= 0; j--) {
                
                if (mpp[store[j]] < mpp[store[j + 1]]) {
                    swap(store[j], store[j + 1]);
                }
                else if ((mpp[store[j]] == mpp[store[j + 1]]) && (store[j] > store[j + 1])){
                    swap(store[j], store[j + 1]);
                }
                else break;
            }
            
            vector<int> temp;
            for (int j = 0; j < k && store[j] != 0; j++) {
                temp.push_back(store[j]);
            }
            
            result.push_back(temp);
        }
        
        return result;
    }
  public:
    vector<vector<int>> kTop(vector<int>& arr, int N, int K) {
        return solve_approach_1(arr, N, K);
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int K;
        scanf("%d",&K);
        
        
        vector<int> a(N);
        Array::input(a,N);
        
        Solution obj;
        vector<vector<int>> res = obj.kTop(a, N, K);
        
        for(auto it:res)
            Array::print(it);
        
    }
}

// } Driver Code Ends