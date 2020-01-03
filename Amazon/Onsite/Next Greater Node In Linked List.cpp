/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 
 Exactly same solution with Next Greater Element I, II, except for linked list we need to store both index & val
 Time Complexity : O(N)
 Space Complexity : O(N) ->worst case of stack depth = N(decresing array)
 
 */
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        stack<pair<int,int>> stk; //store index
        vector<int> res;
        ListNode* curr = head;
        int i = 0;
        while(curr!=NULL)
        {
            while(!stk.empty() && stk.top().second < curr->val) {
                int idx = stk.top().first; stk.pop();
                res[idx] = curr->val;
            }
            stk.emplace(i, curr->val);
            res.push_back(0);
            i++;
            curr = curr->next;
        }
        
        return res;
    }
};
