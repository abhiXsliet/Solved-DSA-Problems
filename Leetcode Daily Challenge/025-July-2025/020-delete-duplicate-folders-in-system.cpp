// https://leetcode.com/problems/delete-duplicate-folders-in-system/




#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    struct Node {
        string name;
        string subfolder;
        unordered_map<string, Node*> children;
    };

    Node* getNode(string name) {
        Node* newNode = new Node();
        newNode -> name = name;
        newNode -> subfolder = "";
        return newNode;
    }
    
    void insertInTrie(Node* root, vector<string> &path) {
        for (string &folder : path) {
            if (!root -> children.count(folder)) {
                root -> children[folder] = getNode(folder);
            }
            root = root -> children[folder];
        }
    }

    string populateNodes(Node* root, unordered_map<string, int> &subfolderMap) {
        vector<pair<string, string>> subfolderPaths;
        
        for (auto &[childName, childNode] : root -> children) {
            string subfolderResult = populateNodes(childNode, subfolderMap);
            subfolderPaths.push_back({childName, subfolderResult});
        }

        sort(begin(subfolderPaths), end(subfolderPaths));

        string completePath; // this is subfolder of the current root which get formed from the children paths

        for (auto &[childName, childPath] : subfolderPaths) {
            completePath += "(" + childName + childPath + ")";
        }

        root -> subfolder = completePath;

        if (!completePath.empty()) {
            subfolderMap[completePath] ++; 
        }

        return completePath;
    }

    void removeDuplicates(Node* root, unordered_map<string, int> &subfolderMap) {
        for (auto it = root -> children.begin(); it != root -> children.end(); ) {
            string childName = it -> first;
            Node* childNode  = it -> second;

            if (!childNode -> subfolder.empty() && subfolderMap[childNode -> subfolder] > 1) {
                it = root -> children.erase(it);
            } else {
                removeDuplicates(childNode, subfolderMap);
                it ++;
            }
        }
    }

    void constructResult(Node* root, vector<string> &path, vector<vector<string>> &result) {
        for (auto &[childName, childNode] : root -> children) {
            path.push_back(childName);
            result.push_back(path);
            constructResult(childNode, path, result);
            path.pop_back();
        }
    }
public:
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        Node* root = getNode("/");

        // Construct the trie
        for (auto& path : paths) {
            insertInTrie(root, path);
        }

        unordered_map<string, int> subfolderMap;    // stores the cnt of each subfolder
        populateNodes(root, subfolderMap);

        removeDuplicates(root, subfolderMap);

        vector<vector<string>> result;
        vector<string> path;
        constructResult(root, path, result);

        return result;
    }
};