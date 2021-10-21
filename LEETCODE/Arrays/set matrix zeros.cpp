/**
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's, and return the matrix.

You must do it in place.



Example 1:


Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]
Example 2:


Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]


Constraints:

m == matrix.length
n == matrix[0].length
1 <= m, n <= 200
-231 <= matrix[i][j] <= 231 - 1
 **/

 class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int R = 0,C = 0,n = matrix.size(),m = matrix[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0&& i==0)
                    R=1;
                if(matrix[i][j]==0&& j==0)
                    C=1;
                if(matrix[i][j]==0)
                    matrix[i][0] = matrix[0][j]= 0;
            }
        }
        for(int i=1;i<m;i++){
            if(matrix[0][i]==0){
                for(int j=1;j<n;j++){
                    matrix[j][i] = 0;
                }
            }
        }
        for(int i=1;i<n;i++){
            if(matrix[i][0]==0){
                for(int j=1;j<m;j++){
                    matrix[i][j] = 0;
                }
            }
        }
        if(R==1){
            for(int i=0;i<m;i++){
                matrix[0][i] = 0;
            }
        }
        if(C==1){
            for(int i=0;i<n;i++){
                matrix[i][0] = 0;
            }
        }
    }
};
