class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();

        int total = 1<<n;

        for(int num = 0; num<total ; num++){
            vector<int> subsets;

            for(int j = 0; j<n; j++){
                if (num & ( 1<<j )){
                    subsets.push_back(nums[j]);
                }
            }
            ans.push_back(subsets);
        }
        return ans;
    }
};