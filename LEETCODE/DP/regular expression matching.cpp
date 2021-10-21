/**
10. Regular Expression Matching
Hard

6579

928

Add to List

Share
Given an input string s and a pattern p, implement regular expression matching with support for '.' and '*' where:

'.' Matches any single character.​​​​
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).



Example 1:

Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:

Input: s = "aa", p = "a*"
Output: true
Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
Example 3:

Input: s = "ab", p = ".*"
Output: true
Explanation: ".*" means "zero or more (*) of any character (.)".
Example 4:

Input: s = "aab", p = "c*a*b"
Output: true
Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore, it matches "aab".
Example 5:

Input: s = "mississippi", p = "mis*is*p*."
Output: false


Constraints:

1 <= s.length <= 20
1 <= p.length <= 30
s contains only lowercase English letters.
p contains only lowercase English letters, '.', and '*'.
It is guaranteed for each appearance of the character '*', there will be a previous valid character to match.

**/

class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.length(),m=p.length();
        int dp[n+1][m+1];
        dp[0][0]=1; //both length=0
        if(m) dp[0][1]=false;//length of s =0
        for(int i=1;i<=n;i++)//lkength of p=0
        {
            dp[i][0]=0;
        }
        for(int j=2;j<=m;j++)//base case
        {
            if(p[j-1]=='*')
                dp[0][j] = dp[0][j-2];
            else dp[0][j] = 0;
        }

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {

                if(p[j-1]=='.'|| p[j-1]==s[i-1]) dp[i][j] = dp[i-1][j-1];
                else if(p[j-1]=='*' && j>1){ //check characters  behind *
                    if(p[j-2]==s[i-1] || p[j-2]=='.'){
                        dp[i][j] = dp[i][j-2] || dp[i-1][j];
                    }
                    else{
                        dp[i][j] = dp[i][j-2];
                    }
                }
                else dp[i][j]=0;
            }
        }
        return dp[n][m];
    }
};
