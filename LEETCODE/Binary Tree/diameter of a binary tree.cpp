/**543. Diameter of Binary Tree
Easy

6158

381

Add to List

Share
Given the root of a binary tree, return the length of the diameter of the tree.

The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

The length of a path between two nodes is represented by the number of edges between them.



Example 1:


Input: root = [1,2,3,4,5]
Output: 3
Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].
Example 2:

Input: root = [1,2]
Output: 1


Constraints:

The number of nodes in the tree is in the range [1, 104].
-100 <= Node.val <= 100
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
    int ans=0;
    int helper(TreeNode*root,int& h){
        if(!root) return 0;
        int lh=0;int rh=0;
        lh=helper(root->left,lh);
        rh=helper(root->right,rh);
        h=max(lh,rh)+1;
        ans=max(ans,lh+rh);
        return h;

    }
    int diameterOfBinaryTree(TreeNode* root) {
        int h=0;
        if(root==NULL)
        return 0;
        helper(root,h);
        return ans;

    }
};
