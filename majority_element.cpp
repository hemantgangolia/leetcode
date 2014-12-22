/*
https://oj.leetcode.com/problems/majority-element/

Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.
*/
class Solution {
public:
    int majorityElement(vector<int> &num) {
        int prev = num[0], count = 1, max_count = 1, max_index = 0;
        for (int i = 1; i < num.size(); i++) {
            if (num[i] == prev) {
                count++;
                if (max_count < count) {
                    max_count = count;
                    max_index = i;
                }
            } else {
                prev = num[i];
                count = 1;
            }
        }
        return num[max_index];
    }
};
