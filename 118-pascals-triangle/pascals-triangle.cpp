class Solution {
public:

    vector<int> getRows(int rows){
        long long ans = 1;
        vector<int> ansRows;

        ansRows.push_back(1);

        for(int col = 1; col<rows; col++){
          ans = ans*(rows-col);
          ans = ans/col;
          ansRows.push_back(ans);
        }
      return ansRows;

    }

    vector<vector<int>> generate(int numRows) {

         vector<vector<int>> ans;
         for(int i = 1; i<=numRows; i++){
            ans.push_back(getRows(i));
         }
        return ans;
    }
};