class Trie {
public:
    struct trieNode{
        bool isendofword;
        trieNode* children[26];
    };

    trieNode* getNode(){
        trieNode* newnode=new trieNode();
        newnode->isendofword=false;

        for(int i=0;i<26;i++){
            newnode->children[i]=NULL;
        }
        return newnode;
    }

    trieNode*root;
    Trie() {
        root=getNode();
    }
    
    void insert(string word) {
        trieNode * crawler=root;
        for(int i=0;i<word.size();i++){
            char ch=word[i];
            int idx=ch-'a';

            if(crawler->children[idx]==NULL){
                crawler->children[idx]=getNode();//a
            }
            crawler=crawler->children[idx];
        }
        crawler->isendofword=true;//e
    }
    
    bool search(string word) {
        trieNode * crawler=root;
        for(int i=0;i<word.size();i++){
            char ch=word[i];
            int idx=ch-'a';

            if(crawler->children[idx]==NULL){
                return false;
            }
            crawler=crawler->children[idx];
        }
       if(crawler!=NULL &&crawler->isendofword==true)return true;//e
       return false;
    }
    
    bool startsWith(string prefix) {
        int i=0;
         trieNode * crawler=root;
        for( i=0;i<prefix.size();i++){
            char ch=prefix[i];
            int idx=ch-'a';

            if(crawler->children[idx]==NULL){
                return false;
            }
            crawler=crawler->children[idx];
        }
       if(i==prefix.length())return true;
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