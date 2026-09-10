class Solution {
public:

    int helper(vector<int>& nums, int k){
        int l = 0, r = 0;
        int cnt= 0;
        int sum = 0;
        int n = nums.size();

        while(r < n){
            sum+=(nums[r]%2);

            while(sum > k){
                sum-=(nums[l]%2);
                l++;
            }

            if(sum <=k){
                cnt+=(r-l+1);
            }

            r++;
        }
        return cnt;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return helper(nums, k) - helper (nums, k-1);
    }
};