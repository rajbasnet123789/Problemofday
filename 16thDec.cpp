/*3264. Final Array State After K Multiplication Operations I
Solved
Easy
Topics
Companies
Hint
You are given an integer array nums, an integer k, and an integer multiplier.

You need to perform k operations on nums. In each operation:

Find the minimum value x in nums. If there are multiple occurrences of the minimum value, select the one that appears first.
Replace the selected minimum value x with x * multiplier.
Return an integer array denoting the final state of nums after performing all k operations.
*/
//we use priority_queue
class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
         int n=nums.size();
         for(int i=0;i<n;i++){
               pq.push({nums[i],i});
         }
         while(k--){
               int mini=pq.top().first;
               int indx=pq.top().second;
               pq.pop();
               nums[indx]=mini*multiplier;
               pq.push({nums[indx],indx});

               
         }
         return nums;
    }
};