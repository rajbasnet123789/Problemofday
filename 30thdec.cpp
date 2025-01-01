/*2466. Count Ways To Build Good Strings
Solved
Medium
Topics
Companies
Hint
Given the integers zero, one, low, and high, we can construct a string by starting with an empty string, and then at each step perform either of the following:

Append the character '0' zero times.
Append the character '1' one times.
This can be performed any number of times.

A good string is a string constructed by the above process having a length between low and high (inclusive).

Return the number of different good strings that can be constructed satisfying these properties. Since the answer can be large, return it modulo 109 + 7.

 */
 class Solution {
public:
   int t[100001];
   const int MOD=1e9+7;
    int helper(int in, int low, int high, int zero, int one) {
        // Base case: Stop recursion when the length exceeds 'high'
        if (in > high) {
            return 0;
        }
         if(t[in]!=-1){
            return t[in];
         }
        // Count this string if its length is within the range [low, high]
        int count = (in >= low && in <= high) ? 1 : 0;
        
        // Recursive calls: Add zeros and ones to the current length
        count += helper(in + zero, low, high, zero, one);
        count += helper(in + one, low, high, zero, one);

        return t[in]=count%MOD;
    }

    int countGoodStrings(int low, int high, int zero, int one) {
        // Start recursion with initial length 0
        memset(t,-1,sizeof(t));
        return helper(0, low, high, zero, one);
    }
};
/*class Solution {
public:
    int t[100001]; // Memoization array
    const int MOD = 1e9 + 7; // Modulo for large numbers

    int helper(int in, int low, int high, int zero, int one) {
        // Base case: Stop recursion when the length exceeds 'high'
        if (in > high) {
            return 0;
        }

        // Return memoized result if already computed
        if (t[in] != -1) {
            return t[in];
        }

        // Initialize result for the current `in`
        t[in] = 0;

        // Include the current length if it's within the range [low, high]
        if (in >= low) {
            t[in] = 1;
        }

        // Add the results of recursive calls for `zero` and `one`
        t[in] = (t[in] + helper(in + zero, low, high, zero, one)) % MOD;
        t[in] = (t[in] + helper(in + one, low, high, zero, one)) % MOD;

        return t[in];
    }

    int countGoodStrings(int low, int high, int zero, int one) {
        // Initialize the memoization array to -1
        memset(t, -1, sizeof(t));

        // Start recursion from length 0
        return helper(0, low, high, zero, one);
    }
};
*/
