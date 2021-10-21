/**
79. Word Search
Medium

7364

280

Add to List

Share
Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.



Example 1:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true
Example 2:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true
Example 3:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false


Constraints:

m == board.length
n = board[i].length
1 <= m, n <= 6
1 <= word.length <= 15
board and word consists of only lowercase and uppercase English letters.


Follow up: Could you use search pruning to make your solution faster with a larger board?
**/


class Solution {
public:
    int n,m;
    bool dfs( int index,int i,int j,vector<vector<char>>& board,string& word){
        if(index==word.size()) return 1;
        if(i==n||i<0||j==m||j<0)
            return 0;
        if(board[i][j]!=word[index]) return 0;
        char c=board[i][j];
        board[i][j]='$';
        bool left=dfs(index+1,i,j-1,board,word);
             bool right=dfs(index+1,i,j+1,board,word);
             bool up=dfs(index+1,i-1,j,board,word);
             bool down=dfs(index+1,i+1,j,board,word);
        board[i][j]=c;
    return (left==1||right==1||up==1||down==1);



    }
    bool exist(vector<vector<char>>& board, string word) {
        n=board.size();
        m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                bool ans=dfs(0,i,j,board,word);
                if(ans==1)
                    return 1;

            }
        }

        return 0;



    }
};
