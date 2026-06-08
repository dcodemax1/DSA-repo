class Solution {
public:

// Better Approach 

    vector<int> rearrangeArray(vector<int>& A) {
        int n = A.size();

        int posIndex = 0;
        int negIndex = 1;
        vector<int> ans(n,0);

        for(int i = 0; i<n; i++){
             if(A[i]>0){
                ans[posIndex] = A[i];
                posIndex+=2;
             }
             else{
                ans[negIndex] = A[i];
                negIndex+=2;
             }
        }
        return ans;
    }
};

/*
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();

        vector<int> pos;
        vector<int> neg;

        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                pos.push_back(nums[i]);
            } else {
                neg.push_back(nums[i]);
            }
        }
        vector<int> ans(n);

        for (int i = 0; i < n/2; i++) {
            ans[2 * i] = pos[i];
            ans[2 * i + 1] = neg[i];
        }
        return ans;
    }
};

*/