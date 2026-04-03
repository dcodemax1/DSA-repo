class Solution {
public:

// Optimal Approach

    int singleNumber(vector<int>& nums) {

        int n = nums.size();
        int xorr = 0;
       for(int i = 0; i<n; i++){
            xorr= xorr^nums[i];
       }
       return xorr;
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

/*

Bettre but fail for negative and large scale

  int maxi = nums[0];
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
 */


 /* Better 2 Approach
 
   int n = nums.size();
        map<long long, int> mp;

        for (int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }

        for (auto x : mp) {
            if (x.second == 1) {
                return x.first;
            }
        }
        return -1;

        */