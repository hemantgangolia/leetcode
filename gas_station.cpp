/*
https://oj.leetcode.com/problems/gas-station/

There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.

Note:
The solution is guaranteed to be unique.
*/
class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int n = gas.size(), net = 0, res = 0;
        if (n==0) return -1;
        int prev = 0;
        if (n==1 && gas[0]-cost[0] < 0) return -1;
        for (int i = 0; i < n; i++) {
            net += (gas[i]-cost[i]);
            if (net < 0) {
                prev += net;
                net = 0;
                res = i+1;
            }
        }
        if (net + prev >= 0) return res;
        else return -1;
    }
};
