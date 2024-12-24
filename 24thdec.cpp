/*3203. Find Minimum Diameter After Merging Two Trees
Solved
Hard
Topics
Companies
Hint
There exist two undirected trees with n and m nodes, numbered from 0 to n - 1 and from 0 to m - 1, respectively. You are given two 2D integer arrays edges1 and edges2 of lengths n - 1 and m - 1, respectively, where edges1[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the first tree and edges2[i] = [ui, vi] indicates that there is an edge between nodes ui and vi in the second tree.

You must connect one node from the first tree with another node from the second tree with an edge.

Return the minimum possible diameter of the resulting tree.

The diameter of a tree is the length of the longest path between any two nodes in the tree.

 */

class Solution {
public:

    pair<int, int> bfs(const vector<vector<int>>& adjList, int start) {
        int n = adjList.size();
        vector<bool> vis(n, false);
        queue<pair<int, int>> q;

        q.push({start, 0});
        vis[start] = true;

        int fnode = start;
        int maxDistance = 0;

        while (!q.empty()) {
            int node = q.front().first;
            int distance = q.front().second;
            q.pop();

            for (int neighbor : adjList[node]) {
                if (!vis[neighbor]) {
                    vis[neighbor] = true;
                    q.push({neighbor, distance + 1});

                    if (distance + 1 > maxDistance) {
                        fnode = neighbor;
                        maxDistance = distance + 1;
                    }
                }
            }
        }

        return {fnode, maxDistance};
    }

    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n1 = edges1.size() + 1; 
        int n2 = edges2.size() + 1; 

        vector<vector<int>> adjList1(n1), adjList2(n2);

       
        for (auto it : edges1) {
            adjList1[it[0]].push_back(it[1]);
            adjList1[it[1]].push_back(it[0]);
        }

     
        for (auto it : edges2) {
            adjList2[it[0]].push_back(it[1]);
            adjList2[it[1]].push_back(it[0]);
        }

  
        auto [x1, _] = bfs(adjList1, 0);
        auto [x2, d1] = bfs(adjList1, x1);


        auto [y1, __] = bfs(adjList2, 0);
        auto [y2, d2] = bfs(adjList2, y1);

        int combined=(d1+1)/2+(d2+1)/2+1;
        return max({d1,d2,combined});
    }
};

