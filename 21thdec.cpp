/*2872. Maximum Number of K-Divisible Components
Solved
Hard
Topics
Companies
Hint
There is an undirected tree with n nodes labeled from 0 to n - 1. You are given the integer n and a 2D integer array edges of length n - 1, where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the tree.

You are also given a 0-indexed integer array values of length n, where values[i] is the value associated with the ith node, and an integer k.

A valid split of the tree is obtained by removing any set of edges, possibly empty, from the tree such that the resulting components all have values that are divisible by k, where the value of a connected component is the sum of the values of its nodes.

Return the maximum number of components in any valid split.

 */
 class Solution {
public:
    long dfs(int node, int parentNode, vector<vector<int>>& adjList, vector<int>& values, int k, int& count) {
        long sum = 0;
        for (auto it : adjList[node]) {
            if (it != parentNode) {
                sum += dfs(it, node, adjList, values, k, count);
            }
        }
        sum += values[node];
        if (sum % k == 0) {
            count++;
            sum=0;
        }
        return sum;
    }

    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> adjList(n);
        for (auto edge : edges) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
        int count = 0;
        dfs(0, -1, adjList, values, k, count);
        return count;
    }
};
