
/*

You are given a perfect binary tree where all leaves are on the same level, and every parent has two children. 
在每一個節點 如果有孩子 就把左孩子 next 指給右孩子, 如果現在的節點 有next,　則把節點的右孩子　指定給他的堂兄弟　next的左孩子.

T: O(N)
S: O(1)
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL) return NULL;
        
        //確定有沒有下一層:如果有 把左孩子next指定給右孩子
        if( root->right != NULL) {
            root->left->next = root->right;
            
            //如果root有兄弟(next), 把右孩子的next 指給兄弟的左孩子.
            if(root->next!=NULL){
                root->right->next = root->next->left;
            }
        }
        
        connect(root->left);
        connect(root->right);
        return root;
    }
};
