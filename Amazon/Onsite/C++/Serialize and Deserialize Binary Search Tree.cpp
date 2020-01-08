/*
 這題我們可以使用3 種作法
 １．BST 也是一種binary tree, 我們可以承襲之前的做法 用level order traversal, 記住每個空孩子為#, 並用相同的方式反序解碼
 https://leetcode.com/problems/serialize-and-deserialize-binary-tree/

 2. BST 有左子樹小 右子樹大的特性, 那麼我們可以利用這個特性, 用preorder traversal 序列化與反序列化
    考慮一顆BST: preorder的順序是[Root, L, R] --> 6, [ 4, 3, 5],[13, 11, 15]  根[左子樹][右子樹]  難點在於怎麼知道這個節點 屬於左子樹 還是右子樹 ?
    我們知道 6 因為是根節點 所以沒有上下界, 數字可以是任何數, 4, 則有一個限制 一定要比6小, 3, 則一定要比6小, 5, 則是比4大,比6小.
    所以我們可以利用這個特性 每次traverse一個數字的時候, 去看看他在不在左右邊界裡面, 如果是的話 那麼他則屬於左/右子樹.

Example: 6 (root), INT_MIN < 4 < 6 (left child of 6), INT_MIN < 3 < 4 (left child of 4), 4 < 5 < 6 (right child of 4)

          6
	/   \
       4     13
      / \    / \
     3   5 11  15
 
 
 */

/* Solution 2 : Use Preorder to only to reconstrcut tree*/
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res = preorder(root);
        cout<<res<<endl;
        return res;
    }
    
    // Root L, R
    string preorder(TreeNode* root) {
        if(root == NULL) return "";
        string left = preorder(root->left);
        string right = preorder(root->right);
        return to_string(root->val)+","+left + ","+right;
    }
        
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        auto q = split(data);
        return preorder(q, INT_MIN, INT_MAX);
    }
    
    //preorder deserialize : reconstrcut a node from top of q, l : lower bound of this node, r : upper bound of this node */
     TreeNode* preorder(queue<int>& q, int l, int r) {
        if(q.empty() || q.front() < l || q.front() > r) return NULL;
        TreeNode* root = new TreeNode(q.front()); q.pop();
        
         root->left = preorder(q, l, root->val);
         root->right = preorder(q, root->val, r);p;
         return root;
    }
    
    
    queue<int> split(string data) {
        istringstream ss(data);
        string token;
        queue<int> res;
        while(getline(ss, token, ',')) {
           if(token=="") continue;
            res.push(stoi(token));    
        }
        return res;
    }
};

