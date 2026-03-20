#include<bits/stdc++.h>
using namespace std;


class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};


class Solution {
  public:
    void range(Node *root, int idx, int &l, int &r){
        if(root == NULL) return;
        if(idx < l) l = idx;
        if(idx > r) r = idx;
        range(root->left, idx - 1, l, r);
        range(root->right, idx + 1, l, r);
    }
    
    vector<vector<int>> verticalOrder(Node *root) {
        // code here
        queue<pair<Node *, int>> q;
        int l = 0, r = 0;
        range(root, 0, l, r);
        vector<vector<int>> ans(r - l + 1);
        
        q.push({root, 0 - l});
        
        while (!q.empty()){
            Node * str = q.front().first;
            int idx = q.front().second;
            ans[idx].push_back(str->data);
            
            if(str->left) q.push({str->left, idx - 1});
            if(str->right) q.push({str->right, idx + 1});
            q.pop();
        }
        
        return ans;
    }
};