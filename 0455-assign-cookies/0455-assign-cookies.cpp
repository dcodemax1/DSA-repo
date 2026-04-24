class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n = g.size();
        int m = s.size();
        int cnt = 0;

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int l = 0, r = 0;

        while (l < n && r < m) {
            if (s[r] < g[l]) {
                r++;
            }
            else if(s[r]>=s[l]){
                l++;
                r++;
            }
           
        }
        return l;
    }
};