class TrieNode {
    public:
        bool isWord;
        TrieNode *child[26];
        TrieNode(){
            isWord = false;
            for( auto &a: child) a = nullptr;
        }
};

class WordDictionary {
    TrieNode* root;
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode * p = root;
        for( auto &i : word){
            if(!p->child[i-'a']) p->child[i-'a'] = new TrieNode();
            p = p->child[i-'a'];
        }
        p->isWord = true;
    }
    
    bool search(string word) {
        return helper(word, root);
    }
private:
    bool helper(string word, TrieNode* node, int index = 0){
        TrieNode* p = node;
        for (int i = index; i < word.length(); i++){
            if(word[i] == '.'){
                for(int j = 0; j < 26 ; j++){
                    if(p->child[j] && helper(word, p->child[j], i+1)){
                        return true;
                    }
                }
                return false;
            }
            if (p->child[word[i] - 'a'] == nullptr) {
                return false;
            }
            p = p->child[word[i] - 'a'];
        }
        return p && p->isWord;
        }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */