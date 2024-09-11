// https://www.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  public:
    // Function to return the minimum cost of connecting the ropes.
    long long minCost(vector<long long>& arr) {
        int n = arr.size();
        
        //step-1 : create a minHeap using priority queue
        priority_queue<long long, vector<long long>, greater<long long> > pq;
        
        //step-2 : push all elements into the priority queue
        for(int i=0; i<n; i++){
            pq.push(arr[i]);
        }
        
        //step-3 : calculate minimum cost
        long long cost = 0;
        
        while(pq.size() > 1){
            
            long long a = pq.top();
            pq.pop();
            
            long long b = pq.top();
            pq.pop();
            
            long long sum = a + b;
            
            cost += sum;
            
            pq.push(sum);
        }
        return cost;
    }
};

//{ Driver Code Starts.
int main() {
    long long t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        long long num;
        vector<long long> a;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }
        Solution ob;
        cout << ob.minCost(a) << endl;
    }
    return 0;
}
// } Driver Code Ends