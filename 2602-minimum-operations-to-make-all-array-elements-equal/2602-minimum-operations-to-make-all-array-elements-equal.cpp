class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        long long n = nums.size();

        sort(nums.begin(), nums.end());

        vector<long long> prefix(n+1,0);
        prefix[0] = nums[0];
        vector<long long> ans;

        for (int i = 0; i < n; i++) {
            prefix[i+1] = prefix[i] + nums[i];
        }
        nums.insert(nums.begin(), 0);
        n++;

        for (auto q : queries) {
            long long lidx =
                lower_bound(nums.begin(), nums.end(), q) - nums.begin()-1;
            long long uidx =
                upper_bound(nums.begin(), nums.end(), q) - nums.begin();

            long long val = q * lidx - (prefix[lidx] - prefix[0]);

            if (uidx != n) {
                val += (prefix[n - 1] - prefix[uidx - 1]) - q * (n - uidx);
            }
            ans.push_back(val);
        }
        return ans;
    }
};
