class Solution {
public:
    vector<int> psee(vector<int>& arr, int n) {
        vector<int> ans(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            ans[i] = st.empty() ? -1 :st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> nse(vector<int>& arr, int n) {
        vector<int> ans(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
           ans[i] = st.empty() ? n :st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> pnge(vector<int>& arr, int n) {
        vector<int> ans(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] < arr[i]) {
                st.pop();
            }
            ans[i] = st.empty() ? -1 :st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> nge(vector<int>& arr, int n) {
        vector<int> ans(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] <= arr[i]) {
                st.pop();
            }
            ans[i] = st.empty() ? n :st.top();
            st.push(i);
        }
        return ans;
    }

    long long sumSubarrayMins(vector<int>& arr, int n) {
       
        long long total = 0;

        vector<int> PSEE = psee(arr, n);
        vector<int> NSE = nse(arr, n);

        for (int i = 0; i < n; i++) {
           int left = i - PSEE[i];
           int right = NSE[i] - i;
            total = (total + left * right * 1LL * arr[i]);
        }
        return total;
    }

    long long sumSubarrayMaxs(vector<int>& arr, int n ) {
       
        long long total = 0;

        vector<int> PNGE = pnge(arr, n);
        vector<int> NGE = nge(arr, n);

        for (int i = 0; i < n; i++) {
           int left = i - PNGE[i];
           int right = NGE[i] - i;
            total = (total + left * right * 1LL * arr[i]);
        }
        return total;
    }

    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();

        return sumSubarrayMaxs(nums, n) - sumSubarrayMins(nums, n);
    }
};