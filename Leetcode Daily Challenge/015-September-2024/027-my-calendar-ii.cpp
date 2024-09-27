// https://leetcode.com/problems/my-calendar-ii/




#include <bits/stdc++.h>
using namespace std;

// TC : O(N^2), Where N = No. of times MyCalendarTwo gets called. 
//              Each call iterates over up to N previous bookings to check for overlaps.

// SC : O(N), where N is the total number of intervals stored in the vectors after N bookings.
class MyCalendarTwo {
public:
    typedef pair<int, int> P;

    vector<P> doubleBookings;   // Overlapping region
    vector<P> singleBookings;   // No overlapping region

    MyCalendarTwo() {}

    bool isOverlapping(int a1, int b1, int a2, int b2) {
        return max(a1, a2) < min(b1, b2);
    }

    P getOverlappingRegion(int a1, int b1, int a2, int b2) {
        return {max(a1, a2), min(b1, b2)};
    }
    
    bool book(int start, int end) {
        // Check if {start, end} conflict with the doubleBookings
        for (P &booking : doubleBookings) {
            if (isOverlapping(booking.first, booking.second, start, end)) {
                return false;
            }
        }

        // Get the common booking region if overlapping, insert it into doubleBookings
        for (P &booking : singleBookings) {
            if (isOverlapping(booking.first, booking.second, start, end)) {
                doubleBookings.push_back({getOverlappingRegion(booking.first, booking.second, start, end)});
            }
        }

        // If not a doulbe booking then it must goes into singleBooking
        singleBookings.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */