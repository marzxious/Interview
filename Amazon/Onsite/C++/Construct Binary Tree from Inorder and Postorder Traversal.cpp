/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//
/* https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/ */


class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() == 0) return NULL;
        int index = inorder.size()-1;
        return constructTree(inorder, postorder, index, 0, inorder.size()-1);
    }
    
    TreeNode* constructTree(vector<int>& inorder, vector<int>& postorder, int& index, int start, int end) {
        if(start > end || index < 0) return NULL;
        if(start == end || index == 0) {
            auto root = new TreeNode(postorder[index]);
            index--;
            return root;
        }
 
        int val = postorder[index--];
        TreeNode* root = new TreeNode(val);

        int idx;
        for(idx=start ; idx <=end; idx++){
            if(inorder[idx]==val)
                break;
        }

        root->right = constructTree(inorder, postorder, index, idx+1, end);
        root->left = constructTree(inorder, postorder, index, start, idx-1);
        return root;
    }
};
