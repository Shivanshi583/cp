/**
Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).



Example 1:

Input: x = 123
Output: 321
Example 2:

Input: x = -123
Output: -321
Example 3:

Input: x = 120
Output: 21
Example 4:

Input: x = 0
Output: 0


Constraints:

-231 <= x <= 231 - 1 **/


class Solution {
public:
    int reverse(int x) {
        long int num=0;
        if(x>= 2147483647 || x<= -2147483647)
            return 0;
        if(x>0){
while(x>0){
num = num *10;
    if(num>= 2147483647 || num<= -2147483647)
            return 0;
num=num + (x%10);
x=x/10;

}
        }
        else{ x=-1*x;
            while(x>0){

            num = num *10;
                 if(num>= 2147483647 || num<= -2147483647)
            return 0;
num=num + (x%10);
x=x/10;
            }
            num = -1*num;
        }
        return int(num);

    }
};
