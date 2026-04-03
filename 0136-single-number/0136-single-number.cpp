class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int maxi = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            maxi = max(maxi, nums[i]);
        }

        vector<int> hash(maxi+1,0);

        for(int i = 0; i<n; i++){
            hash[nums[i]]++;
        }

        for(int i = 0; i<n; i++ ){
            if(hash[nums[i]]==1){
                return nums[i];
            }
        }
        return -1;
    }
};

/*  Brure Force

int n = nums.size();
       for (int i = 0; i < n; i++) {
           int cnt = 0;

           for (int j = 0; j < n; j++) {
               if (nums[j] == nums[i]) {
                   cnt++;
               }
           }
           if (cnt == 1) {
               return nums[i];
           }
       }
       return -1;

       */