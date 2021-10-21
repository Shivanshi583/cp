/**
You are given several boxes with different colors represented by different positive numbers.

You may experience several rounds to remove boxes until there is no box left. Each time you can choose some continuous boxes with the same color (i.e., composed of k boxes, k >= 1), remove them and get k * k points.

Return the maximum points you can get.



Example 1:

Input: boxes = [1,3,2,2,2,3,4,3,1]
Output: 23
Explanation:
[1, 3, 2, 2, 2, 3, 4, 3, 1]
----> [1, 3, 3, 4, 3, 1] (3*3=9 points)
----> [1, 3, 3, 3, 1] (1*1=1 points)
----> [1, 1] (3*3=9 points)
----> [] (2*2=4 points)
Example 2:

Input: boxes = [1,1,1]
Output: 9
Example 3:

Input: boxes = [1]
Output: 1


Constraints:

1 <= boxes.length <= 100
1 <= boxes[i] <= 100
**/

class Solution {
public:
    vector<int> box;
    int A[101][101][101];
    int solve(int i, int j, int k) {
        if(i > j)
            return 0;

        if(A[i][j][k] != -1)
            return A[i][j][k];

        int count = 1;
        int x   = i + 1;
        while(x <= j && box[x] == box[x-1]) {
            x++;
            count++;
        }


        int result = pow(k+count, 2) + solve(x, j, 0);


        for(int m = x; m<=j; m++) {
            if(box[m] == box[i]) {
                result = max(result, solve(x, m-1, 0) + solve(m, j, k+count));
            }
        }

        return A[i][j][k] = result;
    }

    int removeBoxes(vector<int>& box) {
        this->box = box;
        memset(A, -1, sizeof(A));
        return solve(0, box.size()-1, 0);
    }
};
