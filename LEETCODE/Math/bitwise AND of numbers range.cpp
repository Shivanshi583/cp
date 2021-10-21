/**
201. Bitwise AND of Numbers Range
Medium

1956

167

Add to List

Share
Given two integers left and right that represent the range [left, right], return the bitwise AND of all numbers in this range, inclusive.



Example 1:

Input: left = 5, right = 7
Output: 4
Example 2:

Input: left = 0, right = 0
Output: 0
Example 3:

Input: left = 1, right = 2147483647
Output: 0


Constraints:

0 <= left <= right <= 231 - 1

**/

class Solution {
public:
    int msb(int n){
        int x=0;
        while(n){
            x++;
            n/=2;
        }
        return x-1;
    }
    int rangeBitwiseAnd(int a, int b) {
        int ans=0;
        while(a&&b){
            int msb_a=msb(a);
            int msb_b=msb(b);
            if(msb_a!=msb_b)
                break;
            ans+=(1<<msb_a);
            a-=(1<<msb_a);
            b-=(1<<msb_b);
        }
        return ans;

    }
};
