/**
Given an array of strings strs, return the length of the longest uncommon subsequence between them. If the longest uncommon subsequence does not exist, return -1.

An uncommon subsequence between an array of strings is a string that is a subsequence of one string but not the others.

A subsequence of a string s is a string that can be obtained after deleting any number of characters from s.

For example, "abc" is a subsequence of "aebdc" because you can delete the underlined characters in "aebdc" to get "abc". Other subsequences of "aebdc" include "aebdc", "aeb", and "" (empty string).


Example 1:

Input: strs = ["aba","cdc","eae"]
Output: 3
Example 2:

Input: strs = ["aaa","aaa","aa"]
Output: -1


Constraints:

1 <= strs.length <= 50
1 <= strs[i].length <= 10
strs[i] consists of lowercase English letters.

**/

class Solution {
public:
        bool isSub(string a,string b){
                int l1=0,l2=0;
                while( l1<a.size()&&l2<b.size() ){
            if(a[l1]==b[l2]){
                l1++;
                l2++;
            }
            else{
                l1++;
            }
        }
        return l2==b.size();
    }

    int findLUSlength(vector<string>& strs) {
        int ans=-1;
        int n=strs.size();
        for(int i=0;i<n;i++){
            bool flag=1;
            for(int j=0;j<n;j++){
                if(i!=j){
                    if(isSub(strs[j],strs[i])){
                        flag=0;
                    }
                }
            }
            int len=strs[i].size();
            if(flag) ans=max(ans,len);
        }
        return ans;
    }
};
