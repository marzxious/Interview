class TrieNode {
public:
    vector<TrieNode*> children;
    string word;
    bool isWord;
    TrieNode(){
        children = vector<TrieNode*>(26, NULL);
        isWord = false;
        word = "";
    }
};

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* curr = root;
        
        for( auto c : word) {
            if(curr->children[ c - 'a'] == NULL)
                curr->children[c - 'a'] = new TrieNode();
            
            curr = curr->children[c - 'a'];
        }
        
        curr->isWord = true;
        curr->word = word;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* curr = root;
        for(auto& c : word) {
            if(curr->children[c-'a'] == NULL)
                return false;
            curr = curr->children[c-'a'];
        }
        
        return curr->isWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        
        for(auto& c : prefix) {
            if(curr->children[c-'a'] == NULL)
                return false;
            
            curr = curr->children[c - 'a'];
        }
        
        return true;
    }
        
private:
    TrieNode* root;
};

