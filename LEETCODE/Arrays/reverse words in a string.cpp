/**
151. Reverse Words in a String
Medium

2372

3591

Add to List

Share
Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.



Example 1:

Input: s = "the sky is blue"
Output: "blue is sky the"
Example 2:

Input: s = "  hello world  "
Output: "world hello"
Explanation: Your reversed string should not contain leading or trailing spaces.
Example 3:

Input: s = "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
Example 4:

Input: s = "  Bob    Loves  Alice   "
Output: "Alice Loves Bob"
Example 5:

Input: s = "Alice does not even like bob"
Output: "bob like even not does Alice"


Constraints:

1 <= s.length <= 104
s contains English letters (upper-case and lower-case), digits, and spaces ' '.
There is at least one word in s.

 **/

 //1. Reverse the whole string
	//2. put a blank space in front of the word if this word is not the first word
	//3. copy the word to the position starts with startIndex
	//4. reverse the word
    //5.update the possible start of next word
//delete extra charactyers

class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end()); //1
        int startIndex = 0;
        for (int l = 0; l < s.size(); l++) {
            if (s[l] != ' ') {
                if (startIndex != 0) s[startIndex++] = ' '; //2
                int r = l;
                while (r < s.size() && s[r] != ' ') { s[startIndex++] = s[r++]; } // 3
                reverse(s.begin() + startIndex - (r - l), s.begin() + startIndex); // 4
                l = r;
            }
        }

        s.erase(s.begin() + startIndex, s.end()); //6
        return s;
    }
};
