/*
 
https://leetcode.com/problems/reorder-data-in-log-files/
 
 
 
You have an array of logs.  Each log is a space delimited string of words.
For each log, the first word in each log is an alphanumeric identifier.  Then, either:

Each word after the identifier will consist only of lowercase letters, or;
Each word after the identifier will consist only of digits.
We will call these two varieties of logs letter-logs and digit-logs.  It is guaranteed that each log has at least one word after its identifier.

Reorder the logs so that all of the letter-logs come before any digit-log.  The letter-logs are ordered lexicographically ignoring identifier, with the identifier used in case of ties.  The digit-logs should be put in their original order.

Return the final order of the logs.
 
Input: logs = ["dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero"]
Output: ["let1 art can","let3 art zero","let2 own kit dig","dig1 8 1 5 1","dig2 3 6"]

思想: 把log分開成letter & digit log, sort letter log, then compare first with content , then identifier
考點: 字串處理, custom sort

 */


bool comp(const pair<string, string> lhs, const pair<string, string>& rhs) 
{
return lhs.second == rhs.second ? lhs.first < rhs.first : lhs.second < rhs.second;
}
class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
      
      vector<string> digit_log;
      vector<pair<string, string>> letter_log;
      vector<string> res;
      
      for(auto log : logs)
      {

          int i = log.find(' ');//first space
          
          if(isdigit(log[i+1])) 
            digit_log.emplace_back(log);
          else
            letter_log.emplace_back(log.substr(0, i), log.substr(i+1));
      }
             
      sort(letter_log.begin(), letter_log.end(), comp);
      
      for(auto log : letter_log)
      {
          string reformatted = log.first + " " + log.second;
          res.push_back(reformatted);
      }
      
      for(auto log : digit_log)
        res.push_back(log);
    
      return res;
    } 
};

