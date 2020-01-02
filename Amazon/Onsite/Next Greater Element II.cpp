/*
 *
 * same approaches described as next greater element I, but to achieve cycle, we can eitehr append an array next to nums or iterate 2*times array length.
 * Time Complexity : O(N) , N defines as nums size
 * Space Complexity : O(N), maximum depth of stack is N
 * 
 *
 *
 */


class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1);
        stack<int> s;  //store index;
        for(int i = 0 ; i < 2*n; ++i) {
            while(!s.empty() && nums[s.top()] < nums[i%n]) {
                res[s.top()] = nums[i%n]; s.pop();
            }
            s.push(i%n);
        }
        
        return res;
    }
};
