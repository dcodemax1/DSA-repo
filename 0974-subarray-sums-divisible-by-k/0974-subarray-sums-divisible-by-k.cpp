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

class Solution {
public:
    int subarraysDivByK(std::vector<int>& nums, int k) {
       
        int count = 0;
        int prefixSum = 0;
        std::unordered_map<int, int> prefixMap;
        prefixMap[0] = 1; 

        for (int num : nums) {
           
            prefixSum += num;
            
           
            int mod = prefixSum % k;
       
            if (mod < 0) {
                mod += k;
            }
            
            
            if (prefixMap.find(mod) != prefixMap.end()) {
                count += prefixMap[mod];
                prefixMap[mod] += 1;
            } else {
                prefixMap[mod] = 1;
            }
        }
        
        return count; 
    }
};