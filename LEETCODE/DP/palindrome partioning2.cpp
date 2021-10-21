/**
Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.



Example 1:

Input: s = "aab"
Output: 1
Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.
Example 2:

Input: s = "a"
Output: 0
Example 3:

Input: s = "ab"
Output: 1


Constraints:

1 <= s.length <= 2000
s consists of lower-case English letters only.
**/



class Solution {
public:
    int dp[2001];
    int temp[2001][2001];
    bool isPalindrome(int i,int j){
        return temp[i][j];
    }
    int Solve(int i , string &s, int n){
        if(i >= n){
            return 0;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        int ans = INT_MAX;
        for(int j = i; j < n; j++){
            if(isPalindrome(i,j)){
                ans = min(ans,Solve(j+1,s,n));
            }
        }

        dp[i] = (ans == INT_MAX) ? ans : ans + 1;
        return dp[i];
    }
    int minCut(string s) {
        memset(dp,-1,sizeof(dp));
        int n = s.length();
        for(int i = n-1; i >= 0; i--){
            for(int j = 0; j < n; j++){
                if(i > j){
                    temp[i][j] = 0;
                }
                else if(i == j){
                    temp[i][j] = 1;
                }
                else{
                    if(s[i] == s[j]){
                        temp[i][j] = i+1 == j ? 1 : temp[i+1][j-1];
                    }
                    else{
                        temp[i][j] = 0;
                    }
                }
            }
        }

        return Solve(0,s,s.length())-1;
    }
};
