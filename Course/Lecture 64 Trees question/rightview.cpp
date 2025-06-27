#include<iostream>
using namespace std;

class Solution
{
    public:
    //Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
       vector<int> ans;
   if(root==NULL){
       return ans;
   }
   map<int,int> m;
   queue<pair<Node*,int> > q;
   q.push(make_pair(root,0));
   
   while(!q.empty()){
       
       pair<Node*, int> temp=q.front();
       q.pop();
       Node* frontnode=temp.first;
       
       int vd=temp.second;
       if(m.find(vd)==m.end()){
           m[vd]=frontnode->data;
       }
       
       if(frontnode->right){
           q.push(make_pair(frontnode->right,vd+1));
       }
       if(frontnode->left){
           q.push(make_pair(frontnode->left,vd+1));
       }
   }
   
   for(auto i : m){
       ans.push_back(i.second);
   }
   return ans;
    }
};