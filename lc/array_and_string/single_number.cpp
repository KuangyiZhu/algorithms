#include<vector>
/*
Given an array of integers, every element appears twice except for one. Find that single one.
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int found = 0;
        for (int i = 0; i < nums.size(); i++) {
            found ^= nums[i];
        }
       return found; 

    }
};
