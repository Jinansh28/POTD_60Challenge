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
    void helper(Node *root, int &k, int a, unordered_map<int,int> &m, int &count){
        if(root == NULL) return;
        a += root->data;
        if(m.find(a - k) != m.end()) count += m[a-k];
        m[a]++;
        
        helper(root->left, k, a, m, count);
        helper(root->right, k, a, m, count);
        m[a]--;
        
    }
    int countAllPaths(Node *root, int k) {
        int a = 0, count = 0;
        unordered_map<int,int> m;
        m[0] = 1;
        helper(root, k, a, m, count);
        return count;
    }
};