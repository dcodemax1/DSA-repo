class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int n = nums.size();

        int prefixSum = 0;
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            prefixSum += nums[i];

            int rem = prefixSum - k;

            cnt += mp[rem];

            mp[prefixSum] += 1;
        }
        return cnt;
    }
};