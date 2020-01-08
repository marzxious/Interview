class LogSystem {
public:
    LogSystem() {
        
    }
    
    void put(int id, string timestamp) {
        logs.emplace_back(id, timestamp);
    }
    
    vector<int> retrieve(string s, string e, string gra) {
        vector<int> res;
        int idx = indexes[gra];
        for(auto log : logs)
        {    
            string timestamp = log.second.substr(0, idx);
            if(s.substr(0, idx) <= timestamp &&  timestamp <= e.substr(0, idx))
                res.push_back(log.first);
        }
        
        return res;
    }
    
private:
    vector<pair<int, string>> logs;
    unordered_map<string, int> indexes {{"Year", 5} , {"Month", 8}, {"Day", 11}, 
                                        {"Hour", 14}, {"Minute", 17}, {"Second", 20}};
};
