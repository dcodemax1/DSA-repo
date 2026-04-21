class Solution {
public:
// Optimal Approach
    vector<int> psee(vector<int>& arr , int n){
    vector<int> ans(n);
    stack<int> st;

    for(int i = 0; i<n; i++){
        while(!st.empty() && arr[st.top()] > arr[i]){
            st.pop();
        }
        if(st.empty()) ans[i] = -1;
        else ans[i]=st.top();
        st.push(i);
    }
    return ans;
    }
    vector<int> nse(vector<int>& arr, int n){
    vector<int> ans(n);
    stack<int> st;

    for(int i = n-1; i>=0; i--){
    while(!st.empty() && arr[st.top()]>= arr[i]){
        st.pop();
    }
    if(st.empty()) ans[i] = n;
    else ans[i] = st.top();
    st.push(i);
    }
    return ans;
    }


    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int left;
        int right;
        int total = 0;
        int mod = 1e9+7;
        vector<int> PSEE = psee(arr,n);
        vector<int> NSE = nse(arr,n);

        for(int i = 0; i<n; i++){
            left = i-PSEE[i];
            right = NSE[i] -i;
            total = (total+(left * right * 1LL * arr[i])%mod)%mod;
        }
        return total;
    }
};

/*
class Solution {
public:
// brute force 
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int total = 0;
         int mini;
         int mod = 1e9+7;
        for(int i =0; i<n; i++){
            mini = arr[i];
            for(int j = i; j<n; j++){
             if(arr[j] < mini){
                mini = arr[j];
             }
             total= (total+mini)% mod;
            }
            
        }
        return total;
    }
};
*/