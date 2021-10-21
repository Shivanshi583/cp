/**
Given a string s, reverse the string according to the following rules:

All the characters that are not English letters remain in the same position.
All the English letters (lowercase or uppercase) should be reversed.
Return s after reversing it.



Example 1:

Input: s = "ab-cd"
Output: "dc-ba"
Example 2:

Input: s = "a-bC-dEf-ghIj"
Output: "j-Ih-gfE-dCba"
Example 3:

Input: s = "Test1ng-Leet=code-Q!"
Output: "Qedo1ct-eeLg=ntse-T!"


Constraints:

1 <= s.length <= 100
s consists of characters with ASCII values in the range [33, 122].
s does not contain '\"' or '\\'.


**/


class Solution {
public:
    string reverseOnlyLetters(string s) {

        stack<char>st;
        map<int,char>m;
        int n=s.length();
        for(int i=0;i<n;i++){
            if(s[i]>='a' &&s[i]<='z' || s[i]>='A' && s[i]<='Z'){
                st.push(s[i]);
            }
            else{
                m.insert({i,s[i]});
            }
        }
        string ans="";
        for(int i=0;i<n;i++){
            auto it=m.find(i);
            if(it!=m.end()){
                ans=ans+it->second;
            }
            else{
                ans=ans+st.top();
                st.pop();
            }


        }
        return ans;

    }
};
