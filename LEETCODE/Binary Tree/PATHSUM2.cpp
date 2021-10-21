/**
Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths where each path's sum equals targetSum.

A leaf is a node with no children.



Example 1:


Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
Output: [[5,4,11,2],[5,8,4,5]]
Example 2:


Input: root = [1,2,3], targetSum = 5
Output: []
Example 3:

Input: root = [1,2], targetSum = 0
Output: []


Constraints:

The number of nodes in the tree is in the range [0, 5000].
-1000 <= Node.val <= 1000
-1000 <= targetSum <= 1000**/

/**
  struct TreeNode {
    int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
     **/

class Solution {
public:
    vector <vector<int>>VectorAnswer;
    void addThePath(TreeNode* root, int sum,vector<int>answer){
        if(root==NULL){
            return;
        }
        if(root->left==NULL && root->right==NULL && sum==root->val){
            //have reached the leaf node and the sum remaining is equal to it rhega
            answer.push_back(root->val);
            VectorAnswer.push_back(answer);
        }
        answer.push_back(root->val);
        addThePath(root->left,sum-root->val,answer);
         addThePath(root->right,sum-root->val,answer);



    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        addThePath(root,sum,{});
        return VectorAnswer;

    }
};
