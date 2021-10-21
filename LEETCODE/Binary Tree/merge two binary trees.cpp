/**
 Merge Two Binary Trees
Easy

5190

213

Add to List

Share
You are given two binary trees root1 and root2.

Imagine that when you put one of them to cover the other, some nodes of the two trees are overlapped while the others are not. You need to merge the two trees into a new binary tree. The merge rule is that if two nodes overlap, then sum node values up as the new value of the merged node. Otherwise, the NOT null node will be used as the node of the new tree.

Return the merged tree.

Note: The merging process must start from the root nodes of both trees.



Example 1:


Input: root1 = [1,3,2,5], root2 = [2,1,3,null,4,null,7]
Output: [3,4,5,5,4,null,7]
Example 2:

Input: root1 = [1], root2 = [1,2]
Output: [2,2]


Constraints:

The number of nodes in both trees is in the range [0, 2000].
-104 <= Node.val <= 104

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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {//t1 and t2 denotes root 1 and 2
        if(t1!=NULL && t2!=NULL){
            t1->val+=t2->val;
            t1->left=mergeTrees(t1->left,t2->left);
            t1->right=mergeTrees(t1->right,t2->right);
            return t1;
        }
        if(t1!=NULL){
            return t1;
        }
        if(t2!=NULL){
            return t2;
        }
        return t1;

    }
};
