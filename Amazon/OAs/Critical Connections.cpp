/*https://leetcode.com/problems/critical-connections-in-a-network/
Implement Tarjan's algorithm to solve the problem.
Intuition:
Rule out the edges in loops.
1. Build a graph with adjacent list method using the given connection information.
2. Set node 0 as the root node, utilize DFS to traverse the whole graph as a tree. Initialize a global timestamp to be 0,  increase the timestamp each time when we visit a new node, use a vector ("dfn") to save the visiting timestamps for each node. 
3. While doing DFS, set another vector ("low") to find the minimum visiting timestamp in his neighbors. Initialize the low value for each node with its visiting timestamp, compare it with the low value of its children nodes in the traversing tree, and update the low value of the current node as the minimum one. If the low value of a children node is greater than the visiting timestamp of the current node, then mark the edge between this children node and the current node as a critical connection, and push the pair of their indexes into the result.
*/

class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        dfn = vector<int>(n);
        low = vector<int>(n);
        graph.resize(n);
        //Read connections into a graph
        for(auto& c: connections) {
            int u = c[0], v = c[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        //DFS Traverse from the node 0, with its parent set into -1
        dfs(0, -1);
        return res;
    }
private:
    vector<vector<int>> graph, res;
    vector<int> dfn, low;
    int timestamp = 0;

    void dfs(int cur, int pre) {
        //If the timestamp is larget than 0, it means the current node is visited
        if(dfn[cur] > 0)
            return;
        //Initialize the visiting timestamp for current node
        dfn[cur] = low[cur] = ++timestamp;
        for(int next: graph[cur]) {
            if(next == pre) {
                continue;
            }
            dfs(next, cur);
            low[cur] = min(low[cur], low[next]);
            //If the low value of a children node > that of current node
            //This edge is a critical connection
            if(low[next] > dfn[cur]) {
                res.push_back({cur, next});
            }
        }
    }
};
