class Solution {
public:

// Optimal Approach

    void reverse(vector<int>& matrix){
        int n = matrix.size();
        int left = 0, right = n-1;
        for(int i=0; i<n/2; i++){
             swap(matrix[left], matrix[right]);
             left++;
             right--;
        }
    }

    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
            reverse(matrix[i]);
        }
    }
};

/*
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> rotated(n, vector<int> (n));

        for(int i = 0; i< n; i++){
            for(int j =0; j<m; j++){
                rotated[j][n-i-1]= matrix[i][j];
            }
        }

        matrix = rotated;

    }
};

*/