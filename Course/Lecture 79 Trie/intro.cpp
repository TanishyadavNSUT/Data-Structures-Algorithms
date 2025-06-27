#include<iostream>
using namespace std;

class Trienode{
    public:
        char data;
        Trienode *children[26];
        bool isterminal;

    Trienode(char val){
        data = val;
        for (int i = 0; i < 26;i++){
            children[i] = NULL;
        }
        isterminal = false;
    }
};

class Trie{
    public:
    Trienode *root;

    Trie(){
        root = new Trienode('\0');
    }

    void insertutil(Trienode* root, string word){
        if(word.length()==0){
            root->isterminal = true;
            return;
        }

        int index = word[0] - 'A';
        Trienode *child;

        if(root->children[index]!=NULL){
            child = root->children[index];
        }
        else{
            child = new Trienode(word[0]);
            root->children[index] = child;
        }

        insertutil(child, word.substr(1));
    }

    void insertword(string word){
        insertutil(root, word);
    }

    bool searchutil(Trienode* root, string word){
        if(word.length()==0){
            return root->isterminal;
        }

        int index = word[0] - 'A';
        Trienode *child;

        if(root->children[index]!=NULL){
            child = root->children[index];
        }
        else{
            return false;
        }

        return searchutil(child, word.substr(1));
    }

    bool searchword(string word){
        return searchutil(root, word);
    }

    void deleteutil(Trienode* root, string word){
        if(word.length()==0){
            root->isterminal = false;
            return;
        }

        int index = word[0] - 'A';
        Trienode *child;

        if(root->children[index]!=NULL){
            child = root->children[index];
        }
        else{
            cout << "element doesn't exist";
            return;
        }

        deleteutil(child, word.substr(1));
    }

    void deleteword(string word){
        deleteutil(root, word);
    }

};

int main(){

    Trie *t = new Trie();
    t->insertword("ABCD");
    t->insertword("TIME");
    t->insertword("ARM");
    t->insertword("DO");
    cout << "present or not " << t->searchword("ARM");
    cout << endl;
    t->deleteword("ARM");
    cout << "present or not " << t->searchword("ARM");

    return 0;
}