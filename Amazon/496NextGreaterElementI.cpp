
/*
題意: 找到nums1 樹駔 在nums2 數組的第一個比他大的數字. (排序不動)

Input: nums1 = [4,1,2], nums2 = [1,3,4,2].
Output: [-1,3,-1]
Explanation:
    For number 4 in the first array, you cannot find the next greater number for it in the second array, so output -1.
    For number 1 in the first array, the next greater number for it in the second array is 3.
    For number 2 in the first array, there is no next greater number for it in the second array, so output -1.


Solution:
	Monotonic Decreasing Stack --> We traverse num2, if traversed current number is greater than nums at stack top, then all numbers in the stack that is smaller than current number, has current number as next greater number. 

	Time Complexity : O(N) , where N as size of nums2
	Space Complexity : O(1) reuse nums1
*/
class Solution {
public:
	vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2){
		stack<int> stk;
		unordered_map<int, int> next; //key: curr, value : next greater number of curr
		for(auto& num : nums2){
			while(!stk.empty() && stk.top() < num){
				next[stk.top()] = num; stk.pop();
			}
			stk.push(num);
		}

		for(int i = 0; i < nums1.size(); ++i) {
			nums1[i] = next.find(nums[i]) == next.end() ? -1 : next[nums1[i]];
		}
		
		return nums1; 
	}
};
