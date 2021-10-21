/**
Valid Palindrome
Easy

2456

4346

Add to List

Share
Given a string s, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.



Example 1:

Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.
Example 2:

Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.


Constraints:

1 <= s.length <= 2 * 105
s consists only of printable ASCII characters.


**/

class Solution {
public:
    bool isPalindrome(string s) {
        if(s.length()<=1){
            return true;
        }
        int st=0;int en=s.length()-1;
        while(st<en){
            while(st<en && !isalnum(s[st]))
                st++;
                while(st<en && !isalnum(s[en]))
                    en--;
                    if(st<en &&tolower(s[st])!=tolower(s[en]))
                        return false;
                    st++;
                    en--;


        }
        return true;

    }
};
