class Solution {
public:
    int subarray(vector<int>& nums, int k) {
        int left = 0, right = 0, cnt = 0;
        unordered_map<int, int> mpp;

        while (right < nums.size()) {
            mpp[nums[right]]++;
            while (mpp.size() > k) {
                mpp[nums[left]]--;
                if (mpp[nums[left]] == 0) 
                    mpp.erase(nums[left]);

                    left = left + 1;
                }
                cnt = cnt + (right - left + 1);
                right++;
            }
            return cnt;
        }

        int subarraysWithKDistinct(vector<int> & nums, int k) {
            return subarray(nums, k) - subarray(nums, k - 1);
        }
    };