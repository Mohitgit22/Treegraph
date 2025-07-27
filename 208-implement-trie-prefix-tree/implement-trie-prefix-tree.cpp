class Trie {
public:

    struct trieNode {
        trieNode* children[26];
        bool endofword;
    };

    trieNode* getNode() {
        trieNode* newNode = new trieNode();
        newNode->endofword = false;

        for(int i = 0; i < 26; i++){
            newNode->children[i] = NULL;
        }
        return newNode;
    }

     trieNode* root;
    Trie() {
      root = getNode();
    }
    
    void insert(string word) {
        trieNode* crawler = root;

        for(int i = 0; i < word.length(); i++){
            char ch = word[i];
            if(!crawler->children[ch-'a']){
               crawler ->children[ch-'a'] = getNode();
            }
              crawler = crawler ->children[ch-'a'];
        }
        crawler->endofword =true;
    }
    
    bool search(string word) {
        trieNode* crawler = root;
        for(int i = 0; i < word.length(); i++){
            int ind = word[i] - 'a';
               if(!crawler->children[ind])
               return false;

               crawler = crawler->children[ind];
        }
        return crawler->endofword and crawler!=nullptr;
    }
    
    bool startsWith(string prefix) {
        trieNode* crawler = root;
        int i = 0;
        for(i = 0; i < prefix.length(); i++){
            int ind = prefix[i] - 'a';
               if(!crawler->children[ind])
               return false;

               crawler = crawler->children[ind];
        }
        if( i == prefix.length())
        return true;
        return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */