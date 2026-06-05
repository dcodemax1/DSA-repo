class Solution {
public:

// Optimal Approach O (8^n^2)

    bool isValid(vector<vector<int>>& grid, int r, int c, int n,
                 int expectVal) {

        if (grid[r][c] == n * n - 1)
            return true;

        vector<pair<int, int>> directions = {{-2, 1},  {-1, 2}, {1, 2},
                                             {2, 1},   {2, -1}, {1, -2},
                                             {-1, -2}, {-2, -1}};

        for (auto dir : directions) {
            int new_r = r + dir.first;

            int new_c = c + dir.second;

            if (new_r >= 0 && new_c >= 0 && new_r < n && new_c < n &&
                grid[new_r][new_c] == expectVal + 1) {

                if (isValid(grid, new_r, new_c, n, expectVal + 1)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool checkValidGrid(vector<vector<int>>& grid) {
        if (grid[0][0] != 0)
            return false;

        return isValid(grid, 0, 0, grid.size(), 0);
    }
};

/*
class Solution {
public:

// Brute Force

    bool isValid(vector<vector<int>>& grid, int r, int c, int n , int
expectVal){

         if(r <0 || c<0 || r >= n || c >= n || grid[r][c] !=expectVal){
            return false;
         }

         if(grid[r][c] == n*n -1) return true;

         int ans1 = isValid(grid, r-2, c+1, n, expectVal+1);
         int ans2 = isValid(grid, r-1, c+2, n, expectVal+1);
         int ans3 = isValid(grid, r+1, c+2, n, expectVal+1);
         int ans4 = isValid(grid, r+2, c+1, n, expectVal+1);
         int ans5 = isValid(grid, r+2, c-1, n, expectVal+1);
         int ans6 = isValid(grid, r+1, c-2, n, expectVal+1);
         int ans7 = isValid(grid, r-1, c-2, n, expectVal+1);
         int ans8 = isValid(grid, r-2, c-1, n, expectVal+1);

     return ans1||ans2||ans3||ans4||ans5||ans6||ans7||ans8;
    }

    bool checkValidGrid(vector<vector<int>>& grid) {
        return isValid(grid, 0,0, grid.size(), 0);
    }
};

*/