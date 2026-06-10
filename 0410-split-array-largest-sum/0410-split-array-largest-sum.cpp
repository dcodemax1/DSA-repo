class Solution {
public:

    int helper(vector<int>& nums, int k){
        int cnt = 1;
        int largeSum = 0;
        int n = nums.size();

       for(auto val : nums){
        if(largeSum + val <= k){
            largeSum+=val;
        }
        else{
            cnt++;
            largeSum = val;
        }
       }
       return cnt;
    }

    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();

        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums. begin(), nums.end(), 0);

        while(low<=high){
            int mid = low+(high-low)/2;

           int spilt= helper(nums, mid);

           if(spilt > k){
             low = mid+1;
           }
           else{
            high = mid-1;
           }
        }

        return low;
    }
};