class Solution {
public:

// Optimal Approach 

    unordered_map<int, int> mp;
    int subarraysDivByK(vector<int>& nums, int k) {
        int sum = 0;
        int result = 0;
        mp[0] = 1;

        for (int num : nums) {
            sum += num;
           int rem = sum % k;

            if (rem < 0) {
                rem += k;
            }

            if (mp.find(rem) != mp.end()) {
                result += mp[rem];
            }

            mp[rem]++;
        }
        return result;
    }
};

/*class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int count = 0;
        int n = nums.size();

        for (int i = 1; i < n; i++) {
            nums[i] += nums[i - 1];
        }

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {

                int sum = (i == 0) ? nums[j] : nums[j] - nums[i - 1];
                if (sum % k == 0) {
                    count++;
                }
            }
        }
        return count;
    }
};
*/
/*

class Solution {
public:

// Brute Force

    int subarraysDivByK(vector<int>& nums, int k) {

        int count = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];
                if (sum % k == 0) {
                    count++;
                }
            }
        }
        return count;
    }
};

*/
