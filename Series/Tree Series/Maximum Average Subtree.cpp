/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//https://leetcode.com/problems/maximum-average-subtree/ 

class Result{
public:
    int sum;
    int count;
    Result(int _sum, int _count) : sum(_sum), count(_count) {}
};
class Solution {
public:
    double maxAvg;
    double maximumAverageSubtree(TreeNode* root) {
        if(!root) return 0.0;
        maxAvg = 0.0;
        auto res = maxSumSubtree(root);
        maxAvg = max(maxAvg, (double)res.sum/res.count);
        return maxAvg;
    }
    //return sum of this tree, & node of this tree starting from root
    Result maxSumSubtree(TreeNode* root) {
        if(!root) return Result(0.0, 0);
        if(!root->left && !root->right) {
            maxAvg = max(maxAvg, (double)root->val);
            return Result(root->val, 1);
        }
        
        auto left = maxSumSubtree(root->left);
        auto right = maxSumSubtree(root->right);
        int sum = root->val + left.sum + right.sum;
        int count = 1 + left.count + right.count;
        maxAvg = max(maxAvg, (double)sum/(double)count);
        return Result(sum, count);
    }
};
