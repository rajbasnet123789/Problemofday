/*689. Maximum Sum of 3 Non-Overlapping Subarrays
Solved
Hard
Topics
Companies
Given an integer array nums and an integer k, find three non-overlapping subarrays of length k with maximum sum and return them.

Return the result as a list of indices representing the starting position of each interval (0-indexed). If there are multiple answers, return the lexicographically smallest one.

 */
 class Solution {
public:
    int t[20001][4]; // Memoization table

    // Helper function to compute the maximum sum using memoization
    int helper(int in, int count, vector<int>& subarray, int k) {
        if (count == 0) return 0; // Base case: no more subarrays to pick
        if (in >= subarray.size()) return INT_MIN; // Out of bounds

        if (t[in][count] != -1) return t[in][count]; // Use memoized result

        int take = subarray[in] + helper(in + k, count - 1, subarray, k); // Take current subarray
        int not_take = helper(in + 1, count, subarray, k); // Skip current subarray

        return t[in][count] = max(take, not_take); // Memoize and return
    }

    // Solve function to reconstruct indices of selected subarrays
    void solve(int count, int k, int i, vector<int>& subarray, vector<int>& result) {
        if (count == 0) return; // Base case: no more subarrays to pick
        if (i >= subarray.size()) return; // Out of bounds

        int take = subarray[i] + helper(i + k, count - 1, subarray, k);
        int not_take = helper(i + 1, count, subarray, k);

        if (take >= not_take) {
            result.push_back(i); // Include current subarray index
            solve(count - 1, k, i + k, subarray, result); // Move to next valid subarray
        } else {
            solve(count, k, i + 1, subarray, result); // Skip current subarray
        }
    }

    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        memset(t, -1, sizeof(t)); // Initialize memoization table

        int n = nums.size();
        vector<int> subarray(n - k + 1); // Store sums of subarrays of size k
        int sum = 0, i = 0, j = 0;

        // Calculate subarray sums using sliding window
        while (j < n) {
            sum += nums[j];
            if (j - i + 1 == k) { // Window size equals k
                subarray[i] = sum; // Store sum of the current window
                sum -= nums[i]; // Slide the window
                i++;
            }
            j++;
        }

        vector<int> result;
        solve(3, k, 0, subarray, result); // Find the indices of the three subarrays

        return result;
    }
};
