// https://leetcode.com/problems/minimum-number-of-moves-to-seat-everyone/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N*log(N))
    // SC : O(1)
    int approach_1(vector<int>& seats, vector<int>& students) {
        int n = students.size();
        sort(begin(seats), end(seats));
        sort(begin(students), end(students));
        int ans = 0;
        for (int i = 0; i < n; i ++) {
            ans += abs(seats[i] - students[i]);
        }
        return ans;
    }

    // TC : O(N + K) Where N = Size of Seats or Students array
    // SC : O(N + K) Where K = max|seats[i], students[i]|
    int approach_2(vector<int>& seats, vector<int>& students) {
        int n = students.size();
        vector<int> seating(101, 0);
        vector<int> studentPos(101, 0);
        for (int i = 0; i < n; i ++) {
            seating[seats[i]] ++;
            studentPos[students[i]] ++;
        }

        int idx = 0;
        for (int i = 0; i < seating.size(); i ++) {
            int count = seating[i];
            while(count --) {
                seats[idx ++] = i;
            }
        }
        idx = 0;
        for (int i = 0; i < studentPos.size(); i ++) {
            int count = studentPos[i];
            while(count --) {
                students[idx ++] = i;
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += abs(seats[i] - students[i]);
        }
        return ans;
    }

    // TC : O(N) Where N = Size of Seats or Students array
    // SC : O(K) Where K = max|seats[i], students[i]|
    int approach_3(vector<int>& seats, vector<int>& students) {
        int n = students.size();
        vector<int> seatingPos(101, 0);
        vector<int> studentPos(101, 0);
        for (int i = 0; i < n; i ++) {
            seatingPos[seats[i]] ++;
            studentPos[students[i]] ++;
        }

        int ans = 0, i = 0, j = 0;
        while (i < 101 && j < 101) {    // OR :  n > 0
            if (seatingPos[i] == 0) i ++;
            if (studentPos[j] == 0) j ++;

            if (i < 101 && j < 101 && seatingPos[i] != 0 && studentPos[j] != 0) {
                ans += abs(i - j);
                seatingPos[i] --;
                studentPos[j] --;

                // OR do this
                // n --;   // one student got their respective seat
            }
        }
        return ans;
    }
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        // return approach_1(seats, students);

        // return approach_2(seats, students); // COUNTING SORT

        return approach_3(seats, students); // COUNTING SORT : Writting Style Different
    }
};