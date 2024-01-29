// https://www.codingninjas.com/studio/problems/minimum-time-to-solve-the-problems_1062659



#include <bits/stdc++.h> 
using namespace std;
typedef long long int ll;

// TC : O(N)
// SC : O(1)
int getFriendCount(vector<int>& problemPerSubject, ll maxProblemsPerFriend) {
    ll currentProblemSum = 0;
    int friendCount = 1;
    for (int i = 0; i < problemPerSubject.size(); i++) {
        if (problemPerSubject[i] + currentProblemSum <= maxProblemsPerFriend) {
            currentProblemSum += problemPerSubject[i];
        } else {
            friendCount++;
            currentProblemSum = problemPerSubject[i];
        }
    }
    return friendCount;
}

// TC : O(NlogM), BS = O(logM), where N = problemPerSubject.size() and M is the sum of elements in problemPerSubject
// SC : O(1)
ll minimumRequiredTime(vector<int>& problemPerSubject, int totalFriends) {
    int totalproblemPerSubject = problemPerSubject.size();

    ll minProblemsPerFriend = *max_element(problemPerSubject.begin(), problemPerSubject.end());
    ll maxProblemsPerFriend = accumulate(problemPerSubject.begin(), problemPerSubject.end(), 0LL);

    while (minProblemsPerFriend < maxProblemsPerFriend) {
        ll midProblemsPerFriend = minProblemsPerFriend + (maxProblemsPerFriend - minProblemsPerFriend) / 2;

        if (getFriendCount(problemPerSubject, midProblemsPerFriend) <= totalFriends) {
            maxProblemsPerFriend = midProblemsPerFriend;
        } else {
            minProblemsPerFriend = midProblemsPerFriend + 1;
        }
    }
    return minProblemsPerFriend;
}
