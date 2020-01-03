/*

題意: 給一個整數n, 他有k個digit, 求剛比這個整數n大的 k個digit的數字, 其中這k個digit的數字數量要與n一樣 --> next permutation
example 1: 12 (兩位數), 下一個兩位數的整數, 由1, 2 組合而成 則為 21
example 2: 1243 (四位數), 下一個四位數的整數, 由 1, 2, 3, 4, 組成 則為 1, 3, 2, 4

intuition: 一個四個位數的整數3, 4, 5, 6 最小的 lexicographic order 是生序
Smallest : 3-4-5-6
Largest  : 6-5-4-3

因此知道從最小到最大 是一個由升序到降序的過程. 每次要求下一個最大的數字, 我們希望更動越後面的位元, 這樣改動後的數字變動最小
1234 --> 1243 --> 1324 -->1342
  -        -       -        -
next permuation :
1. 從後面找到降序起點(代表這部分已經排列是最大permutation) 
2. 降序起點的前一個位置是下一個permutation要考慮的位置.
3. 從後面找到第一個比下一個permutation大的數字, 進行交換
4. 交換後這段變成升序.(permutation 最小)
*/
class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        int next = s.length() - 1;
        for(; next >= 0; --next) {
            if(next == 0 || s[next-1] < s[next]) break;
        }
        
        if(next == 0) return -1; //降序 : already max permutation
        
        next = next-1;
        
        int i = s.length() - 1;
        for(; i > next; --i) {
            if(s[i] > s[next]) break;
        }
        
        swap(s, i, next);
        reverse(s.begin()+next+1, s.end());
        
        long res = 0;
        for(int i = 0; i < s.length(); ++i)
        {    res*=10; 
             res+= s[i] - '0';
        }
        
        if(res > 2147483647) return -1; //overflow check
    
        return res;
    }
    
    void swap(string& s, int i, int j) {
        char c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
};
