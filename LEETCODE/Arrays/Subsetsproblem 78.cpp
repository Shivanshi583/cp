/**
Given an integer array nums of unique elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.



Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
Example 2:

Input: nums = [0]
Output: [[],[0]]


Constraints:

1 <= nums.length <= 10
-10 <= nums[i] <= 10
All the numbers of nums are unique.
**/
class Solution {
public:
    void bt(int i, vector<int>&nums,vector<int>&temp,vector<vector<int>>&ans){
        if(i==nums.size()){
            ans.push_back(temp);
        }
        else{
            temp.push_back(nums[i]);
            bt(i+1,nums,temp,ans);

            temp.pop_back();
            bt(i+1,nums,temp,ans);
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;  vector<int>temp;
        bt(0,nums,temp,ans);
        return ans;
    }
};.
