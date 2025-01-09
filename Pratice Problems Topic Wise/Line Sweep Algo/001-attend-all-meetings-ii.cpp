// https://www.geeksforgeeks.org/problems/attend-all-meetings-ii/1




//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
  private:
    // TC : O(N*log(N))
    // SC : O(N)
    int approach_1(vector<int>& start, vector<int>& end) {
        // minimum no. of meeting rooms would be the max cut in the range
        int n = start.size();
        vector<pair<int, char>> ranges;
        for (int i = 0; i < n; i ++) {
            ranges.push_back({start[i], 'S'});
            ranges.push_back({end[i], 'E'});
        }
        
        auto cmp = [&](pair<int, char>& p1, pair<int, char>& p2) {
            if (p1.first == p2.first) {
                return p1.second == 'E' && p2.second == 'S';
            }
            return p1.first < p2.first;
        };
        
        sort(ranges.begin(), ranges.end(), cmp);

        int track  = 0;
        int maxCut = 0;
        for (int i = 0; i < ranges.size(); i ++) {
            if (ranges[i].second == 'S') 
                track ++;
            else 
                track --;
            maxCut = max(maxCut, track);
        }
        return maxCut;
    }
    
    // TC : O(N*log(N))
    // SC : O(N)
    int approach_2(vector<int>& start, vector<int>& end) {
        int n = start.size();
        vector<pair<int, int>> ranges;
        for (int i = 0; i < n; i++) {
            ranges.push_back({start[i], end[i]});
        }
        // Sort the ranges based on their start times
        sort(ranges.begin(), ranges.end());
    
        int result = 0;
        priority_queue<int, vector<int>, greater<int>> minHeap; // Min-heap to track end times
    
        for (int i = 0; i < n; i++) {
            // Remove ranges from the heap that do not overlap with the current range
            while (!minHeap.empty() && minHeap.top() <= ranges[i].first) {
                minHeap.pop();
            }
            // Add the current range's end time to the heap
            minHeap.push(ranges[i].second);
            // Update the result with the maximum heap size
            result = max(result, (int)minHeap.size());
        }
    
        return result;
    }
  public:
    int minMeetingRooms(vector<int> &start, vector<int> &end) {
        // return approach_1(start, end);   // Line Sweep Algo
        return approach_2(start, end);      // using min-Heap
    }
};


//{ Driver Code Starts.
//Back-end complete function template in C++

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr, brr;
        string input1;
        getline(cin, input1);
        stringstream ss1(input1);
        int number1;
        while (ss1 >> number1) {
            arr.push_back(number1);
        }
        string input2;
        getline(cin, input2);
        stringstream ss2(input2);
        int number2;
        while (ss2 >> number2) {
            brr.push_back(number2);
        }
        Solution ob;
        int res = ob.minMeetingRooms(arr, brr);
        cout << res << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends