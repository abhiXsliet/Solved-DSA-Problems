// https://leetcode.com/problems/my-calendar-i/




#include <bits/stdc++.h>
using namespace std;

// -------------------------------- BRUTE -----------------------------------------------------------------------------

// Time Complexity: O(N^2), Where N is the number of times MyCalendar is called. 
//                          Each call requires iterating over up to N previously booked intervals.

// Space Complexity: O(N), Where N is the number of entries stored in the vector after N successful bookings.
class MyCalendar {
public:
    vector<pair<int, int>> vec;
    MyCalendar() {}
    
    bool book(int start, int end) {
        for (auto& interval : vec) {
            int st = interval.first;
            int en = interval.second;
            // If there's an overlap, return false
            if (!(end <= st || start >= en)) {  // OR  (end > st && start < en)
                return false;
            }
        }
        // If no overlap, add the interval
        vec.push_back({start, end});
        return true;
    }
};


// --------------------------------------- OPTIMAL ------------------------------------------------------------------------

// TC : O(N * log(N)) Where N = No. of times MyCalendar gets called and O(log(N)) for searching in set for each call
// SC : O(N)
class MyCalendar {
public:
    set<pair<int, int>> st;
    MyCalendar() {}
    
    bool book(int start, int end) {
        auto it = st.lower_bound({start, end});

        // Find the first event which starts just after {start, end}
        if (it != st.end() && it -> first < end) 
            return false;

        // In case next element is not available then get the previous
        if (it != st.begin()) { // single element : no prev iterator
            auto prevIt = prev(it);
            if (prevIt -> second > start) {
                return false;
            }
        }

        st.insert({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */