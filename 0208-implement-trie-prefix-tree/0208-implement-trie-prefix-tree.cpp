struct trie{
    vector<trie*> child;
    bool isEnd;

    trie(){
        child.assign(26,nullptr);
        isEnd=false;
    }
};

class Trie {
private:
    trie* root;

public:
    Trie() {
        root = new trie();
    }
    
    void insert(string word) {
        trie* currentNode = root;
        for(auto x:word){
            if(!currentNode->child[x-'a']){
                currentNode->child[x-'a'] = new trie();
            }
            currentNode = currentNode->child[x-'a'];
        }
        currentNode->isEnd = true;
    }
    
    bool search(string word) {
        trie* currentNode = root;
        for(auto x:word){
            if(!currentNode->child[x-'a']){
                return false;
            }
            currentNode = currentNode->child[x-'a'];
        }
        return currentNode->isEnd;
    }
    
    bool startsWith(string prefix) {
        trie* currentNode = root;
        for(auto x:prefix){
            if(!currentNode->child[x-'a']){
                return false;
            }
            currentNode = currentNode->child[x-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */