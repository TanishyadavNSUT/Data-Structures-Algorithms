class Trienode{
    public:
    char ch;
    Trienode* children[26];
    bool isterminal;

    Trienode(char val){
        ch=val;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        isterminal=false;
    }

};


class Trie {

public:
    Trienode* root;
    
    /** Initialize your data structure here. */
    
    Trie() {
        root= new Trienode('\0');
    }

    void insertutil(Trienode* root, string word){
        if(word.length()==0){
            root->isterminal=true;
            return;
        }

        int index=word[0]-'a';
        Trienode* child;

        if(root->children[index]!=NULL){
            child=root->children[index];
        }
        else{
            child=new Trienode(word[0]);
            root->children[index]=child;
        }

        insertutil(child,word.substr(1));


    }




    /** Inserts a word into the trie. */
    void insert(string word) {
        insertutil(root,word);
    }

    bool searchutil(Trienode* root, string word){
        if(word.length()==0){
            return root->isterminal;
        }

        int index=word[0]-'a';
        Trienode* child;

        if(root->children[index]!=NULL){
            child=root->children[index];
        }
        else{
            return false;
        }

        return searchutil(child,word.substr(1));
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        return searchutil(root,word);
    }

    bool prefixutil(Trienode* root, string word){
        if(word.length()==0){
            return true;
        }

        int index=word[0]-'a';
        Trienode* child;

        if(root->children[index]!=NULL){
            child=root->children[index];
        }
        else{
            return false;
        }
        return prefixutil(child,word.substr(1));
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        return prefixutil(root,prefix);
    }
};
