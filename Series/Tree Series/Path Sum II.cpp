/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/* https://leetcode.com/problems/path-sum-ii/ */

class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        int currSum = 0;
        vector<int> currPath;
        findPath(root, currSum, sum, currPath);
        return res;
    }
    
    void findPath(TreeNode* root, int currSum, int target, vector<int>& currPath){
        
        if(!root) return;
        
        currSum+=root->val;
        currPath.emplace_back(root->val);
        
        if(!root->left && !root->right) {
            if(currSum == target) {
                res.emplace_back(currPath);
            }
        }
        
        findPath(root->left, currSum, target, currPath);
        findPath(root->right, currSum, target, currPath);
        currPath.pop_back();
        currSum-=root->val;   
    }
};
