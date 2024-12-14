/*2762. Continuous Subarrays
Solved
Medium
Topics
Companies
Hint
You are given a 0-indexed integer array nums. A subarray of nums is called continuous if:

Let i, i + 1, ..., j be the indices in the subarray. Then, for each pair of indices i <= i1, i2 <= j, 0 <= |nums[i1] - nums[i2]| <= 2.
Return the total number of continuous subarrays.

A subarray is a contiguous non-empty sequence of elements within an array.*/


class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
           int i=0;
           int j=0;
           int n=nums.size();
           map<int,int>mpp;//we store in map so we can know the max and min both
           long long score=0;
           while(j<n){
                   mpp[nums[j]]++;
                while (!mpp.empty() && mpp.rbegin()->first - mpp.begin()->first > 2) {
                    mpp[nums[i]]--;
                    if(mpp[nums[i]]==0){
                        mpp.erase(nums[i]);//we remove the mpp element if it is not in the window
                    }
                    i++;
               }
               score+=j-i+1;
               j++;
           }
           return score;
    }
};