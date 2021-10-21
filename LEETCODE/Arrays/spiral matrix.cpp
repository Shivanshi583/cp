/**
Given an m x n matrix, return all elements of the matrix in spiral order.



Example 1:


Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:


Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]


Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 10
-100 <= matrix[i][j] <= 100

**/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& a) {
        vector<int>ans;
        int n=a.size(),m=a[0].size();
        int l=0,r=m-1,u=0,d=n-1;
        while(l<=r&&u<=d){
            for(int j=l;j<=r;j++){
                ans.push_back(a[u][j]);
            }
            u++;
            for(int i=u;i<=d;i++){
                ans.push_back(a[i][r]);
            }
            r--;
            if(u<=d){
                for(int j=r;j>=l;j--){
                    ans.push_back(a[d][j]);
                }d--;

            }
            if(l<=r){
                for(int i=d;i>=u;i--){
                    ans.push_back(a[i][l]);
                }
                l++;
            }
        }
        return ans;

    }
};
