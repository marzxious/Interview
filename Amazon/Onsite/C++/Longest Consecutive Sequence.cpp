/*暴力法 : sort array 找最長的 O(NLogN) where N = number of element
Challenge : Design an O(N)
Fan Propose use Union Find: 
When we visited a value n, we checked if the neighboring number n-1, n+1  exists, if it did, union them. The largest union subset is the  answer.*/ 

class UnionFind {
public:
    int find(int x){
        if(fathers[x].first == x) return x;
        return fathers[x].first = find(fathers[x].first);
    }

    void connect(int a, int b) {
        int father_a = find(a);
        int father_b = find(b);
        if(father_a != father_b ) {
            fathers[father_b].second += fathers[father_a].second;
            fathers[father_a].first = father_b;
        }
    }

    unordered_map<int, pair<int, int>> fathers;
};
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> exists;
        UnionFind uf;
        for(auto& n : nums) {
            exists.insert(n);
            uf.fathers[n] = {n, 1};
        }

        for(auto& n : nums){
            int left = n-1;
            int right = n+1;
            if(exists.count(left))
                uf.connect(n, n-1);
            if(exists.count(right))
                uf.connect(n, n+1);
        }
        int maxLen = 0;
        for(auto& elm : uf.fathers) {
            maxLen = max(maxLen, elm.second.second);
        }
        return maxLen;
    }
};
