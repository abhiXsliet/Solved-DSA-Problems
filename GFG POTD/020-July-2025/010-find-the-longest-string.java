// https://www.geeksforgeeks.org/problems/find-the-longest-string--170645/1




import java.util.*;

class Trie {
    private static class TrieNode {
        boolean isTerminal;
        TrieNode[] children = new TrieNode[26];
    }
    
    private TrieNode getNode() {
        TrieNode newNode = new TrieNode();
        newNode.isTerminal = false;
        for (int i = 0; i < 26; i ++) {
            newNode.children[i] = null;
        }
        return newNode;
    }
    
    TrieNode root;
    public Trie() {
        root = getNode();
    }
    
    public void insertInTrie(String s) {
        TrieNode crawl = root;
        for (char ch : s.toCharArray()) {
            int idx = (ch - 'a');
            if (crawl.children[idx] == null) {
                crawl.children[idx] = getNode();
            }
            crawl = crawl.children[idx];
        }
        crawl.isTerminal = true;
    }
    
    public boolean searchInTrie(String s) {
        TrieNode crawl = root;
        for (char ch : s.toCharArray()) {
            int idx = (ch - 'a');
            if (crawl.children[idx] == null || !crawl.children[idx].isTerminal) {
                return false;
            }
            crawl = crawl.children[idx];
        }
        return crawl.isTerminal;
    }
}

class Solution {
    public String longestString(String[] words) {
        // return approach_1(words);   // TLE Using HashSet : Brute
        // return approach_2(words);   // Using HashMap : Better
        return approach_3(words);      // Using Trie
    }
    
    // TC : O(N * M * M)
    // SC : O(N * M)
    private String approach_1(String[] words) {
        HashSet<String> uSt = new HashSet<>();
        for (String s : words) {
            uSt.add(s);
        }
        
        String result = "";
        for (String s : words) {
            StringBuilder pref = new StringBuilder();
            boolean present = true;
            for (char ch : s.toCharArray()) {
                pref.append(ch);
                if (!uSt.contains(pref.toString())) {
                    present = false;
                    break;
                }
            }
            if (present && (result.length() < s.length() || 
                            (result.length() == s.length() && s.compareTo(result) < 0))) {
                result = s;
            }
        }
        return result;
    }
    
    // TC : O(N*log(N)*M)
    // SC : O(N * M)
    private String approach_2(String[] words) {
        Arrays.sort(words);
        
        HashMap<String, Boolean> uMpp = new HashMap<>();
        for (String s : words) {
            if (s.length() == 1) {
                uMpp.put(s, true);
            } else {
                String temp = s.substring(0, s.length() - 1);
                
                if (uMpp.getOrDefault(temp, false)) {
                    uMpp.put(s, true);
                } else {
                    uMpp.put(s, false);
                }
            }
        }
        
        String result = "";
        for (String s : words) {
            if (uMpp.get(s) && s.length() > result.length()) {
                result = s;
            }
        }
        return result;
    }
    
    // TC : O(N * M) Where N = Size of words array
    // SC : O(N * M) where M = max string length
    private String approach_3(String[] words) {
        Trie t = new Trie();
        
        for (String s : words) {
            t.insertInTrie(s);
        }
        
        String result = "";
        for (String s : words) {
            if (t.searchInTrie(s)) {
                if ((result.length() < s.length()) || 
                    (result.length() == s.length() && s.compareTo(result) < 0)) {

                    result = s; 
                }
            }
        }
        return result;
    }
}