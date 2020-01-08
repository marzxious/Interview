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
 
 3. 後序遍歷encode + 先序遍歷decode 
  後序遍歷: [L, R, Root] --> [3, 5, 4], [11, 13, 15], 6  [左子樹],[右子樹], 根 從後面看回來變成 根[右子樹][左子樹], 所以可以用類似solution 2先序遍歷的方式來decode
  只是方法從Root, L, R 變成 Root, R, L. 判斷上下界的方式則與solution 2一樣.


Note: BST 因為有左子樹小於根, 右子樹 大於根, 對任何的traversal, 重新排序之後 則變成中序遍歷 L, Root, R

 */

/* # 都用先序遍历*/
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
    
    //preorder deserialize : reconstrcut a node from top of q, l : lower bound of this node, u : upper bound of this node */
     TreeNode* preorder(queue<int>& q, int l, int u) {
        if(q.empty() || q.front() < l || q.front() > u) return NULL;
        TreeNode* root = new TreeNode(q.front()); q.pop();
        
         root->left = preorder(q, l, root->val);
         root->right = preorder(q, root->val, u);
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


/*後序遍歷encode + 先序遍歷decode*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res = postorder(root);
        cout<<res<<endl;
        return res;
    }
    // L, R, Root
    string postorder(TreeNode* root) {
        if(root == NULL) return "";
        string left = postorder(root->left);
        string right = postorder(root->right);
        string res = "";

        if(left!="") {
            res+=left;
            res.push_back(',');
        }

        if(right!="") {
            res+=right;
            res.push_back(',');
        }

        return res + to_string(root->val);

    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        auto res = split(data);
        TreeNode* root = preorder(res, INT_MIN, INT_MAX);
        return root;
    }

    // 從後面按照 Root, R, L的方式遍歷.
    TreeNode* preorder(vector<TreeNode*>& data, int l, int u)
    {
        if(data.size() ==0 || data.back()->val < l || data.back()->val > u) return NULL;

        TreeNode* root = data.back();
        data.pop_back();

        root->right = preorder(data, root->val, u);
        root->left = preorder(data, l, root->val);
        return root;
    }

private:
    vector<TreeNode*> split(string& data) {
        istringstream ss(data);
        string token;
        vector<TreeNode*> res;
        while(getline(ss, token, ',')) {
            res.push_back(new TreeNode(stoi(token)));
        }

        return res;
    }
};

