/*494. Target Sum
Solved
Medium
Topics
Companies
You are given an integer array nums and an integer target.

You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.

For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
Return the number of different expressions that you can build, which evaluates to target.

 */
 //BRUTE FORCE 
 class Solution {
public:
    int helper(int in,vector<int>&nums,int target,int sum){
           if(in>=nums.size()){
                 if(sum==target){
                      return 1;
                 }
                 else
                 {
                    return 0;
                 }
           }
           int add=helper(in+1,nums,target,sum+nums[in]);
           int minus=helper(in+1,nums,target,sum-nums[in]);
           return add+minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        return helper(0,nums,target,sum);
    }
};
// USING MEMOIZATION
class Solution {
public:
    unordered_map<string, int> mp; // Memoization map

    int helper(int in, vector<int>& nums, int target, int sum) {
        // Base case: all elements processed
        if (in >= nums.size()) {
            return (sum == target) ? 1 : 0;
        }

        // Generate the memoization key
        string key = to_string(in) + "_" + to_string(sum);

        // Check if result is already computed
        if (mp.count(key)) {
            return mp[key];
        }

        // Recursive calls: Add or subtract the current number
        int add = helper(in + 1, nums, target, sum + nums[in]);
        int minus = helper(in + 1, nums, target, sum - nums[in]);

        // Store the result in the memoization map
        mp[key] = add + minus;

        return mp[key];
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        return helper(0, nums, target, 0);
    }
};
