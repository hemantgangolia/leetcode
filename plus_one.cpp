/*
https://oj.leetcode.com/problems/plus-one/

Given a non-negative number represented as an array of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.
*/

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        reverse(digits.begin(), digits.end());
        int carry = 1, sum;
        for (int i = 0; i < digits.size(); i++) {
            sum = (digits[i]+carry);
            digits[i] = sum%10;
            carry = sum/10;
            if (carry == 0) {
                break;
            }
        }
        if (carry != 0) {
            digits.push_back(carry);
        }
        reverse(digits.begin(), digits.end());
        return digits;
    }
};