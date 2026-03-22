#include<bits/stdc++.h>
using namespace std;


class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


class Solution {
  public:
    int minTime(Node* root, int target) {
        // code here
        unordered_map<Node *, Node *> m;
        unordered_map<Node *, bool > vis;
        
        queue<Node*> q;
        q.push(root);
        m[root] = NULL;
        
        Node * t;
        
        while(!q.empty()){
            Node * str = q.front();
            q.pop();
            vis[str] = false;
            
            if(str->data == target) t = str;
            
            if(str->left){
                q.push(str->left);
                m[str->left] = str;
            }
            if(str->right){
                q.push(str->right);
                m[str->right] = str;
            }
        }
        
        // for(auto &i : m) cout<<i.first->data<<" "<<i.second->data<<endl;
        // for(auto i : vis) cout<<i.first->data<<" "<<i.second<<endl;
        
        q.push(t);
        q.push(NULL);
        int ans = 0;
        
        while(!q.empty()){
            Node * str = q.front();
            q.pop();
            
            if(str == NULL){
                ans++;
                if(!q.empty()) q.push(NULL);
                continue;
            }
            
            vis[str] = true;
            
            if(m[str] != NULL && vis[m[str]] == false){
                q.push(m[str]);
            }
            if(str->left && vis[str->left] == false) q.push(str->left);
            if(str->right && vis[str->right] == false) q.push(str->right);
            
        }
        
        return ans - 1;
        
    }
};