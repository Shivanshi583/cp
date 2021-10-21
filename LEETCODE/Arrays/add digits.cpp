/**
Add Digits
Easy

1385

1379

Add to List

Share
Given an integer num, repeatedly add all its digits until the result has only one digit, and return it.



Example 1:

Input: num = 38
Output: 2
Explanation: The process is
38 --> 3 + 8 --> 11
11 --> 1 + 1 --> 2
Since 2 has only one digit, return it.
Example 2:

Input: num = 0
Output: 0


Constraints:

0 <= num <= 231 - 1


Follow up: Could you do it without any loop/recursion in O(1) runtime?

**/
class Solution {
public:
    int addDigits(int num) {
        int sum=0;
        while(num>0){
            int r=num%10;
            sum+=r;
            num/=10;
        }
        if(sum>=10)
            return addDigits(sum);

        return sum;
    }
};

//without loops

class Solution {
public:
    int addDigits(int num) {
       while(num>9){
           int sum=0;
           while(num>0){
               sum+=num%10;
               num/=10;
           }
           num=sum;
       }
    return num;
    }
};


