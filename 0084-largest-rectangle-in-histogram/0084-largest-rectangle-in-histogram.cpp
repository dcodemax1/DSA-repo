class Solution {
public:
// Optimal Approach 
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int maxArea = 0;
        int nse;
        int pse;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                int element = st.top();
                st.pop();

                int nse = i;
                int pse = st.empty() ? -1 : st.top();
                maxArea = max(maxArea, heights[element] * (nse - pse - 1));
            }
            st.push(i);
        }
        while (!st.empty()) {
            nse = n;
            int element = st.top();
            st.pop();
            pse = st.empty() ? -1 : st.top();

            maxArea = max(maxArea, heights[element] * (nse - pse - 1));
        }

        return maxArea;
    }
};
/*
class Solution {
public:
    // Brute Force

    vector<int> findNSE(vector<int>& heights, int n){
     vector<int> nse(n);
     stack<int> st;

     for(int i = n-1; i>=0; i--){
         while(!st.empty() && heights[st.top()]>= heights[i]){
            st.pop();
         }

         nse[i] = st.empty() ? n : st.top();
         st.push(i);
     }
     return nse;
    }

    vector<int> findPSE(vector<int>& heights, int n){
    vector<int> pse(n);
    stack<int> st;

    for(int i = 0; i<n; i++){
        while(!st.empty() && heights[st.top()] >= heights[i]){
            st.pop();
        }

        pse[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    return pse;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxi = 0;

        vector<int> nse = findNSE(heights,n);
        vector<int> pse = findPSE(heights,n);

        for(int i = 0; i<n; i++){
            maxi = max(maxi , heights[i]*(nse[i]-pse[i]-1));
        }
        return maxi;
    }
};

*/