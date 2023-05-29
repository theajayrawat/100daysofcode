// Webpage:https://leetcode.com/problems/implement-trie-prefix-tree/description/

class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char val){
        data=val;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        isTerminal=false;
    }

};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root=new TrieNode('\0');
    }
    
    void insertUtil(TrieNode* root, string word)
    {
        if(word.size()==0)
        {
            root->isTerminal=true;
            return;
        }

        TrieNode* child;
        int index=word[0]-'a';

        if(root->children[index])
            child=root->children[index];
        else
        {
            child=new TrieNode(word[0]);
            root->children[index]=child;
        }

        insertUtil(child,word.substr(1));
    }

    void insert(string word) {
        insertUtil(root,word);
    }
    
    bool searchUtil(TrieNode* root, string word)
    {
        if(word.size()==0)
            return root->isTerminal;

        TrieNode* child;
        int index=word[0]-'a';

        if(root->children[index])
            child=root->children[index];
        else 
            return false;

        return searchUtil(child,word.substr(1));  
    }

    bool search(string word) {
        return searchUtil(root,word);
    }
    
    bool prefixUtil(TrieNode* root, string word)
    {
        if(word.size()==0)
            return true;

        TrieNode* child;
        int index=word[0]-'a';

        if(root->children[index])
            child=root->children[index];
        else 
            return false;

        return prefixUtil(child,word.substr(1));  
    }

    bool startsWith(string prefix) {
        return prefixUtil(root,prefix);
    }
};
