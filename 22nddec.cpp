/*2940. Find Building Where Alice and Bob Can Meet
Solved
Hard
Topics
Companies
Hint
You are given a 0-indexed array heights of positive integers, where heights[i] represents the height of the ith building.

If a person is in building i, they can move to any other building j if and only if i < j and heights[i] < heights[j].

You are also given another array queries where queries[i] = [ai, bi]. On the ith query, Alice is in building ai while Bob is in building bi.

Return an array ans where ans[i] is the index of the leftmost building where Alice and Bob can meet on the ith query. If Alice and Bob cannot move to a common building on query i, set ans[i] to -1.*/
/* Approach : Priority Queue and hashing
1. First we can answer below basic queries for (i, j):
if i < j and heights[i] < heights[j], then Alice and Bob meet at j.
if i > j and heights[i] > heights[j], then Alice and Bob meet at i.
if i == j, then Alice and Bob already meet at i.

2. For the remaining queries, we create a map with key -> value pair as below
Max query index (i,j) -> {max Height(i,j), query number}
We are storing below info with above map :
a query (i, j) answer will be after index max(i,j).
height required for this query will be > (max(heights[i], heights[j])). 
answer will be stored at query number index.

3. Now we run a loop on heights array from left to right.
We check which queries can be answered by this height/ index.
For this, we will maintain a min heap of the form {maxHeight, query no}
and store queries which have max index < current index i.

Time : O(n + qlogq) // n - heights size, q - no of queries
Space : O(n + q)
*/
class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size();
        int totalQueries = queries.size();

        // to store queries ans
        vector<int> ans(totalQueries, -1);

        // Max query index -> max Height, query no
        unordered_map<int, vector<pair<int,int>>> mp;

        // min heap : maxHeight, query no
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        // 1 : answering basic queries and creating map for remaining
        for (int q=0; q<totalQueries; q++) {
            int i = queries[q][0];
            int j = queries[q][1];
            if (i < j && heights[i] < heights[j])
                ans[q] = j;
            else if (i > j && heights[i] > heights[j])
                ans[q] = i;
            else if (i == j)
                ans[q] = i;
            else
                mp[max(i, j)].push_back({max(heights[i], heights[j]), q});
        }
        // 2 : Use priority queue to handle remaining queries
        for (int i=0; i<n; i++) {
            // check which queries can be answered with index i
            while (!pq.empty() && pq.top().first < heights[i]) {
                ans[pq.top().second] = i;
                pq.pop();
            }
            // push queries with max index as i in min heap
            for (auto &it : mp[i])
                pq.push(it);
        }
        return ans;
    }
};