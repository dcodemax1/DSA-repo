/*
Brute Force

class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        int n = nums.size();
        int ans = -1;
        int mini = INT_MAX;

        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){

                if(nums[i]==1 && nums[j]==2 || nums[i]==2 && nums[j]==1){
                    ans = abs(i-j);
                    mini = min(mini, ans);

                }


            }
        }
        return mini == INT_MAX ? -1 : mini;

    }
};
*/

class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        int n = nums.size();
        int first = -1, second = -1;
        int mini = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                first = i;

                if (second != -1) {
                    mini = min(mini, abs(first - second));
                }
            } else if (nums[i] == 2) {
                second = i;

                if (first != -1) {
                    mini = min(mini, abs(first - second));
                }
            }
        }

        return mini == INT_MAX ? -1 : mini;
    }
};