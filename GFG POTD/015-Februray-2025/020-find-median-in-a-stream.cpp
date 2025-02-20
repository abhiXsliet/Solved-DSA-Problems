// https://www.geeksforgeeks.org/problems/find-median-in-a-stream-1587115620/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  private:
    // TC : O(log(N))
    // SC : O(log(N))
    void heapInsertion(priority_queue<int>& maxHeap, priority_queue<int, vector<int>, greater<>>& minHeap, int element) {
        if (maxHeap.empty() || element < maxHeap.top()) {
            maxHeap.push(element);
        } else {
            minHeap.push(element);
        }
        
        if (maxHeap.size() > minHeap.size() + 1) {  // max-heap size should always be only +1 greater than min-heap not more than that
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if (maxHeap.size() < minHeap.size()) {   // max-heap size should always be +1 more or equal compared to min-heap
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double getMedian(priority_queue<int>& maxHeap, priority_queue<int, vector<int>, greater<>>& minHeap) {
        // even : if both heap has the same no. of elements, so median will be at summation of both minHeap and maxHeap top()
        if (maxHeap.size() == minHeap.size()) {
            double mean = (maxHeap.top() + minHeap.top()) / 2.0;
            return mean;
        }
        // odd : if the heap size is different, so median will be at top of maxHeap
        return (double) maxHeap.top();
    }
  public:
    /*
        1. Use a max-heap to store the left half of the elements.
        2. Use a min-heap to store the right half of the elements.
        3. Always ensures that max-heap(left) size always equals to minHeap(right) or max-heap size is always one more than the right one 
        4. The median is either the root of the max-heap (if sizes are unequal) or the average of the roots of both heaps (if sizes are equal).
    */
    // TC : O(N*log(N))
    // SC : O(N)
    vector<double> getMedian(vector<int> &arr) {
        int n = arr.size();
        priority_queue<int> maxHeap;    // left heap
        priority_queue<int, vector<int>, greater<>> minHeap;    // right heap
        
        vector<double> result;
        
        for (int i = 0; i < n; i ++) {
            heapInsertion(maxHeap, minHeap, arr[i]);
            double val = getMedian(maxHeap, minHeap);
            
            result.push_back(val);
        }
        
        return result;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        vector<double> ans = ob.getMedian(nums);
        cout << fixed << setprecision(1);
        for (auto &i : ans)
            cout << i << " ";
        cout << "\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends