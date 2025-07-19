// https://leetcode.com/problems/remove-sub-folders-from-the-filesystem/




import java.util.*;

class Solution {
    public List<String> removeSubfolders(String[] folder) {
        // return approach_1(folder);
        return approach_2(folder);  // Extra Space Optimized
    }

    // TC : O(N*log(N))
    // SC : O(1)
    private List<String> approach_2(String[] folder) {
        Arrays.sort(folder);
        List<String> result = new ArrayList<>();
        for (String fold : folder) {
            if (result.isEmpty() || !fold.startsWith(result.get(result.size() - 1) + "/")) {
                result.add(fold);
            }
        }
        return result;
    }

    // TC : O(N*log(N))
    // SC : O(N)
    private List<String> approach_1(String[] folder) {
        Arrays.sort(folder);
        Set<String> st = new HashSet<>();
        List<String> result = new ArrayList<>();
        for (String fold : folder) {
            boolean isSubFolder = false;
            StringBuilder prefix = new StringBuilder();
            for (char ch : fold.toCharArray()) {
                if (ch == '/' && st.contains(prefix.toString())) {
                    isSubFolder = true;
                    break;
                }
                prefix.append(ch);
            }
            if (!isSubFolder) {
                st.add(prefix.toString());
                result.add(fold);
            }
        }
        return result;
    }
}