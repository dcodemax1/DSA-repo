class Solution {
public:
// Optimal Approach
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();

        long xorr = 0;

        for (int i = 0; i < n; i++) {
            xorr = xorr ^ nums[i];
        }

        int rightmostBit = (xorr & xorr - 1) ^ xorr;
        int number1 = 0, number2 = 0;

        for (int i = 0; i < n; i++) {
            if ((nums[i] & rightmostBit)) {
                number1 = number1 ^ nums[i];
            } else {
                number2 = number2 ^ nums[i];
            }
        }
        if (number1 < number2)
            return {number2, number1};
        return {number1, number2};
    }
};

/* Brute Force

 map<int, int> mp;
        int n = nums.size();
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }

        for (auto x : mp) {
            if (x.second == 1) {
                ans.push_back(x.first);
            }
            if (ans.size() == 2)
                break;
        }
        return ans;

        */