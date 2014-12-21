/*
https://oj.leetcode.com/problems/container-with-most-water/

Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container.
*/

class Solution {
public:
    int maxArea(vector<int> &height) {
        int sz = height.size();
        if (sz <= 1) return 0;
        int left=0, right = sz-1, res = 0;
        while (left < right) {
            res = max (res, (right-left)*min(height[left], height[right]));
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return res;
    }
};