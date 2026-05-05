class Solution {
public:
    int findminsplitSum(vector<int>& nums, int k, int mid, int n) {
        int count = 1;
        int splitSum = 0;

        for (int i = 0; i < n; i++) {
            if (splitSum + nums[i] <= mid) {
                splitSum += nums[i];
            } else {
                count++;
                splitSum = nums[i];
            }
        }
        return count;
    }

    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();

        int low = *max_element(nums.begin(), nums.end() );
        int high = accumulate(nums.begin(), nums.end(), 0);

        while (low <= high) {
            int mid = low + (high - low) / 2;

            int splitarr = findminsplitSum(nums, k, mid, n);

            if (splitarr > k) {
                low =mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return low;
    }
};