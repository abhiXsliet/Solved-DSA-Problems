// https://www.geeksforgeeks.org/problems/lru-cache/1



//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

/*
// ------------------------------ APPROACH - 1 : BRUTE FORCE ------------------------------
// TC : O(N^2)
// SC : O(N)
// design the class in the most optimal way
class LRUCache {
  public:
    vector<pair<int, int>> cache;
    int n;
    // Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap) {
        n  = cap;
    }

    // Function to return value corresponding to the key.
    int get(int key) {
        bool present = 0;
        int value = -1;
        for (int i = 0; i < cache.size(); i ++) {
            if (cache[i].first == key) {
                value = cache[i].second;
                present = 1;
                cache.erase(begin(cache) + i);
            }
        }
        if (present) {
            cache.push_back({key, value});
        }
        return value;
    }

    // Function for storing key-value pair.
    void put(int key, int value) {
        // check if the key is present then remove it to insert at the last
        for (int i = 0; i < cache.size(); i ++) {
            if (cache[i].first == key) {
                cache.erase(begin(cache) + i);
            }
        }
        if (cache.size() == n) 
            cache.erase(begin(cache) + 0);
        cache.push_back({key, value});
    }
};

*/

/*  

// ------------------------------ APPROACH - 2 : OPTIMAL ------------------------------
// TC : O(N)
// SC : O(N)
class LRUCache {
  public:
    list<int> dll;
    unordered_map<int, pair<list<int>::iterator, int>> cache; // {key, {Address, value}}
    int n;
    
    // Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap) {
        n = cap;
    }
    
    void makeRecentlyUsed(int key) {
        dll.erase(cache[key].first);  // remove the address
        dll.push_front(key);
        cache[key].first = dll.begin();
    }

    // Function to return value corresponding to the key.
    int get(int key) {
        if (cache.count(key)) {
            makeRecentlyUsed(key);
            return cache[key].second;
        }
        return -1;
    }

    // Function for storing key-value pair.
    void put(int key, int value) {
        if (cache.count(key)) {
            makeRecentlyUsed(key);
            cache[key].second = value;
        } else {
            dll.push_front(key);
            cache[key] = {dll.begin(), value};
            n --;
        }
        if (n < 0) {
            int keyToDelete = dll.back();
            cache.erase(keyToDelete);
            dll.pop_back();
            n ++;
        }
    }
};
*/

// ------------------------------ APPROACH - 3 : OPTIMAL ------------------------------
// TC : O(N)
// SC : O(capacity)
class LRUCache {
  public:
    struct Node {
        int key;
        int val;
        Node *next;
        Node *prev;
        Node(int k, int v) {
            this -> val = v;
            this -> key = k;
            prev     = NULL;
            next     = NULL;
        }
    };
    
    unordered_map<int, Node*> cache;
    Node *head;
    Node *tail;
    int capacity;
    
    // Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap) {
        capacity = cap;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head -> next = tail;
        tail -> prev = head;
    }

    // Function to return value corresponding to the key.
    int get(int key) {
        if (!cache.count(key)) 
            return -1;
        
        Node* node = cache[key];
        removeNode(node);
        insertNode(node);
        return node -> val;
    }

    // Function for storing key-value pair.
    void put(int key, int value) {
        if (cache.count(key)) {
            Node* curr = cache[key];
            removeNode(curr);
            delete curr;
        }
        
        // inset a new node
        Node* newNode = new Node(key, value);
        insertNode(newNode);
        cache[key] = newNode;
        
        // inserting a new node exceeded the capacity limit then delete node
        if (cache.size() > capacity) {
            Node* nodeToDel = tail -> prev;
            removeNode(nodeToDel);
            cache.erase(nodeToDel -> key);
            delete nodeToDel;
        }
    }
    
    // Remove a node from the ll
    void removeNode(Node *node) {
        Node *forw = node -> next;
        Node *back = node -> prev;
        back -> next = forw;
        forw -> prev = back;
        node -> next = NULL;
        node -> prev = NULL;
    }
    
    // Add a node right after the head (Most Recently Used Position)
    void insertNode(Node *node) {
        Node *forw = head -> next;
        head -> next = node;
        node -> prev = head;
        node -> next = forw;
        forw -> prev = node;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);

        int queries;
        cin >> queries;
        while (queries--) {
            string q;
            cin >> q;
            if (q == "PUT") {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->put(key, value);
            } else {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends