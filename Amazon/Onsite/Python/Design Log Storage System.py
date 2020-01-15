class LogSystem:

    def __init__(self):
        # list is ok
        self.logs = []
        self.g = {'Year': 0, 'Month':1, 'Day':2, 'Hour': 3, 'Minute':4, 'Second':5}
    def put(self, id: int, timestamp: str) -> None:
        self.logs.append([id, timestamp])

    def retrieve(self, s: str, e: str, gra: str) -> List[int]:
        res = []
        s = s.split(':')
        s = s[:self.g[gra]+1]
        e = e.split(':')
        e = e[:self.g[gra]+1]
        for log in self.logs:
            if self.check(log[1], s, e, gra):
                res.append(log[0])
        return res
    
    def check(self, time, s, e, gra):
        time = time.split(':')
        time = time[:self.g[gra]+1]
        return s <= time <= e