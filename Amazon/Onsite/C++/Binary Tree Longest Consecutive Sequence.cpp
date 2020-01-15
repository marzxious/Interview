/* First left (post-order), then leaf node, then right (pre-order)*/

class Solution {
public:
    int maxLcs;
    int longestConsecutive(TreeNode* root) {
        if(root == NULL) return 0;
        maxLcs = 1;
        search(root);
        return maxLcs;
    }

    int search(TreeNode* root) {

        if(root == NULL)
            return 0;

        if(root->left == NULL && root->right == NULL)
            return 1;

        int left = search(root->left);
        int right = search(root->right);
        int lcs_left = 1;

        if(root->left!=NULL && root->left->val == root->val+1)
            lcs_left += left;

        int lcs_right = 1;

        if(root->right!=NULL && root->right->val == root->val+1)
            lcs_right += right;

        int lcs = max(lcs_right, lcs_left);
        maxLcs = max(lcs, maxLcs);
        return lcs;
    }
};
