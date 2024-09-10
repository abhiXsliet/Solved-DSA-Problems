// https://leetcode.com/problems/insert-greatest-common-divisors-in-linked-list/




#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
private:
    int gcd(int a, int b){

        if(a == 0)
            return b;

        if(b == 0)
            return a;

        while (a != b)
        {
            if( a > b){
                a = a - b;
            }else {
                b = b - a;
            }
        }
        return a;
    }

    int GCD(int a, int b) {
        if (a == 0) return b;
        if (b == 0) return a;
        return GCD(b % a, a);
    }

    // TC : O(N)
    // SC : O(N)
    ListNode* brute(ListNode* head) {
        vector<int> l;
        ListNode* temp = head;
        while(temp != NULL) {
            l.push_back(temp -> val);
            temp = temp -> next;
        }
        
        vector<int>gcdVal;
        int idx1 = 0, idx2 = 1;
        while(idx2 < l.size()) {
            int val = gcd(l[idx1], l[idx2]);
            gcdVal.push_back( val );
            idx1++;
            idx2++;
        }

        ListNode* curr = head -> next;
        ListNode* prev = head;
        int index = 0;
        while(curr != NULL) {
            ListNode* nodeToInsert = new ListNode(gcdVal[index]);
            prev -> next = nodeToInsert;
            nodeToInsert -> next = curr;
            prev = curr;
            curr = curr -> next;
            index++;
        }
        
        return head;
    }

    // TC : O(N)
    // SC : O(1)
    ListNode* optimal_1(ListNode* head) {
        ListNode* prev = head;
        ListNode* curr = head -> next;

        while (curr) {
            int gcdVal = GCD(prev -> val, curr -> val);
            ListNode* temp = new ListNode(gcdVal);
            prev -> next = temp;
            temp -> next = curr;
            prev = curr;
            curr = curr -> next;
        }

        return head;
    }

    // TC : O(N)
    // SC : Recursive Stack Space O(N) 
    ListNode* optimal_2(ListNode* head) {
        if (!head || !head -> next) 
            return head;

        ListNode* temp = optimal_2(head -> next);

        // Get GCD of nodes
        int gcdVal = GCD(head -> val, head -> next -> val);

        ListNode* newNode = new ListNode(gcdVal);
        newNode -> next   = temp;
        head    -> next   = newNode;

        return head;
    }
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        // return brute(head);

        // return optimal_1(head);

        return optimal_2(head);  // Recursive Approach
    }
};