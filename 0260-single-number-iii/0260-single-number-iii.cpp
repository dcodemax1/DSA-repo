class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        long long xorr = 0;

        for (int i = 0; i < n; i++) {
            xorr ^= nums[i];
        }

        long long rightmost = (xorr & xorr - 1) ^ xorr;
        int number1 = 0, number2 = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] & rightmost) {
                number1 ^= nums[i];
            } else {
                number2 ^= nums[i];
            }
        }

        if (number1 < number2) {
            return {number1, number2};
        } else {
            return {number2, number1};
        }
    }
};