class Solution {    
public:
    vector<int> criticalConnections(int nv, int ne, vector<vector<int>>& connections) {
        //Read connections
        if (connections.empty())
            return res;
        graph.resize(nv);
        vs = vector<int>(nv);
        low = vector<int>(nv);
        for(auto& c : connections){
            int u = c[0], v = c[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        //DFS traversing from node 0, with parent -1 (not existed)
        dfs(0,-1);
        for(auto i : artip)
            res.push_back(i);
        return res;
    }
    
private:
    vector<vector<int>> graph;
    vector<int> vs, low,res;
    set<int> artip;
    int timeStamp = 0;
    void dfs(int cur, int pre){
        if (vs[cur] > 0)
            return;
        vs[cur] = low[cur] = ++timeStamp;
        for(int node : graph[cur]){
            if (node == pre)
                continue;
            dfs(node, cur);
            low[cur] = min(low[cur], low[node]);
            if (low[node] >= vs[cur])
            {
               if (pre < 0 || (graph[cur].size() >= 2 && low[node] != vs[cur])) 
                   artip.insert(cur); 
            }
        }       
    }
};
