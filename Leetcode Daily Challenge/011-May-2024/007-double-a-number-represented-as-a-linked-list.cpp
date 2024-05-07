// https://leetcode.com/problems/double-a-number-represented-as-a-linked-list/



#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
private:
    // TC : O(N)
    // SC : O(N) -> Recursive Depth
    int doubleRec(ListNode* head) {
        if (!head) return 0;

        int carry   = doubleRec(head -> next);
        int value   = (head -> val) * 2 + carry;
        head -> val = value % 10;

        return value / 10;
    }

    // TC : O(N)
    // SC : O(N) -> Recursive Depth
    ListNode* reverseIterative(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(curr) {
            ListNode* fowd = curr -> next;
            curr -> next   = prev;
            prev           = curr;
            curr           = fowd;
        }
        return prev;
    }

    // TC : O(N)
    // SC : O(N) -> Recursive Depth
    ListNode* reverseRec(ListNode* head) {
        if (!head || !head -> next) return head;

        ListNode* nextNode = reverseRec(head -> next);
        head -> next -> next = head;
        head -> next         = NULL;
        return nextNode;
    }

    // TC : O(N)
    // SC : O(1) + O(N) to return ans 
    vector<int> multiply(vector<int>& v){
        vector<int> ans;
        reverse(v.begin(), v.end());
        int carry = 0;
        for(int i=0;i<v.size();i++){
            int sum = carry + (v[i]*2);
            ans.push_back(sum%10);
            carry = sum/10;
        }
        if(carry != 0) ans.push_back(carry);
        return ans;
    }

    // TC : O(N) Where N = No. of Nodes
    // SC : O(N)
    ListNode* approach_1(ListNode* head) {
        if(head -> val == 0) {
            return new ListNode(0);
        }
        
        ListNode* temp = head;
        vector<int> store;
        while(temp != NULL) {
            store.push_back(temp->val);
            temp = temp -> next;
        }

        vector<int>newStore = multiply(store);

        ListNode* dummy = new ListNode(0);
        ListNode* nodeToInsert = dummy;
        
        for(int i = newStore.size()-1; i >= 0; i--) {
            nodeToInsert -> next = new ListNode(newStore[i]);
            nodeToInsert = nodeToInsert -> next;
        }
        
        return dummy -> next;
    }

    // TC : O(N)
    // SC : O(1)
    ListNode* approach_2(ListNode* head) {
        head = reverseIterative(head);

        ListNode* curr = head;
        ListNode* prev = NULL;
        int carry      = 0;

        while(curr) {
            int value   = (2 * curr -> val) + carry;
            curr -> val = value % 10;
            carry       = value / 10;
            prev        = curr;
            curr        = curr -> next;
        }
        
        if (carry > 0) {
            prev -> next = new ListNode(carry);
        }

        // head = reverseIterative(head);
        head = reverseRec(head);

        return head;
    }

    // TC : O(N)
    // SC : O(N)
    ListNode* approach_3(ListNode* head) {
        stack<ListNode*> stk;
        ListNode* curr = head;
        
        while (curr) {
            stk.push(curr);
            curr = curr -> next;
        }

        int carry = 0;
        while (!stk.empty()) {
            curr = stk.top();
            stk.pop();

            int value   = (2 * curr -> val) + carry;

            curr -> val = value % 10;
            carry       = value / 10;
        }

        if (carry > 0) {
            ListNode* newHead = new ListNode(carry);
            newHead -> next   = head;
            return newHead;
        }
        return head;
    }

    // TC : O(N)
    // SC : O(1)
    ListNode* approach_4(ListNode* head) {
        int nextNodeCarry = doubleRec(head);
        if (nextNodeCarry) {
            ListNode* newHead = new ListNode(nextNodeCarry);
            newHead -> next   = head;
            return newHead;
        }
        return head;
    }

    // TC : O(N)
    // SC : O(1)
    ListNode* approach_5(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = NULL;

        while (curr) {
            int value = curr -> val * 2;

            if (value < 10) {
                curr -> val = value;
            } else if (prev == NULL) {  // prev == NULL && value >= 10 : 1-Node => 8
                ListNode* newHead = new ListNode(value / 10);
                newHead -> next   = curr;
                curr -> val       = value % 10;
                head              = newHead;
            } else {    // prev != NULL && value >= 10
                prev -> val += 1;
                curr -> val  = value % 10;
            }

            prev = curr;
            curr = curr -> next;
        }
        return head;
    }

    // TC : O(N)
    // SC : O(1)
    ListNode* approach_6(ListNode* head) {
        if (head -> val >= 5) {
            // ListNode* newHead = new ListNode(0);
            // newHead -> next   = head;
            // head              = newHead;
            head = new ListNode(0, head);   // single liner instead of above 3-lines
        }

        ListNode* curr = head;

        while(curr) {
            curr -> val = (2 * curr -> val) % 10;

            if (curr -> next && curr -> next -> val >= 5) {
                curr -> val += 1;
            }

            curr = curr -> next;
        }
        return head;
    }
public:
    ListNode* doubleIt(ListNode* head) {
        // return approach_1(head);     // Naive : store and multiply

        // return approach_2(head);     // Reverse LL & Operate

        // return approach_3(head);     // Using Stack

        // return approach_4(head);     // Using Recursion

        // return approach_5(head);     // No Reverse : L ---> R Traversal

        return approach_6(head);     // No Reverse : L ---> R Traversal, 
                                        // Check if nextNode -> val >= 5 then add +1 to curr node
    }
};