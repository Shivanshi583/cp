
/**
Given a non-negative integer c, decide whether there're two integers a and b such that a2 + b2 = c.



Example 1:

Input: c = 5
Output: true
Explanation: 1 * 1 + 2 * 2 = 5
Example 2:

Input: c = 3
Output: false
Example 3:

Input: c = 4
Output: true
Example 4:

Input: c = 2
Output: true
Example 5:

Input: c = 1
Output: true


Constraints:

0 <= c <= 231 - 1
**/
class Solution {
public:
    bool judgeSquareSum(int c) {

        for(long a = 0;a*a <= c; a++){
            double b = sqrt(c-(a*a));
            if(b==(int)b){
                return true;
            }
        }
        return false;
    }
};

//or

class Solution {
public:
    bool judgeSquareSum(int c) {
        unordered_map<int,int> m;
        for(int a= 0;a <= 46340; a++){
            m[(a*a)]++;
            if(m.find(c - (a*a))!=m.end())return true;
        }
        return false;
    }
};




