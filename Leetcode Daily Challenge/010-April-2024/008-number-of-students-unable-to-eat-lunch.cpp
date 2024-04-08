// https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/



#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // TC : O(N) Where N = No. of Students
    // SC : O(N) At max no student able to eat
    int solve_1(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q;
        for (int& student : students) {
            q.push(student);
        }

        int i = 0;
        int times = 0;
        while(!q.empty()) {
            int frontStudent = q.front();
            q.pop();
            
            if (i < sandwiches.size() && frontStudent == sandwiches[i]) {
                i ++;
                times = 0;
            }
            else {
                q.push(frontStudent);
                times ++;
            }

            if (times == q.size()) {
                break;
            }
        }

        return q.size();
    }

    // TC : O(M + N) 
    // SC : O(1) 
    int solve_2(vector<int>& students, vector<int>& sandwiches) {
        int student_1 = 0;  // student who likes circular sandwiches
        int student_0 = 0;  // student who likes rectangular sandwiches

        for (int& student : students) {
            if (student == 0) student_0 ++;
            else student_1 ++;
        }

        for (int& sandwich : sandwiches) {
            if (sandwich == 0) {
                if (student_0 > 0)  
                    student_0 --;
                else 
                    return student_1;
            }
            else {
                if (student_1 > 0)
                    student_1 --;
                else 
                    return student_0;
            }
        }

        return max(student_0, student_1);
    }

    // TC : O(M + N)
    // SC : O(1)
    int solve_2_better(vector<int>& students, vector<int>& sandwiches) {
        // arr[0] & arr[1] : students who likes circular and rectangular sandwiches
        vector<int> arr(2, 0);

        for (int &student : students) {
            arr[student] ++;
        }

        int n = sandwiches.size();
        for (int i = 0; i < n; i++) {
            if (arr[sandwiches[i]] == 0) {
                return n - i;
            }

            arr[sandwiches[i]] --;
        }

        return 0;
    }
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        // return solve_1(students, sandwiches);    // SIMULATION

        // return solve_2(students, sandwiches);

        return solve_2_better(students, sandwiches);
    }
};