class Solution {
public:

// Optimal Approach using range concept 

    int jump(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = 0;
        int jumps = 0;

        while (r < n - 1) {
            int farthest = 0;
            for (int i = l; i<= r; i++) {
                farthest = max(farthest, i + nums[i]);
            }
            l = r + 1;
            r = farthest;

            jumps++;
        }
        return jumps;
    }
};

/*
class Solution {
public:

// Recursion and using memoization Brute Force

    int helper(int ind, int jumps, vector<int>& nums, vector<vector<int>>& dp,
               int n) {

        if (ind >= n - 1)
            return jumps;

        if (dp[ind][jumps] != -1)
            return dp[ind][jumps];

        int mini = INT_MAX;

        for (int i = 1; i <= nums[ind]; i++) {
            mini = min(mini, helper(ind + i, jumps + 1, nums, dp, n));
        }
        return dp[ind][jumps] = mini;
    }

    int jump(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(n, -1));

        return helper(0, 0, nums, dp, n);
    }
};

*/