

/*********************************************************************************************************************************************************************
You are given several logs that each log contains a unique id and timestamp. Timestamp is a string that has the following format: Year:Month:Day:Hour:Minute:Second, 
for example, 2017:01:01:23:59:59. All domains are zero-padded decimal numbers.

Design a log storage system to implement the following functions:

void Put(int id, string timestamp): Given a log's unique id and timestamp, store the log in your storage system.

int[] Retrieve(String start, String end, String granularity): Return the id of logs whose timestamps are within the range from start to end. Start and end all have the same format as timestamp. 
However, granularity means the time level for consideration. For example, start = "2017:01:01:23:59:59", end = "2017:01:02:23:59:59", granularity = "Day", it means that we need to find the logs within the range from Jan. 1st 2017 to Jan. 2nd 2017.
*/


// Method 1: Multimap
// Time Complexity: O(logN) put, O(#_of_id_in_the_result + logN ) retrive (worse case, all logs were in bound
// Space Complexity: O(N) map to hold logs
//
class LogSystem {
public:
    LogSystem() {
      
    }
    
    void put(int id, string timestamp) {
        mp[timestamp] = id;
    }
    
    vector<int> retrieve(string s, string e, string gra) {

         int index = idx[gra];
         if(index != -1)
         {
            s.replace(s.begin()+index, s.end(), mapping[gra].first);
            e.replace(e.begin()+index, e.end(), mapping[gra].second);
         }
        
         cout<<s<<","<<e<<endl;
         auto it_s = mp.lower_bound(s);
         auto it_e = mp.lower_bound(e); //point to next element. 
             
         vector<int> res;
         for(; it_s!=it_e; ++it_s)
             res.push_back((*it_s).second);
        
         if(it_e!=mp.end() && (*it_e).first ==e)
            res.push_back((*it_e).second);
        
         return res;
    }
    
    
private:
    map<string, int> mp;
    unordered_map<string, int> idx = {{"Year", 5}, {"Month", 8}, {"Day", 11}, {"Hour", 14}, {"Minute", 17}, {"Second", -1}};
    unordered_map<string, pair<string, string>> mapping {
        {"Year", {"00:00:00:00:00", "12:31:23:59:59"}},
        {"Month", {"00:00:00:00", "31:23:59:59"}},
        {"Day"  ,  {"00:00:00", "23:59:59"}},
        {"Hour" , {"00:00", "59:59"}},
        {"Minute", {"00", "59"}}  
    };
};

//Modified Map
//
// Time Complexity: O(1) put, O(N) retrive
// Space Complexity: O(N) to store log
//
class LogSystem {
public:
    LogSystem() {
        
    }
    
    void put(int id, string timestamp) {
        logs.push_back({id, timestamp});
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



