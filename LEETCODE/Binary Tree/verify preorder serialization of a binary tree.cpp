/**
One way to serialize a binary tree is to use preorder traversal. When we encounter a non-null node, we record the node's value. If it is a null node, we record using a sentinel value such as '#'.


For example, the above binary tree can be serialized to the string "9,3,4,#,#,1,#,#,2,#,6,#,#", where '#' represents a null node.

Given a string of comma-separated values preorder, return true if it is a correct preorder traversal serialization of a binary tree.

It is guaranteed that each comma-separated value in the string must be either an integer or a character '#' representing null pointer.

You may assume that the input format is always valid.

For example, it could never contain two consecutive commas, such as "1,,3".
Note: You are not allowed to reconstruct the tree.



Example 1:

Input: preorder = "9,3,4,#,#,1,#,#,2,#,6,#,#"
Output: true
Example 2:

Input: preorder = "1,#"
Output: false
Example 3:

Input: preorder = "9,#,#,1"
Output: false


Constraints:

1 <= preorder.length <= 104
preoder consist of integers in the range [0, 100] and '#' separated by commas ','.
**/

//`removing the last two elements if  top element is a # while pushing another # and in the end if the only element is # ,it is valid
class Solution {
public:
    bool isValidSerialization(string preorder) {
        vector<char>stack;
        preorder += ",";
        for (int i = 0; i < preorder.size(); i++) {
            if (preorder[i] != ',') continue;
            stack.push_back(preorder[i - 1]);
            if (preorder[i - 1] == '#') {
                while (stack.size() > 2 && stack[stack.size() - 1] == '#' && stack[stack.size() - 2] == '#' && stack[stack.size() - 3] != '#') {
                    stack.pop_back();
                    stack.pop_back();
                    stack.pop_back();
                    stack.push_back('#');
                }
            }
        }
        return stack.size() == 1 && stack[0] == '#';
    }
};

