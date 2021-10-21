/**
Given an integer array nums that may contain duplicates, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.



Example 1:

Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
Example 2:

Input: nums = [0]
Output: [[],[0]]


Constraints:

1 <= nums.length <= 10
-10 <= nums[i] <= 10
**/
class Solution {
public:
    void bt(int i, vector<int>&nums,vector<int>&temp,vector<vector<int>>&ans,bool prev){
        if(i==nums.size()){
            ans.push_back(temp);
        }
        else{
            bt(i+1,nums,temp,ans,false);
            if(i>0 && nums[i]==nums[i-1]&&(!prev))
                return ;
            temp.push_back(nums[i]);
            bt(i+1,nums,temp,ans,true);

            temp.pop_back();

        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;  vector<int>temp;
        bt(0,nums,temp,ans,false);
        return ans;
    }
};
