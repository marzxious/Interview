"""121. Word Ladder II 
从 end 到 start 做一次 BFS，并且把距离 end 的距离都保存在distance 中。
然后在从 start 到 end 做一次 DFS，每走一步必须确保离 end 的distance 越来越近。


1. 求最短路径： BFS
2. 求所有路径： DFS
3. 所以这道题的算法一定是BFS + DFS

4. 找a -> i， 纯粹BFS可以做，但是会有很多浪费
            a
         /    \
        b      c
       / \    / \
      d   e  f   g
      \   /  \  /
        h      i
        
    BFS求所有路径的问题，queue里面放的是一个路径。
    Level 1: [a]
    Level 2: [ab, ac]
    Level 3: [abd, abe, acf, acg]
    Level 4: [abdh, abeh, acfi, acgi]
    整个过程有很多的浪费。 比如一旦进入b， 就已经是没有必要了。
    
5. 纯粹DFS更糟糕，甚至会找不是最短的。BFS至少路径不会超过最优值。

6. BFS + DFS。 去掉a -> b这种情况。怎么去掉？

            a4
         /     \
        b5      c3
       / \     / \
      d6  e6  f2  g2
      \   /   \  /
        h7     i1
        
  b, c离 a 距离都是 1， 凭什么b就不行？ 需要判断离终点的distance多少。 
  b离终点越来越远。我要走一条路径，肯定是越走离终点越近。
  BFS只能保证离起点越走越来越远。 怎样判断离终点的距离呢？反过来做，从i出发。
  把所有的点离终点的距离保存起来，用哈希表，再去做BFS
  a -> ac -> acf  -> acfi
          \       \
           \        -> acgi
            -> acg
            
 从终点到起点做一次BFS
 再从起点到终点做一次DFS
 
"""
from collections import deque
class Solution:
    def findLadders(self, start, end, dict):
        # 起始和结束词汇不在词典里面，需要自己加进去。
        dict.add(start)
        dict.add(end)
        
        # 建立indexes的哈希表。 key是word pattern
        indexes = self.build_indexes(dict)
        
        # BFS建立distance的哈希表
        distance = self.bfs(end, indexes)
        
        # 初始路径
        path = [start]
        
        # 初始结果
        results = []
        
        # DFS找到结果。限制条件是下一次词典的distance必须是降序的。
        self.dfs(start, end, distance, indexes, path, results)
        
        return results
        
    '''
    这里寻找下一个变换单词的方法是建立 index， 
    即， 如果有一个单词 abc， 分别去掉第1,2,3个字符之后，
    把 abc 这个单词分别扔进 %bc, a%c, ab% 这三个不同的 key 的 hash 里。
    hash 里的 key 是去掉一个字符之后的 pattern， value 是一个 set，
    保存满足这个pattern 的所有单词。
    
    value是key的“下一个单词”的一个list。 
    key定义了下一个单词， 也就是key对应的value， 必须有什么pattern。
    当然我们挑value的时候，也就是key 对应的单词的时候， 
    是从题目给与的词典里面拿出来的。
    这样就保证我们在get_next_words的时候，得到的word是题目给与的词典里面的词。
    
    这里的逻辑是，如果要找到一个词的下一个词， 
    按照题目要求，这个词与下一个此只有一个char不同。那么我们for 循环，
    依次把每个char变成%, 然后这个用%替代一个以后的东东， 
    就是已经建立的indexes这个dict里面的key。 
    而这个key对应的value，就是满足“下一个词”要求的一个list。
    BFS需要把所有的词都拿出来，计算distance
    DFS需要把符合distance降序的每个词都拿出来做搜索
    ''''
    def build_indexes(self, dict):
        indexes = {}
        
        for word in dict:
            for i in range(len(word)):
                key = word[:i] + '%' + word[i + 1:]
                if key in indexes: 
                    indexes[key].add(word)
                else: 
                    indexes[key] = set([word])
                
        return indexes
    

    def get_next_words(self, word, indexes):
        words = []
        for i in range(len(word)):
            key = word[:i] + '%' + word[i + 1:]
            for w in indexes.get(key, []): 
                words.append(w)
            
        return words
    
    
    '''BFS利用哈希表，节省一层循环的模板'''
    def bfs(self, end, indexes):
        distance = {end: 0}
        queue = deque([end])
        
        while queue:
            word = queue.popleft()
            
            for next_word in self.get_next_words(word, indexes):
                if next_word not in distance:
                    distance[next_word] = distance[word] + 1
                    queue.append(next_word)
                    
        return distance
    
    
    def dfs(self, curt, target, distance, indexes, path, results):
        if curt == target:
            results.append(list(path))
            
            return
        
        for word in self.get_next_words(curt, indexes):
            if distance[word] != distance[curt] - 1: 
                continue
            
            path.append(word)
            self.dfs(word, target, distance, indexes, path, results)
            path.pop()
            
            
            
            