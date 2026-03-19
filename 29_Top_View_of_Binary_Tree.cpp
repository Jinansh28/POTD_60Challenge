#include<bits/stdc++.h>
using namespace std;


class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};


class Solution {
  public:
    void helper(Node *root, unordered_map<int,int> &m, unordered_map<int,int> &n, int idx, int height){
        if(root == NULL) return;
        if(m.find(idx) == m.end()){ 
            m[idx] = root->data;
            n[idx] = height;
        }
        if(n.find(idx) != n.end() && n[idx] > height){ 
            m[idx] = root->data;
            n[idx] = height;
        }
        
        helper(root->left, m, n, idx - 1, height + 1);
        helper(root->right, m, n, idx + 1, height + 1);
    }
    
    vector<int> topView(Node *root) {
        unordered_map<int,int> m, n;
        m[0] = root->data;
        n[0] = 0;
        helper(root, m, n, 0, 0);
        
        vector<pair<int,int>> ans;
        for(auto i : m){
            ans.push_back({i.first, i.second});
        }
        sort(ans.begin(), ans.end());
        
        vector<int> a;
        for(auto i : ans) a.push_back(i.second);
        
        return a;
    }
};