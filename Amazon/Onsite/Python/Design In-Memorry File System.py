class Node:
    def __init__(self):
        self.folder = {} # self.folder[foldername] = Node()
        self.file = {} # self.file[fname] = 'content'
        
class FileSystem(object):
    def __init__(self):
        self.root = Node()

    def ls(self, path):
        path = path.split('/')
        path, cur = path[1:], self.root 
        if path == ['']: return sorted([k for k in cur.folder] + [v for v in cur.file])
        for i in range(len(path)):
            if path[i] in cur.folder: 
                cur = cur.folder[path[i]]
            elif i == len(path)-1 and path[i] in cur.file:  #If it is a file path,  return file's name. 
                return [path[i]]
            else:
                return []
        return sorted([k for k in cur.folder] +[v for v in cur.file])

    def mkdir(self, path):
        path = path.split('/')
        path, cur = path[1:], self.root 
        for p in path:
            if p not in cur.folder:
                cur.folder[p] = Node()
            cur = cur.folder[p]        

    def addContentToFile(self, filePath, content):
        path = filePath.split('/')
        mpath, fname, cur = path[1:-1], path[-1], self.root
        for p in mpath:
            if p not in cur.folder:
                cur.folder[p] = Node()
            cur = cur.folder[p] 
        cur.file[fname] = cur.file.get(fname, '') + content

    def readContentFromFile(self, filePath):
        path = filePath.split('/')
        mpath, fname, cur = path[1:-1], path[-1], self.root
        for p in mpath:
            cur = cur.folder[p]             
        return cur.file[fname]