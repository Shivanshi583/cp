/**
grid 212. Word Search II
Hard

4688

161

Add to List

Share
Given an m x n board of characters and a list of strings words, return all words on the board.

Each word must be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.



Example 1:


Input: board = [["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]], words = ["oath","pea","eat","rain"]
Output: ["eat","oath"]
Example 2:


Input: board = [["a","b"],["c","d"]], words = ["abcb"]
Output: []


Constraints:

m == board.length
n == board[i].length
1 <= m, n <= 12
board[i][j] is a lowercase English letter.
1 <= words.length <= 3 * 104
1 <= words[i].length <= 10
words[i] consists of lowercase English letters.
All the strings of words are unique.
**/


class Trie{
    public:
    string word="";
    Trie* child[26];
    Trie(){
        this->word="";
       memset(child,NULL,sizeof(child));
    }

};

Trie* buildtree(vector<string>& words){
        Trie* root=new Trie();
        for(auto s:words){
            Trie* tmp=root;
            for(char c:s){
                int p=c-'a';
                if(tmp->child[p]==NULL) tmp->child[p]=new Trie();
                tmp=tmp->child[p];
            }
            tmp->word=s;
        }
        return root;
    }
    void dfs(int i,int j,Trie* root,vector<string>& ans,vector<vector<char>>& board){
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size()) return;
        char c=board[i][j];
        if(c=='$' || root->child[c-'a']==NULL) return;
        root=root->child[c-'a'];
        if(root->word.size()>0){
            ans.push_back(root->word);
            root->word="";
        }
        board[i][j]='$';
        dfs(i,j-1,root,ans,board);
        dfs(i,j+1,root,ans,board);
        dfs(i-1,j,root,ans,board);
        dfs(i+1,j,root,ans,board);
        board[i][j]=c;
    }

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int n=board.size(),m=board[0].size();
        int p=words.size();
        Trie *root=buildtree(words);
        vector<string> ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                Trie* tmp=root;
                dfs(i,j,tmp,ans,board);
            }
        }
        return ans;
    }
};
