/*承襲1的做法 但是現在要考慮上升序列跟下降序列,一樣在custom return type儲存需要的訊息*/

class Result {
public:
    int lcs_inc; //longest increasing subsequence from this node (include root)
    int lcs_dec; //longest decreasing subsequence from this node (include root)

    Result(int _lcs_inc, int _lcs_dec ): lcs_inc(_lcs_inc), lcs_dec(_lcs_dec) {}
    
};
class Solution {
public:
    int maxlcs;
    int longestConsecutive(TreeNode* root) {
        if(root==NULL) return 0; //特判
        maxlcs = 1;
        search(root);      
        return maxlcs;
    }
    
    //return result records value of longest increasing&decreasing subsequeuce from given node
    Result search(TreeNode* root){   
        if(root==NULL) return Result(0,0);
        
        int lcs_inc = 0;
        int lcs_dec = 0;
        
        auto left = search(root->left);
        auto right = search(root->right);
        
        //find longest increasing/decreasing subsequence from left/right subtree
        if(root->left!=NULL && root->left->val == root->val+1)
            lcs_inc = max(lcs_inc, left.lcs_inc);
        else if(root->left!=NULL && root->left->val == root->val-1)
            lcs_dec = max(lcs_dec, left.lcs_dec);
        
        if(root->right!=NULL && root->right->val == root->val+1)
            lcs_inc = max(lcs_inc, right.lcs_inc);
        else if(root->right!=NULL && root->right->val == root->val-1)
            lcs_dec = max(lcs_dec, right.lcs_dec);
               
        Result res(lcs_inc + 1, lcs_dec + 1);
        maxlcs = max(maxlcs, res.lcs_inc + res.lcs_dec -1); //注意這邊的計算方式
        
        return res;
    }
};
