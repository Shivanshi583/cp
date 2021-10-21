/**
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".



Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.


Constraints:

1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lower-case English letters.
**/
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int c=0 ,minlen=250;
        string minstr;
        for(int i=0;i< strs.size();i++)
        {
            int n=strs[i].length();
            if(n<minlen)
                minlen=n;
            minstr=strs[i];

        }
        for(int i=0;i<minlen;i++){
            for(int j=0;j<strs.size();j++){
                if(strs[j][i]!=minstr[i]){
                    return minstr.substr(0,c);
                }

            }
            c++;
        }
        return minstr.substr(0,c);

    }
};
