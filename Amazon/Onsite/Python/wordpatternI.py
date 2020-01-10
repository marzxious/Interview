class Solution:
    """
    @param pattern: a string, denote pattern string
    @param teststr: a string, denote matching string
    @return: an boolean, denote whether the pattern string and the matching string match or not
    """
    def wordPattern(self, pattern, teststr):
        # hash table
        p = list(pattern)
        t = teststr.split()
        if len(p) != len(t):
            return False
        n = len(p)
        p2t = {}
        t2p = {}
        for i in range(n):
            if p[i] in p2t and t[i] in t2p:
                if p2t[p[i]] != t[i] or t2p[t[i]] != p[i]:
                    return False
            elif p[i] in p2t or t[i] in t2p:
                return False
            else:
                p2t[p[i]] = t[i]
                t2p[t[i]] = p[i]
        return True