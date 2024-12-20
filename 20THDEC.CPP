/*2415. Reverse Odd Levels of Binary Tree
Solved
Medium
Topics
Companies
Hint
Given the root of a perfect binary tree, reverse the node values at each odd level of the tree.

For example, suppose the node values at level 3 are [2,1,3,4,7,11,29,18], then it should become [18,29,11,7,4,3,1,2].
Return the root of the reversed tree.

A binary tree is perfect if all parent nodes have two children and all leaves are on the same level.

The level of a node is the number of edges along the path between it and the root node.*/
/**
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
    TreeNode* reverseOddLevels(TreeNode* root) {
             queue<TreeNode*>pq;
             pq.push(root);
             bool flag=false;
             while(!pq.empty()){
                int size=pq.size();
                vector<TreeNode*>levelNodes;
                for(int i=0;i<size;i++){
                     TreeNode* temp=pq.front();
                     pq.pop();
                     levelNodes.push_back(temp);
                     if(temp->left){
                        pq.push(temp->left);
                     }
                     if(temp->right){
                        pq.push(temp->right);
                     }

                }
                if(flag){
                      for(int i=0,j=size-1;i<j;i++,j--){
                        swap(levelNodes[i]->val,levelNodes[j]->val);
                      }
                }
             flag=!flag;
             }
             return root;

    }
};