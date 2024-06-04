class TrieNode{
public:
    TrieNode *child[26];
    int countOccurances;
    int endCount;
    TrieNode(){
        countOccurances = 0;
        endCount = 0;
        for( auto &c : child){
            c = nullptr;
        }
    }
};

class Trie {
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode *p = root;
        for(auto &a : word){
            int temp = a-'a';
            if(!p->child[temp]) p->child[temp] = new TrieNode();
            p = p->child[temp];
            p->countOccurances += 1;
        }
        p->endCount += 1;
    }
    
    int countWordsEqualTo(string word) {
        TrieNode *p = root;
        for(auto &a : word){
            int temp = a-'a';
            if(p->child[temp]){
                p = p->child[temp];
            }else{
                return 0;
            }
        }
        return p->endCount;
    }
    
    int countWordsStartingWith(string prefix) {
        TrieNode *p = root;
        for(auto &a : prefix){
            int temp = a-'a';
            if(p->child[temp]){
                p = p->child[temp];
            }else{
                return 0;
            }
        }
        return p->countOccurances;
    }
    
    void erase(string word) {
        TrieNode *p = root;
        for(auto &a : word){
            int temp = a-'a';
            p = p->child[temp];
            p->countOccurances -= 1;
        }
        p->endCount -= 1;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * int param_2 = obj->countWordsEqualTo(word);
 * int param_3 = obj->countWordsStartingWith(prefix);
 * obj->erase(word);
 */