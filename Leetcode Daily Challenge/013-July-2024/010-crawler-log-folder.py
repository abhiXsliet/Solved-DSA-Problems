# https://leetcode.com/problems/crawler-log-folder/




class Solution(object):
    def minOperations(self, logs):
        """
        :type logs: List[str]
        :rtype: int
        """
        # return self.approach_1(logs)     # Brute
        # return self.approach_2(logs)     # Better
        # return self.approach_3(logs)     # Better : Different writing style
        return self.approach_4(logs)     # Using Stack

    # TC : O(M) Where M = logs array size
    # SC : O(N) Where N = Length of Individual Strings
    def approach_4(self, logs) :
        stk = []
        for log in (logs) :
            if log != "../" and log != "./":
                stk.append(log)
            elif log == "../":
                if stk:
                    stk.pop()
        return len(stk)

    # TC : O(M) Where M = logs array size
    # SC : O(1)
    def approach_3(self, logs) :
        depth = 0
        for log in (logs) :
            if log == "../":
                depth = max(0, depth - 1)
            elif log == "./":
                continue
            else:
                depth += 1
        return depth

    # TC : O(M) Where M = logs array size
    # SC : O(1)
    def approach_2(self, logs) :
        depth = 0
        for log in logs:
            n   = len(log)
            dot = 0
            if log[n - 2].isdigit() or log[n - 2].isalpha():
                depth += 1
            if log[0] == '.' and log[n - 2] == '.':
                dot = n - 2
            depth = depth - dot if depth >= dot else 0
        return depth

    # TC : O(M*N) Where M = logs array size & N = Max Length of Individual String
    # SC : O(1)
    def approach_1(self, logs) :
        depth = 0
        for log in logs :
            n   = len(log)
            dot = 0
            for i in range (n - 2, -1, -1) :
                if log[i].isdigit() or log[i].isalpha():    # isalnum()
                    depth += 1
                    break
                if i - 1 >= 0 and log[i - 1] == '.' :
                    dot += 1 
            depth = depth - dot if depth >= dot else 0
        return depth