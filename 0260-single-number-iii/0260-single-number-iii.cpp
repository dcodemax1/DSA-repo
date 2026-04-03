class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
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
    }
};