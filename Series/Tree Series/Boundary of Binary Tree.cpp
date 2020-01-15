/* First traverse left, then leaf, then right */

class Solution {
public:
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
      vector<int> boundaries;
      if(root == NULL) return boundaries;
      boundaries.push_back(root->val);
      left(root->left, boundaries);
      leaf(root->left, boundaries);
      leaf(root->right, boundaries);
      right(root->right, boundaries);
      return boundaries;
    }
    
    void left(TreeNode* root, vector<int>& boundaries) {
        if(!root) return;
        if(root->left == NULL && root->right==NULL) return; //skip leaf
        boundaries.push_back(root->val);
        if(root->left == NULL) left(root->right, boundaries);
        else left(root->left, boundaries);
    }
    
    void right(TreeNode* root, vector<int>& boundaries) {
        if(!root) return;
        if(root->left == NULL && root->right == NULL) return; //skip leaf
        if(root->right == NULL) right(root->left, boundaries);
        else right(root->right, boundaries);
        boundaries.push_back(root->val);
    }
    
    void leaf(TreeNode* root, vector<int>& boundaries){
        if(!root) return;
        if(root->left == NULL && root->right == NULL) { 
            boundaries.push_back(root->val);
            return;
        }
        leaf(root->left,boundaries);
        leaf(root->right, boundaries);
        
    }
};
