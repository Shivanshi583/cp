/**
Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must be unique and you may return the result in any order.



Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
Explanation: [4,9] is also accepted.


Constraints:

1 <= nums1.length, nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 1000
**/

#include<bits/stdc++.h>
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        unordered_map<int,int> hash;

        int n1 =(int)nums1.size();
        int n2 =(int)nums2.size();
        for(int i=0;i<n1;i++){
            hash[nums1[i]]++;

        }
        for(int i=0;i<n2;i++){
            if(hash[nums2[i]]!=0){
                result.push_back(nums2[i]);
                hash[nums2[i]]=0;
            }
        }
        return result;
    }
};
