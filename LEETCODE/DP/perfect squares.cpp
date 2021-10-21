/**
279. Perfect Squares
Medium

5642

266

Add to List

Share
Given an integer n, return the least number of perfect square numbers that sum to n.

A perfect square is an integer that is the square of an integer; in other words, it is the product of some integer with itself. For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.



Example 1:

Input: n = 12
Output: 3
Explanation: 12 = 4 + 4 + 4.
Example 2:

Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.


Constraints:

1 <= n <= 104

**/

TOP-DOWN APPROACH

class Solution {
public:
    int dp[10001];
    int helper(int n){
        if(n<=3) return n;
        if(dp[n]!=-1) return dp[n];
        int ans=INT_MAX;

        for(int i=1;i*i<=n;i++){
            ans=min(ans,1+helper(n-i*i));
        }
        return dp[n]= ans;
    }
    int numSquares(int n) {
        memset(dp,-1,sizeof(dp));
        int ans=helper(n);
        return ans;

    }
};

//BOTTOM-UP APPROACH
class Solution {
public:
    int numSquares(int n) {
        if(n<=3) return n;
        int dp[n+1];
        memset(dp,0,sizeof(dp));
        dp[1]=1;dp[2]=2;dp[3]=3;
        for(int i=4;i<=n;i++){
            dp[i]=i;
            for(int j=1;j*j<=i;j++){
                dp[i]=min(dp[i],1+dp[i-j*j]);
            }
        }
        return dp[n];
    }
};
