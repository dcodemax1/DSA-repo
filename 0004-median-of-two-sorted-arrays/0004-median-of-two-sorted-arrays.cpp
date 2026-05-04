class Solution {
public:

//  Better Approach 

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int i = 0;
        int j = 0;

        int cnt = 0;
        
        int n = (n1 + n2);

        int ind2 = (n / 2);
        int ind1 = ind2 - 1;

        int ele1 = INT_MIN, ele2 = INT_MIN;

        while (i < n1 && j < n2) {
            if (nums1[i] < nums2[j]) {
                if (cnt == ind1)
                    ele1 = nums1[i];
                if (cnt == ind2)
                    ele2 = nums1[i];
                cnt++;
                i++;
            } else {
                if (cnt == ind2)
                    ele2 = nums2[j];
                if (cnt == ind2)
                    ele2 = nums2[j];
                cnt++;
                j++;
            }
        }

        while (i < n1) {
            if (cnt == ind1)
                ele1 = nums1[i];
            if (cnt == ind2)
                ele2 = nums1[i];
            cnt++;
            i++;
        }

        while (j < n2) {
            if (cnt == ind2)
                ele2 = nums2[j];
            if (cnt == ind2)
                ele2 = nums2[j];
            cnt++;
            j++;
        }

        if(n % 2 == 1) return ele2;

        return (double)((double)(ele1+ele2))/2.0;
    }
};

/*class Solution {
public:

// Brute Force

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums3;
        int n = nums1.size();
        int m = nums2.size();

        int i = 0, j = 0;

        while (i < n && j < m) {
            if (nums1[i] < nums2[j]) {
                nums3.push_back(nums1[i++]);

            } else {
                nums3.push_back(nums2[j++]);
            }
        }

        while (i < n) {
            nums3.push_back(nums1[i++]);
        }

        while (j < m) {
            nums3.push_back(nums2[j++]);
        }

        int n1 = nums3.size();

        if (n1 % 2 == 1)
            return nums3[n1 / 2];

        return (double)((double)(nums3[n1 / 2]) + (double)(nums3[(n1 / 2) - 1]))
/ 2.0;
    }
};

*/

/*
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        if(nums2.size()<nums1.size()) return
findMedianSortedArrays(nums2,nums1); int n1 = nums1.size(); int n2 =
nums2.size();

        int low = 0, high = n1;

        while (low <= high) {
            int mid1 = low + (high - low) / 2;
            int mid2 = (n1 + n2 + 1) / 2 - mid1;

            int l1 = mid1 == 0 ? INT_MIN : nums1[mid1 - 1];
            int l2 = mid2 == 0 ? INT_MIN : nums2[mid2 - 1];

            int r1 = mid1 == n1 ? INT_MAX : nums1[mid1];
            int r2 = mid2 == n2 ? INT_MAX : nums2[mid2];

            if (l1 <= r2 && l2 <= r1) {
                if ((n1 + n2) % 2 == 0) {
                    return (max(l1, l2)+ min(r1, r2)) / 2.0;
                } else {
                    return max(l1, l2);
                }
            }

            else if (l1 > r2) {
                high = mid1 - 1;

            } else {
                low = mid1 + 1;
            }
        }

        return 0.0;
    }
};
*/