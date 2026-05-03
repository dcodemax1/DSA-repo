class Solution {
public:
    // Brute Force

    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();

        int mini = (int)n / 3;

        vector<int> res;

        for (int i = 0; i < n; i++) {

            if (res.empty() || res.back() != nums[i]) {
                int cnt = 0;
                for (int j = 0; j < n; j++) {

                    if (nums[j] == nums[i]) {
                        cnt++;
                    }
                }
                if (cnt > mini) {

                    res.push_back(nums[i]);
                }
            }
            if (res.size() == 2)
                break;
        }

        return res;
    }
};
/*
class Solution {
public:

// Optimal Approach
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1 = 0;
        int cnt2 = 0;

        int ele1 = INT_MIN, ele2 = INT_MIN;

        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (cnt1 == 0 && ele2 != nums[i]) {
                cnt1 = 1;
                ele1 = nums[i];
            } else if (cnt2 == 0 && ele1 != nums[i]) {
                cnt2 = 1;
                ele2 = nums[i];
            }

            else if (ele1 == nums[i]) {
                cnt1++;
            } else if (ele2 == nums[i]) {
                cnt2++;
            } else {
                cnt1--;
                cnt2--;
            }
        }

        int count0 = 0, count1 = 0;

        for (int i = 0; i < n; i++) {
            if (ele1 == nums[i]) {
                count0++;
            }
            if (ele2 == nums[i]) {
                count1++;
            }
        }

        vector<int> res;
        int mini = (int)n / 3 + 1;

        if (count0 >= mini) {
            res.push_back(ele1);
        }

        if (count1 >= mini && ele2 != ele1) {
            res.push_back(ele2);
        }

        return res;
    }
};

*/