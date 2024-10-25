// https://leetcode.com/problems/remove-sub-folders-from-the-filesystem/




import java.util.*;

class Solution {
    // TC : O(N*log(N))
    // SC : O(1)
    public List<String> removeSubfolders(String[] folder) {
        Arrays.sort(folder);
        List<String> res = new ArrayList<>();
        for (String fold : folder) {
            if (res.isEmpty() || !fold.startsWith(res.get(res.size() - 1)  + "/")) {
                res.add(fold);
            }
        }
        return res;
    }
}