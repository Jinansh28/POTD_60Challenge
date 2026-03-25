#include<bits/stdc++.h>
using namespace std;


class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};


class Solution {
  public:
    void inorder(Node*root,int key, vector<Node*>&ans){
        
      if(!root) return;
      
      inorder(root->left,key,ans);
      if(root->data<key){ ans[0] = root;}
      else if(root->data>key){
          
          if(ans[1]==nullptr){ ans[1]=root;}
          else if(root->data < ans[1]->data){ans[1]=root;}
          
      }
      inorder(root->right,key,ans);
  }
  
    vector<Node*> findPreSuc(Node* root, int key) {
        
        
        if(!root) return {nullptr,nullptr};
        vector<Node*> ans(2,nullptr);
        inorder(root,key,ans);
        return ans;
        
    }
};