class Solution {
public:
    // Optimal Approach

    int atMostK(vector<int>& nums, int k) {
        int l = 0, r = 0;
        int n = nums.size();
        int count = 0;
        unordered_map<int, int> mp;

        while (r < n) {
            mp[nums[r]]++;
           
            while (mp.size() > k) {
                mp[nums[l]]--;
                if (mp[nums[l]] == 0) {
                    mp.erase(nums[l]);
                }
                l++;
            }

            if(mp.size()<=k){
            count += (r - l + 1);
            }

            r++;
        }
        return count;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }
};

/*
class Solution {
public:

// Brute Force

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        int n = nums.size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            mp.clear();
            for (int j = i; j < n; j++) {
                mp[nums[j]]++;

                if (mp.size() == k) {
                    count++;
                } else if (mp.size() > k) {
                    break;
                }
            }
        }
        return count;
    }
};

*/