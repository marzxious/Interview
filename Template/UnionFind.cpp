/*
 * Union Find : Union (Connect Subsets, O(1)) Find( Check if two components are in same subset, O(1)
 * We add additional Sets to record members in the same subset
 *
 *
 *
 *
 *
 *
 */



class ConnectingGraph {
public:
    /*
    * @param n: An integer
    */ConnectingGraph(int n) {
    
      father.resize(n+1);
      groupnodes.resize(n+1);
     
      for(int i=1 ; i<=n; ++i)
      {
          father[i] = {i, i};
          groupnodes[i].push_back(i);
      }
    }

    //Connect : merge two subsets.
    void connect(int a, int b) {
        
        pair<int,int> father_a =  find(a); //O(1)
        pair<int,int> father_b =  find(b);
        
        if(father_a.first != father_b.first) {

            int subset_a_idx = father[father_a.first].second; 
            int subset_b_idx = father[father_b.first].second;
            
	    father[father_a.first].first = father_b.first;
            
            for(auto node : subsets[subset_a_idx] )
                subsets[subset_b_idx].push_back(node);

            subsets[subset_a_idx].clear();
            father[father_a.first].second = subset_b_idx;    
        }
    }
    
    vector<int> getnode(int a) {
      	vector<int> res;
	auto father_a = find(a);
	int subsetIdx = father_a.second;
	for(auto& node : subset[subsetIdx])
		res.push_back(node);
	return res;
    }

     bool query(int a, int b) {
        return find(a).first == find(b).first;
    }
private:
    int size;
    /* subset: used to record each subset member*/
    vector<vector<int>> subsets;   
    vector<pair<int, int>> father ; // pair[0] : father_label, pair[1]:index of subset for this node.
    
    //given x: return father_x & index of group node of father_x
    pair<int,int> find(int x)
    {
        if(father[x].first==x)
            return father[x];
        //順便做路徑壓縮 反正vector assign = O(1)  
        return father[x] = find(father[x].first);
    }
};
