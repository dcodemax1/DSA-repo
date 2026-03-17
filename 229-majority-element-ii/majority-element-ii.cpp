class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();

        int mini = int(n / 3) + 1;

        int cnt1 = 0, cnt2 = 0;
        int el1 = INT_MIN, el2 = INT_MIN;

        for (int i = 0; i < n; i++) {
            if (cnt1 == 0 && el2 != nums[i]) {
                cnt1++;
                el1 = nums[i];
            }

            else if (cnt2 == 0 && el1 != nums[i]) {
                cnt2++;
                el2 = nums[i];
            } else if (nums[i] == el1) {
                cnt1++;
            } else if (nums[i] == el2) {
                cnt2++;
            }

            else {
                cnt1--;
                cnt2--;
            }
        }

        int count1 = 0, count2 = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] == el1)
                count1++;
            if (nums[i] == el2)
                count2++;
        }

        if (count1 >= mini) {
            ans.push_back(el1);
        };
        if (count2 >= mini) {
            ans.push_back(el2);
        };

        return ans;
    }
};