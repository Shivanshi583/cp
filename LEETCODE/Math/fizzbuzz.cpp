/*8
Fizz Buzz  -Adobe
Easy

1574

1742

Add to List

Share
Given an integer n, return a string array answer (1-indexed) where:

answer[i] == "FizzBuzz" if i is divisible by 3 and 5.
answer[i] == "Fizz" if i is divisible by 3.
answer[i] == "Buzz" if i is divisible by 5.
answer[i] == i if non of the above conditions are true.


Example 1:

Input: n = 3
Output: ["1","2","Fizz"]
Example 2:

Input: n = 5
Output: ["1","2","Fizz","4","Buzz"]
Example 3:

Input: n = 15
Output: ["1","2","Fizz","4","Buzz","Fizz","7","8","Fizz","Buzz","11","Fizz","13","14","FizzBuzz"]


Constraints:

1 <= n <= 104
**/

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector <string> ans;
      int fizz=0;
        int buzz=0;
        for(int i =1;i<=n;i++){
            fizz++;
            buzz++;
            if(fizz==3&& buzz==5){
                ans.push_back("FizzBuzz");
                fizz=0;
                buzz=0;
            }
            else if(fizz==3){
                ans.push_back("Fizz");
                fizz=0;
            }
            else if(buzz==5){
                ans.push_back("Buzz");
                buzz=0;
            }
            else{
                ans.push_back(to_string(i));
            }
        }
        return ans;

    }
};


    ///without using if-else

    class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans(n);
        for(int i = 1; i <= n; i++) {
            ans[i - 1] = to_string(i);
        }
        for(int i = 2; i < n; i += 3) {
            ans[i] = "Fizz";
        }
        for(int i = 4; i < n; i += 5) {
            ans[i] = "Buzz";
        }
        for(int i = 14; i < n; i += 15) {
            ans[i] = "FizzBuzz";
        }
        return ans;
    }
};
