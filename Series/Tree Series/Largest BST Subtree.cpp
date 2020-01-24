class Result{
public:
    bool isBST;
    int leftMin;
    int rightMax;
    int node;
    Result(bool _isBST, int _leftMin, int _rightMax, int _node):isBST(_isBST), leftMin(_leftMin), rightMax(_rightMax), node(_node) {}    
};
class Solution {
public:
    int maxnode;
    int largestBSTSubtree(TreeNode* root) {
        maxnode = 0;
        largestBST(root);
        return maxnode;
    }
    //largestBST : return a result with starting from root, largest value of right subtree  & minvalue ofleft subtree. both "include root" */
    Result largestBST(TreeNode* root) {
        if(!root) {return Result(true, INT_MAX, INT_MIN, 0);}
        if(!root->left && !root->right) {
            maxnode = max(maxnode, 1);
            return Result(true, root->val, root->val, 1);
        }
        auto left = largestBST(root->left);
        auto right = largestBST(root->right);
        int totalnode = 1 + left.node + right.node;

        if(left.isBST && right.isBST) {
            if(left.rightMax < root->val && right.leftMin > root->val) {
                maxnode = max(totalnode, maxnode);
                return Result(true, min(root->val, left.leftMin), max(root->val, right.rightMax), totalnode);
            }
        }
        return Result(false, min(root->val, left.leftMin), max(root->val, right.rightMax), totalnode);
    }
};
