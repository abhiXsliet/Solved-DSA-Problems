// https://leetcode.com/problems/find-the-length-of-the-longest-common-prefix/




import java.util.*;

class TrieNode {
    TrieNode[] children;
    TrieNode() {
        children = new TrieNode[10];
    }
}

class Trie {
    public TrieNode getNode() {
        return new TrieNode();
    }

    public void insertInTrie(TrieNode root, int num) {
        TrieNode crawl = root;
        String val = String.valueOf(num);
        for (char ch : val.toCharArray()) {
            int idx = ch - '0';
            if (crawl.children[idx] == null) {
                crawl.children[idx] = getNode();
            }
            crawl = crawl.children[idx];
        }
    }

    public int searchInTrie(TrieNode root, int num) {
        TrieNode crawl = root;
        String val = String.valueOf(num);
        int len = 0;
        for (char ch : val.toCharArray()) {
            int idx = ch - '0';
            if (crawl.children[idx] != null) {
                len ++;
                crawl = crawl.children[idx];
            } else {
                break;
            }
        }
        return len;
    }
}

class Solution {
    private int approach_1(int[] arr1, int[] arr2) {
        Set<Integer> st = new HashSet<>();
        for (int num : arr1) {
            int temp = num;
            while (temp > 0) {
                st.add(temp);
                temp /= 10;
            }
        }

        int maxLen = 0;
        for (int num : arr2) {
            int temp = num;
            while (temp > 0) {
                if (st.contains(temp)) {
                    maxLen = Math.max(maxLen, (int) (Math.log10(temp)) + 1);
                }
                temp /= 10;
            }
        }
        return maxLen;
    }
    private int approach_2(int[] arr1, int[] arr2) {
        Trie t = new Trie();
        TrieNode root = t.getNode();

        for (int num : arr1) {
            t.insertInTrie(root, num);
        }

        int maxLen = 0;
        for (int num : arr2) {
            maxLen = Math.max(maxLen, t.searchInTrie(root, num));
        }
        return maxLen;
    }
    public int longestCommonPrefix(int[] arr1, int[] arr2) {
        // return approach_1(arr1, arr2);
        return approach_2(arr1, arr2);
    }
}