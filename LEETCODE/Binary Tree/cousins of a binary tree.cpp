/**
993. Cousins in Binary Tree
Easy

2195

119

Add to List

Share
Given the root of a binary tree with unique values and the values of two different nodes of the tree x and y, return true if the nodes corresponding to the values x and y in the tree are cousins, or false otherwise.

Two nodes of a binary tree are cousins if they have the same depth with different parents.

Note that in a binary tree, the root node is at the depth 0, and children of each depth k node are at the depth k + 1.



Example 1:


Input: root = [1,2,3,4], x = 4, y = 3
Output: false
Example 2:


Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
Output: true
Example 3:


Input: root = [1,2,3,null,4], x = 2, y = 3
Output: false


Constraints:

The number of nodes in the tree is in the range [2, 100].
1 <= Node.val <= 100
Each node has a unique value.
x != y
x and y are exist in the tree.

**/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int depth[101],par[101];
    void helper(TreeNode* root,TreeNode* p,int level){
        if(!root) return;
        depth[root->val]=level;
        par[root->val]=p->val;
        helper(root->left,root,level+1);
        helper(root->right,root,level+1);
    }
    bool isCousins(TreeNode* root, int x, int y) {
        memset(depth,-1,sizeof(depth));
        memset(par,-1,sizeof(par));
        TreeNode* p=new TreeNode(-1);
        helper(root,p,0);
        return (depth[x]==depth[y] && par[x]!=par[y]);
    }
};
