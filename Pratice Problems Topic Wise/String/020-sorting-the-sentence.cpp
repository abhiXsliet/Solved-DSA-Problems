// https://leetcode.com/problems/sorting-the-sentence/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC = O(N)
    // SC = O(N)
    string sortSentence(string s) {

        // Create a string stream from the input string
        istringstream iss(s);

        // Declare a vector to store the words
        vector<string> words;

        string word;
        // Split the input string into words and store them in the vector
        while (iss >> word) {
            words.push_back(word);
        }

        // Get the number of words
        int m = words.size();
        // Declare a vector to store the sorted words
        vector<string> result(m);

        // Iterate over the words
        for (auto& word : words) {
            // Get the length of the word
            int len = word.size();

            // Get the index from the last character of the word
            int i = word[len - 1] - '1';

            // Add the word to the result vector at the correct position
            result[i] = word.substr(0, len - 1);
        }

        // Declare a string to store the final result
        string ans;
        // Concatenate the sorted words into a sentence
        for (auto& word : result) {
            ans += word + " ";
        }

        // Remove the trailing space
        ans.pop_back();
        
        // Return the sorted sentence
        return ans;
    }
};