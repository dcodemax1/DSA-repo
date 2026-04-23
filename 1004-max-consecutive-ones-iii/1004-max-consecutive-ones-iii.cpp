class Solution {
public:
    int l = 0, r = 0;
    int maxLen = 0;
    int zeros = 0;
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        while (r < n) {
            if (nums[r] == 0) {
                zeros++;
            }
            if (zeros > k) {
                if (nums[l] == 0) {
                    zeros--;
                }
                l++;
            }
            maxLen = max(maxLen, r - l + 1);
            r++;
        }
        return maxLen;
    }
};

/*
class Solution {
public:

// Better Approach

    int l = 0, r = 0;
    int maxLen = 0;
    int zeros = 0;
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        while(r<n){
            if(nums[r]==0){
                zeros++;

            }
            while(zeros> k){
              if(nums[l]==0){
                zeros--;

              }
               l++;
            }
            maxLen = max(maxLen, r-l+1);
            r++;
        }
        return maxLen;
    }
};
*/

/*
class Solution {
public:

// Brute Force

    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();

        int maxLen = 0;
        for (int i = 0; i < n; i++) {
            int zeros = 0;
            for (int j = i; j < n; j++) {
                if (nums[j] == 0) {
                    zeros++;
                }
                if (zeros > k) {
                   break;
                }
                 maxLen = max(maxLen, j - i + 1);
            }
        }
        return maxLen;
    }
};
*/