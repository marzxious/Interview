class Solution {
public:
    int maxUniTreeCounts;
    int countUnivalSubtrees(TreeNode* root) {
        if(root == NULL) return 0;
        maxUniTreeCounts = 0; 
        search(root);        
        return maxUniTreeCounts;
    }

    //given a node, return if this tree is unitree
    bool search(TreeNode* root) {
        
        if(root == NULL) return true;
        auto left = search(root->left);
        auto right = search(root->right);
        
        if(left&&right) {
            if((root->left!=NULL && root->left->val != root->val)  || (root->right!=NULL && root->right->val!= root->val))
                return false;
            maxUniTreeCounts++;            
            return true;
        }
        
        return false;
    }
};
