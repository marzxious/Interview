/*Use two hash sets to save the existed number and the pairs that has already been used.
*/

class Solution {
public:
    int twoSum(vector<int>& nums, int target) {
        int res = 0;
        if (nums.empty()) return res;
        unordered_set<int> dic;
        unordered_set<int> seen;
        for(int num : nums){
            if(dic.find(target - num) != dic.end()
               && seen.find(target-num) == seen.end()){
                ++res;
                seen.insert(num);
                seen.insert(target - num);
            }
            else if (dic.find(num) == dic.end())
                dic.insert(num);
        }
        return res;
    }
};
