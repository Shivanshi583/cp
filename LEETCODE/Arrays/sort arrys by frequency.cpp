/**
451. Sort Characters By Frequency
Medium

3308

165

Add to List

Share
Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.

Return the sorted string. If there are multiple answers, return any of them.



Example 1:

Input: s = "tree"
Output: "eert"
Explanation: 'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
Example 2:

Input: s = "cccaaa"
Output: "aaaccc"
Explanation: Both 'c' and 'a' appear three times, so both "cccaaa" and "aaaccc" are valid answers.
Note that "cacaca" is incorrect, as the same characters must be together.
Example 3:

Input: s = "Aabb"
Output: "bbAa"
Explanation: "bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.


Constraints:

1 <= s.length <= 5 * 105
s consists of uppercase and lowercase English letters and digits.
**/

//TC=O(NLOGN)
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        for(auto x:s) mp[x]++;
        vector<pair<char,int>> v;
        for(auto x:mp) v.push_back({x.first,x.second});
        sort(v.begin(),v.end(),[&](auto a, auto b){
           return a.second>b.second;
        });
        string ans="";
        for(auto x:v){
            for(int i=1;i<=x.second;i++) {
                ans.push_back(x.first);
            }
        }
        return ans;
    }
};

//TC=O(N)
//USING BUCKET SORT
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        for(auto x:s) mp[x]++;
        int n=s.size();
        vector<vector<char>>bucket(n+1);
        for(auto x:mp){
            bucket[x.second].push_back(x.first);
        }
        string ans="";
        for(int f=n;f>=1;f--){
            for(char c:bucket[f]){
                ans+=string(f,c);
            }
        }
        return ans;
    }
};
