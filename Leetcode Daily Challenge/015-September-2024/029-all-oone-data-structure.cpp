// https://leetcode.com/problems/all-oone-data-structure/




#include <bits/stdc++.h>
using namespace std;

// TC : O(1)
// SC : O(N)
class AllOne {
public:
    struct Node {
        int count;
        unordered_set<string> keys;
        Node *next, *prev;
        Node(int c) : count(c), prev(NULL), next(NULL) {}
    };

    unordered_map<string, Node*> mpp;
    Node* head; // head -> next will give the min key string
    Node* last; // tracks the max key string

    AllOne() {
        head = new Node(0);
        last = head;
    }

    // Creating a new Node next to the prevNode
    void createNodeAfter(Node* prevNode, int count) {
        Node* newNode = new Node(count);
        newNode -> next = prevNode -> next;
        newNode -> prev = prevNode;
        if (prevNode -> next) {
            prevNode -> next -> prev = newNode;
        }
        prevNode -> next = newNode;

        if (last == prevNode) {
            last = newNode;
        }
    }

    // Removing the current Node
    void removeNode(Node* currNode) {
        currNode -> prev -> next = currNode -> next;
        if (currNode -> next) {
            currNode -> next -> prev = currNode -> prev;
        }
        if (last == currNode) {
            last = currNode -> prev;
        }
        delete currNode;
    }
    
    void inc(string key) {
        if (mpp.find(key) == mpp.end()) {
            // check head -> next is == 1 otherwise create a new node
            if (!head -> next || head -> next -> count != 1) {
                createNodeAfter(head, 1);    // creating a new node after head with freq = 1
            }
            head -> next -> keys.insert(key);   // insert key into newly created node
            mpp[key] = head -> next;            // store the address of newly created node
        } else {
            // key already exists in map then get the address 
            // then remove from the current address and move it to new address with +1 freq if exists otherwise create it
            Node* currNode = mpp[key];
            int currCount  = currNode -> count;
            if (!currNode -> next || currNode -> next -> count != currCount + 1) {
                createNodeAfter(currNode, currCount + 1);    // creating a new node after currNode with freq current count + 1
            }   
            
            currNode -> next -> keys.insert(key);   // move the key to the +1 freq node
            mpp[key] = currNode -> next;            // store new address of key into map
            currNode -> keys.erase(key);            // erase this key from prev freq node

            if (currNode -> keys.empty()) { // decrementing freq by 1 of key makes the set empty
                removeNode(currNode);
            }
        }
    }
    
    void dec(string key) {
        Node* currNode = mpp[key];  // it is guarantee that key will be in map
        int currCount  = currNode -> count;
       
        if (currCount == 1) {   // removing this node makes the count = 0
            mpp.erase(key);
        } else {
            // if there's not exists a prev node with current count - 1 then create a new node and erase the entry of key from the curr node
            if (currNode -> prev -> count != currCount - 1) {
                createNodeAfter(currNode -> prev, currCount - 1);
            }
            
            // else already there's a node with current count - 1
            currNode -> prev -> keys.insert(key);
            mpp[key] = currNode -> prev;
        }

        currNode -> keys.erase(key);

        if (currNode -> keys.empty()) {
            removeNode(currNode);
        }
    }
    
    string getMaxKey() {
        if (last == head) { // no node is available
            return "";
        }
        return *(last -> keys.begin());
    }
    
    string getMinKey() {
        if (!head -> next) {
            return "";
        }
        return *(head -> next -> keys.begin());
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */