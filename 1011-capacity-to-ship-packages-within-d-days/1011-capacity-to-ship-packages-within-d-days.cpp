class Solution {
public:
    int needDays(vector<int>& weights, int cap, int n) {
        int day = 1;
        int weight = 0;
        for (int i = 0; i < n; i++) {
            if ((weight + weights[i]) > cap) {
                day++;
                weight = weights[i];
            } else {
                weight += weights[i];
            }
        }
        return day;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        int n = weights.size();

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (needDays(weights, mid, n) <= days) {
                high = mid - 1;
            } else
                low = mid + 1;
        }
        return low;
    }
};