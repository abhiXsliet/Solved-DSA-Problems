// https://www.geeksforgeeks.org/problems/the-celebrity-problem/1




#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:
    // TC : O(N^2)
    // SC : O(1)
    int approach_1(vector<vector<int>> &mat) {
        int n = mat.size();
        
        for (int i = 0; i < n; i ++) {
            bool isCeleb = true; // 'i' is a potential celeb.
            for (int j = 0; j < n; j ++) {
                if (i != j && mat[i][j]) {    // celeb knows no-one
                    isCeleb = false;
                    break;
                }
            }
            if (isCeleb) {  // everyone should know 'i'
                for (int j = 0; j < n; j ++) {
                    if (!mat[j][i]) {
                        isCeleb = false;
                        break;
                    }
                }
            }
            if (isCeleb) return i;
        }
        return -1;
    }
    

    /*
        - Push every persons into queue : 0, 1, 2, ..., n
        - check & process two persons only (A, B) : if A knows B, A can't be celebrity => put B in ds
                                                  : if B knows A, B can't be celebrity => put A in ds
    */    
    // TC : O(N)
    // SC : O(N)
    int approach_2(vector<vector<int>> &mat) {
        int n = mat.size();
        
        queue<int> q;
        for (int i = 0; i < n; i ++) {
            q.push(i);
        }
        
        auto isKnow = [&](int A, int B) {
            return mat[A][B];  
        };
        
        int celeb = -1;
        while (q.size() >= 1) {
            if (q.size() == 1) {
                celeb = q.front();
                q.pop();
                break;
            }
            
            int A = q.front(); q.pop();
            int B = q.front(); q.pop();
            
            if (isKnow(A, B)) {
                q.push(B);
            } else {
                q.push(A);
            }
        }
        
        // validate celeb
        for (int k = 0; k < n; k ++) {
            if (celeb != k && (!mat[k][celeb] || mat[celeb][k])) {
                celeb = -1;
                break;
            }
        }
        
        return celeb;
    }
    
    /*
        // --------------------------------- Two Pointer Approach ----------------------------------------
        1. Set two pointers: i = 0 and j = n - 1
        2. Eliminate non-celebrities:
           - If mat[i][j] == 1, increment i (i can't be the celebrity, since celebrity knows no one)
           - If mat[i][j] == 0, decrement j (j can't be the celebrity, since celebrity is known by everyone)
        3. Once the loop ends, i points to a potential celebrity
        4. Confirm i is the celebrity by validating its row and column
    */
    // TC : O(N)
    // SC : O(1)
    int approach_3(vector<vector<int>> &mat) {
        int n = mat.size();
        
        int i = 0, j = n - 1;
        while (i < j) {
            if (mat[i][j]) {
                i ++;
            } else {
                j --;
            }
        }
        
        // validate 'i' as potential celeb
        int celeb = i;
        
        for (int k = 0; k < n; k ++) {
            if (k != celeb && (mat[celeb][k] || !mat[k][celeb]))
                return -1;
        }
        return celeb;
    }
  public:
    int celebrity(vector<vector<int>>& mat) {
        // return approach_1(mat);  // brute
        // return approach_2(mat);  // better : using queue
        return approach_3(mat);
    }
};