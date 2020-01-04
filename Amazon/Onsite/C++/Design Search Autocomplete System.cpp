class Data{
public:
    int count;
    string word;
    Data(string _word, int _count) : word( _word), count( _count) {}
    bool operator<( const Data& other) const
    { return count == other.count ? word > other.word : count < other.count; }
};

typedef priority_queue<Data, vector<Data>>  MaxHeap;



class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isword;
    unordered_map<string, int> freq;
      
    TrieNode() {
        isword = false;
    }
};

class Trie {
public:
    Trie(){
        root = new TrieNode();
    }
     
    void insert(const string& word, int freq) {
        TrieNode* curr = root;
        for(auto& c : word) {
            
            if(curr->children.find(c) == curr->children.end())
                curr->children[c] = new TrieNode();
            
            curr = curr->children[c];
            curr->freq[word]+=freq;
        }
        
        curr->isword = true;
    }
    
    vector<string> search(const string& prefix) {
        vector<string> res;
        TrieNode* curr = root;
        for(auto& c : prefix) {
            
            if(curr->children.find(c) == curr->children.end()) return res;
            curr = curr->children[c];
        }
        
        MaxHeap maxhp;
        for(auto& word : curr->freq)
            maxhp.emplace(word.first, word.second);
        
        for(int i = 0; !maxhp.empty() && i < 3; ++i)
        {   res.push_back(maxhp.top().word); maxhp.pop(); }
        
        return res;
    }
    
private:
    TrieNode* root;
};


class AutocompleteSystem {
public:
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        trie = new Trie();
        for(int i = 0; i < sentences.size(); ++i)
            trie->insert(sentences[i], times[i]);
    }
    
    vector<string> input(char c) {
        if(c == '#') {
            trie->insert(prefix, 1);
            prefix = "";
            res.clear();
            return res;
        }
        
        prefix+=c;
        auto res = trie->search(prefix);
        return res;
    }
private:
    Trie* trie;
    string prefix="";
    vector<string> res;
};

