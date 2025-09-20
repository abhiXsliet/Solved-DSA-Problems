// https://leetcode.com/problems/implement-router/




import java.util.*;

class Router {
    private int size;
    private Queue<List<Integer>> q;
    private Set<List<Integer>> st;           // to avoid duplicates
    private Map<Integer, List<Integer>> mpp; // {destinations, {timestamps}}

    public Router(int memoryLimit) {
        this.size = memoryLimit;
        this.q  = new LinkedList<>();
        this.st = new HashSet<>();
        this.mpp = new HashMap<>();
    }
    
    public boolean addPacket(int source, int destination, int timestamp) {
        List<Integer> packet = Arrays.asList(source, destination, timestamp);

        if (st.contains(packet)) return false;

        if (q.size() >= size) forwardPacket();

        q.offer(packet);
        st.add(packet);
        mpp.computeIfAbsent(destination, k -> new ArrayList<>()).add(timestamp);
        
        return true;
    }
    
    public int[] forwardPacket() {
        if (q.isEmpty()) return new int[0];

        List<Integer> packet = q.poll();
        st.remove(packet);

        int dest = packet.get(1);
        List<Integer> timeStamp = mpp.get(dest);
        if (timeStamp != null && !timeStamp.isEmpty()) {
            timeStamp.remove(0);
        }

        int[] result = new int[packet.size()];
        for (int i = 0; i < packet.size(); i ++) {
            result[i] = packet.get(i);
        }
        return result;
    }
    
    public int getCount(int destination, int startTime, int endTime) {
        List<Integer> timeStamp = mpp.get(destination);
        if (timeStamp == null || timeStamp.isEmpty()) return 0;

        int low  = lowerBound(timeStamp, startTime);
        int high = upperBound(timeStamp, endTime);

        return (high - low);
    }

    int lowerBound(List<Integer> arr, int tar) {
        int n = arr.size();
        int low = 0, high = n - 1, ans = n;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr.get(mid) >= tar) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }

    int upperBound(List<Integer> arr, int tar) {
        int n = arr.size();
        int low = 0, high = n - 1, ans = n;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr.get(mid) > tar) {
                ans  = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
}

/**
 * Your Router object will be instantiated and called as such:
 * Router obj = new Router(memoryLimit);
 * boolean param_1 = obj.addPacket(source,destination,timestamp);
 * int[] param_2 = obj.forwardPacket();
 * int param_3 = obj.getCount(destination,startTime,endTime);
 */