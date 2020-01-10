/*
 *
 * Leetcode 原題 : https://leetcode.com/problems/minimum-cost-to-connect-sticks 
把所有的candidate加入heap裡面, 每次從heap裡找出最小的兩者相加 並把合成的stick 加回heap當作新的選項
 */


typedef priority_queue<int, vector<int>, greater<int>> MinHeap;
class Solution {
public:
    int connectSticks(vector<int>& sticks) {
      MinHeap hp;

      for(auto stick : sticks )
        hp.push(stick);

      int cost = 0;
      while(!hp.empty() && hp.size() > 1)
      {
        int a = hp.top(); hp.pop();
        int b = hp.top(); hp.pop();
        cost += (a + b);
        hp.push(a+b);
      }

      return cost;
    }
};
