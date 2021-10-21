/*
Given a string text, you want to use the characters of text to form as many instances of the word "balloon" as possible.

You can use each character in text at most once. Return the maximum number of instances that can be formed.



Example 1:



Input: text = "nlaebolko"
Output: 1
Example 2:



Input: text = "loonbalxballpoon"
Output: 2
Example 3:

Input: text = "leetcode"
Output: 0


Constraints:

1 <= text.length <= 104
text consists of lower case English letters only.

*/

class Solution {
public:
    int maxNumberOfBalloons(string text)
    {
        unordered_map<char,int> mp;
        for(int i=0;i<text.length();i++)
        {
            mp[text[i]]++;
        }
        int ans=INT_MAX;
        ans=min(ans,mp['b']);
        ans=min(ans,mp['a']);
        ans=min(ans,mp['l']/2);
        ans=min(ans,mp['o']/2);
        ans=min(ans,mp['n']);
        return ans;
    }
};
