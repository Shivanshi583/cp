/**
n input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).



Example 1:

Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:

Input: s = "aa", p = "*"
Output: true
Explanation: '*' matches any sequence.
Example 3:

Input: s = "cb", p = "?a"
Output: false
Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.
Example 4:

Input: s = "adceb", p = "*a*b"
Output: true
Explanation: The first '*' matches the empty sequence, while the second '*' matches the substring "dce".
Example 5:

Input: s = "acdcb", p = "a*c?b"
Output: false


Constraints:

0 <= s.length, p.length <= 2000
s contains only lowercase English letters.
p contains only lowercase English letters, '?' or '*'.

**/

class Solution {
public:
    bool isMatch(string s, string p) {
        if(p.length()==0)
            return (s.length()==0);
        vector<vector<int>> dp(s.length()+1,vector<int>(p.length()+1,0));
        dp[0][0]=1;
        for(int i=1;i<=p.length();i++)
        {
            if(p[i-1]=='*')
                dp[0][i]=1;
            else
                break;
        }
        for(int i=1;i<=s.length();i++)
        {
            for(int j=1;j<=p.length();j++)
            {
                if(p[j-1]=='*')
                {
                    dp[i][j]=dp[i-1][j] || dp[i][j-1];
                }
                else if(p[j-1]==s[i-1] || p[j-1]=='?')
                {
                    dp[i][j]=dp[i-1][j-1];
                }
            }
        }
        return dp[s.length()][p.length()];

    }

};
