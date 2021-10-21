/**
70. Climbing Stairs
Easy

8558

252

Add to List

Share
You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?



Example 1:

Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:

Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step


Constraints:

1 <= n <= 45

**/

//top-down approach

class Solution {
public:
    int dp[46];
    int solve(int n){
        if(n==0) return 0;
        if(n==1) return 1;
        if(n==2) return 2;
        if(dp[n]!=-1)
            return dp[n];
        int ans =solve(n-1)+solve(n-2);
        return dp[n]=ans;
    }
    int climbStairs(int n) {
        memset(dp,-1,sizeof(dp));
        return solve(n);


    }
};
