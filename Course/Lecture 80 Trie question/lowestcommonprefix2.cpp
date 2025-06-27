class Trienode{
    public:
    char ch;
    Trienode* children[26];
    int childcount;
    bool isterminal;

    Trienode(char val){
        ch=val;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        childcount=0;
        isterminal=false;
    }


};

class Trie{
    public:
    Trienode* root;

    Trie(){
        root=new Trienode('\0');
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
            root->childcount++;
        }

        insertutil(child,word.substr(1));
    }

    void insert(string word){
        insertutil(root,word);
    }

    void getprefix(Trienode* root,string word, string& ans){
        for(int i=0;i<word.length();i++){
            char ch=word[i];
            if(root->childcount==1){
                ans.push_back(ch);
                int index=ch-'a';
                root=root->children[index];
            }
            else{
                break;
            }
            if(root->isterminal){
                break;
            }
        }
    }
};

string longestCommonPrefix(vector<string> &arr, int n)
{
    Trie* t=new Trie();

    for(int i=0;i<n;i++){
        t->insert(arr[i]);
    }

    string str=arr[0];
    string ans="";
    t->getprefix(t->root,str,ans);
    return ans;



    
}