class Node:
    def __init__(self):
        self.children = {}
        self.isword = False
        self.top3 = collections.defaultdict(list) # store index of top3 words []
class Trie:
    def __init__(self):
        self.root = Node()
        
    def add(self, word, wordlist, worddict):
        cur = self.root
        idx = worddict[word][0] # idx
        for w in word:
            if w not in cur.children:
                cur.children[w] = Node()
                cur.top3[w].append(idx)
            else:
                if idx not in cur.top3[w]: cur.top3[w].append(idx)
                cur.top3[w].sort(key = lambda x: (-worddict[wordlist[x]][1], wordlist[x])) # -freq, word
                if len(cur.top3[w]) > 3: cur.top3[w].pop()
            cur = cur.children[w]
        cur.isword = True
        
class AutocompleteSystem(object):
    def __init__(self, sentences, times):
        self.t = Trie()
        n = len(sentences)
        self.wordlist = sentences # list, wordlist[idx] = word
        self.worddict = {}        # dict, worddict[word] = [idx, freq]
        for idx in range(n):
            self.worddict[sentences[idx]] = [idx, times[idx]]
            self.t.add(sentences[idx], self.wordlist, self.worddict)
        self.cur = self.t.root
        self.newword = []
        
    def input(self, c):
        if c == '#': 
            nw = ''.join(self.newword)
            if nw not in self.worddict:
                self.wordlist.append(nw)
                self.worddict[nw] = [len(self.wordlist)-1, 1]
            else:
                self.worddict[nw][1] += 1 # update freq
            self.t.add(nw, self.wordlist, self.worddict)
            # reset
            self.cur = self.t.root
            self.newword = []
            return []
        
        self.newword.append(c) # keep recording
        if self.cur and c in self.cur.children:
            res = [self.wordlist[idx] for idx in self.cur.top3[c]]
            self.cur = self.cur.children[c]
            return res
        else:
            self.cur = None # stop search
            return []