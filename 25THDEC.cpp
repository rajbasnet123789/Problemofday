/**
515. Find Largest Value in Each Tree Row
Solved
Medium
Topics
Companies
Given the root of a binary tree, return an array of the largest value in each row of the tree (0-indexed).

 
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int>largest;
        if(root==NULL){
            return {};
        }
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
               int size=q.size();
               vector<int>LevelNodes(size);
               for(int i=0;i<size;i++){
                    TreeNode* temp=q.front();
                    LevelNodes[i]=temp->val;
                    q.pop();
                    if(temp->left){
                          q.push(temp->left);
                    }
                    if(temp->right){
                         q.push(temp->right);
                    }
               }
               largest.push_back((*max_element(LevelNodes.begin(),LevelNodes.end())));
        }
        return largest;
    }
};