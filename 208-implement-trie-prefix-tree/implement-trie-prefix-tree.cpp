class TrieNode {
    public:
        bool isWord;
        TrieNode *child[26];
        TrieNode(){
            isWord = false;
            for( auto &a: child) a = nullptr;
        }
};

class Trie {
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode * p = root;
        for( auto &i : word){
            if(!p->child[i-'a']) p->child[i-'a'] = new TrieNode();
            p = p->child[i-'a'];
        }
        p->isWord = true;
    }
    
    bool search(string word, bool prefix = false) {
        TrieNode * p = root;
        for( auto &i : word){
            if(!p->child[i-'a']) return false;
            p = p->child[i-'a'];
        }
        if(prefix == false) return p->isWord;
        return true;
    }
    
    bool startsWith(string prefix) {
        return search(prefix, true);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */