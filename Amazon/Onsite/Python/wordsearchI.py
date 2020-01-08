class Solution:
    """
    @param board: A list of lists of character
    @param word: A string
    @return: A boolean
    """
    def exist(self, board, word):
        # dfs
        row, col = len(board), len(board[0])
        if row == 0 or col == 0 or len(word) == 0: return False
        for i in range(row):
            for j in range(col):
                if board[i][j] == word[0] and self.dfs(board, i, j, word, 1, set([(i,j)])):
                    return True
        return False
        
    def dfs(self, board, x, y, word, pos, seen):
        if pos == len(word): return True
        row, col = len(board), len(board[0])
        for i,j in [(1,0),(0,1),(-1,0),(0,-1)]:
            nx, ny = i+x, j+y
            if 0 <= nx < row and 0 <= ny < col and (nx,ny) not in seen and word[pos] == board[nx][ny]:
                seen.add((nx,ny))
                if self.dfs(board, nx, ny, word, pos+1, seen):
                    return True
                seen.remove((nx,ny))
        return False