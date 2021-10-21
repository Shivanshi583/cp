/*8
45. Jump Game II
Medium

5888

223

Add to List

Share
Given an array of non-negative integers nums, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

You can assume that you can always reach the last index.



Example 1:

Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [2,3,0,1,4]
Output: 2


Constraints:

1 <= nums.length <= 104
0 <= nums[i] <= 1000

**/

class Solution {//time=O[n]
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int steps=0;
        int currentr=0;
        int maxr=0;
        for(int i=0;i<n-1;i++){
        maxr=max(maxr,i+nums[i]);
        if(i>=currentr){
            steps++;
            currentr=maxr;
            maxr=0;
        }
        }
        return steps;
    }
};
