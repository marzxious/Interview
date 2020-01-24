/* https://leetcode.com/problems/maximum-binary-tree/ */

class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return constructTree(nums, 0, nums.size()-1);
    }
    
    TreeNode* constructTree(vector<int>& nums, int start, int end){
        if(start > end) return NULL;
        if(start == end) {
            return new TreeNode(nums[start]);
        }
        int maxidx = findmax(nums,start, end);
        auto left = constructTree(nums, start, maxidx-1);
        auto right = constructTree(nums, maxidx+1, end);
        auto root = new TreeNode(nums[maxidx]);
        root->left = left;
        root->right = right;
        return root;
    }
    
    int findmax(vector<int>& nums, int start, int end) {
        int maxval = INT_MIN;
        int index = start;
        for(int i = start; i <=end; ++i) {
            if(nums[i] > maxval){
                index = i;
                maxval = nums[i];
            }
        }
        return index;
    }
};
