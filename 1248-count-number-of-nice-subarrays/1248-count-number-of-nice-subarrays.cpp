class Solution {
public:
// Optimal Approach

    int atMost(vector<int>& nums, int k){
     int n = nums.size();
        int l = 0, r = 0;
        int count =0;
       long long sum = 0;

        if(k <0) return 0;

        while (r < n) {
            sum += (nums[r]%2);

            while (sum > k) {
                sum -= (nums[l]%2);
                l++;
            }
            if(sum <= k){
                count+=r-l+1;
            }
            r++;
        }
      
        return count;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums, k)- atMost(nums, k-1);
    }
};