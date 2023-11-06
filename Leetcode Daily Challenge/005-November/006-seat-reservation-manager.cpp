// https://leetcode.com/problems/seat-reservation-manager/


#include <bits/stdc++.h>
using namespace std;

// ---------------- Approach - 1 : Brute Force ----------------------------------------------------------------
// T.C : O(m * n) , where m = number of calls and n = time taken to reserve
// S.C : O(n)

class SeatManager {
public:
    vector<int> seats;
    int N;
    SeatManager(int n) {
        N = n;
        seats.resize(n+1, -1); // unreserved seats
    }
    
    // O(m * n) where m = no. of times reserve() gets called
    //                n = traversal of for loop
    int reserve() {
        for (int i = 1; i < N+1; i++) {
            if (seats[i] == -1) {
                seats[i] = 1;   // seat reserved 
                return i;
            }
        }

        return -1;
    }
    
    void unreserve(int seatNumber) {
        seats[seatNumber] = -1; // unreserved
    }
};


// ----------------- Approach - 2 : Better than brute force ----------------------------------------------------
// T.C : O((m+n) * logn) Reduced the time taken by reserve()
// S.C : O(n)

class SeatManager {
public:
    priority_queue<int, vector<int>, greater<int>> pq;  // minheap
    SeatManager(int n) {
        for (int i = 1; i <= n; i++) {  // O(n)
            pq.push(i);         // O(log(n))
        }
    }
    
    int reserve() {
        int seat = pq.top();
        pq.pop();
        return seat;
    }
    
    void unreserve(int seatNumber) {
        pq.push(seatNumber);
    }
};


// ----------------------- Optimal Approach ------------------------------------------------------
// Avoiding pre-initialising of heap
// T.C : O(m* log(n)) , where m = number of reserve() calls
// S.C : O(n)

class SeatManager {
public:
    priority_queue<int, vector<int>, greater<int>> pq;  // minHeap
    int seat_marker;
    SeatManager(int n) {
        seat_marker = 1;
    }
    
    int reserve() {
        while(!pq.empty()) {
            int seat = pq.top();
            pq.pop();
            return seat;
        }

        int seat = seat_marker;
        seat_marker++;
        return seat;
    }
    
    void unreserve(int seatNumber) {
        pq.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */